#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdio.h>
#include "client.h"
#include "iconv.hpp"

const string utf8_to_iso (const char * utf8_in) {
  string result ("chybka");
  iconvpp::converter conv("ISO-8859-2", // output encoding
                          "UTF-8");     // input encoding
  conv.convert(string(utf8_in), result);
  return result;
}
#ifdef DEBUG
#define debug printf
#else
static inline void debug (...) {};
#endif

static constexpr int TIMEOUT = 50000;
// konverzní utilita
Connection::~Connection() {
  delete [] rx_buff;
  if (fd > 0) close (fd);
}
bool Connection::connect(const char * name, const int port) {
  struct sockaddr_in serv_addr;
  if ((fd = ::socket(AF_INET, SOCK_STREAM, 0)) < 0) {
      fprintf(stderr, "socket creation error\n");
      return false;
  }
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(port);
  // Convert IPv4 and IPv6 addresses from text to binary form
  if (::inet_pton(AF_INET, name, &serv_addr.sin_addr) <= 0) {
      fprintf(stderr, "invalid address\n");
      return false;
  }
  if (::connect(fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
      fprintf(stderr, "connection failed\n");
      return false;
  }
  struct timeval timeout;
  timeout.tv_sec  = 0;
  timeout.tv_usec = TIMEOUT;
  if (::setsockopt (fd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof timeout) < 0) {
      fprintf (stderr, "setsockopt timeout failed\n");
      return false;
  }
  return set_handle();
}
bool Connection::set_handle() {
  usleep (TIMEOUT);
  const int n = ::read(fd, rx_buff, RXBUFLEN);
  if (n < 0) return false;
  string res (rx_buff, n);
  // debug("res:\"%s\"\n", res.c_str());
  const size_t proto = res.find ("TTSCP spoken here");
  if (proto == string::npos) {
    fprintf(stderr, "invalid protocol\n");
    return false;
  }
  const string hs ("handle: ");
  size_t h = res.find (hs);
  if (h == string::npos) {
    fprintf(stderr, "invalid handle\n");
    return false;
  }
  h += hs.size();
  handle = res.substr (h, 15);
  debug("%s:handle=\"%s\"\n", id, handle.c_str());
  return true;
}
bool Connection::send(const string & s, const bool ack) {
  debug("%s:send=%s", id, s.c_str());
  const int n = ::write(fd, s.c_str(), s.size());
  if (n < 0) return false;
  if (!ack)  return true;
  usleep (TIMEOUT);
  recv(nullptr);
  if (!recvd) return false;
  return true;
}
void Connection::recv(OutputInterface * i) {
  while (true) {
    const int r = ::read(fd, rx_buff, RXBUFLEN);
    if (r <= 0) break;
    recvd = r;
    rx_buff [r] = '\0';
    if (i) i->send (rx_buff, recvd);
    debug("%s:recv:%d\n", id, recvd);
    //debug("%s:response=%s", id, rx_buff);
  }
}

void Connection::fini() {
  if (fd > 0) { ::close(fd); fd = -1; }
}
bool Connection::end(OutputInterface * i) {
  const string s (rx_buff, recvd);
  const size_t r = s.find ("200 output OK");
  if (r == string::npos) return false;
  if (i) i->fini();
  return true;
}

/* Ukazuje se, že není nutné udržovat TCP spojení po celou
 * dobu života klienta. Ostatně doba vyslovení věty je vždy
 * o hodně větší než doba navázání spojení.  */

bool TTSCP_Client::say(const string & s) {
  if (!init()) return false;
  const size_t len = s.size();
  const int blen = 256;
  char aplbuf [blen];
  const int r = snprintf(aplbuf, blen, "appl %zd\r\n", len);
  string c (aplbuf, r);
  if (!data.send(s, false)) return false;
  if (!ctrl.send(c)) return false;
  for (int n=0; n<1000; n++) {
    usleep (TIMEOUT << 2);
    ctrl.recv (nullptr);
    data.recv (iface);
    if (ctrl.end(iface)) break;
  }
  fini();
  return true;
}
bool TTSCP_Client::init() {
  if (! data.connect (server_name, server_port)) return false;
  if (! ctrl.connect (server_name, server_port)) return false;
  // initialize
  string s ("data ");
  s += ctrl.get_handle() + "\r\n";
  if (!data.send (s)) return false;
  // set stream
  s  = "strm $";  // tohle není přesně popsáno (zpětné inženýrství)
  s +=  data.get_handle() + ":raw:rules:diphs:synth:";
  if (iface == nullptr) s += "#localsound\r\n";
  else      { s += "$"; s += data.get_handle() + "\r\n"; }
  if (!ctrl.send (s)) return false;
  return true;
}
void TTSCP_Client::fini() {
  data.fini();
  ctrl.fini();
}
