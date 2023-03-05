#ifndef CLIENT_H
#define CLIENT_H
#include <string>
#include <unistd.h>

using namespace std;
static constexpr int RXBUFLEN = 0x1000;
extern const string utf8_to_iso (const char * utf8_in);
// forward declaration
class TTSCP_Client;
class WavOutput;
class AlsaOutput;
// Interface pro zpracování audio dat
class OutputInterface {
  friend class WavOutput;
  friend class AlsaOutput;
  TTSCP_Client * parent;
  public:
    explicit OutputInterface(TTSCP_Client * p) noexcept : parent(p) {};
    virtual ~OutputInterface() {};
    virtual int  send (const void * data, const int len) = 0;
    virtual void fini () = 0;
};
// TCP spojení
class Connection {
  const char * id;
  string handle;
  int    fd, recvd;
  char * rx_buff;
  public:
    explicit Connection (const char * _id) noexcept : id(_id), handle(), fd(-1), recvd(0) {
      rx_buff = new char [RXBUFLEN];
    }
    ~Connection ();
    bool connect (const char * name, const int port);
    const string & get_handle () const { return handle; }
    bool send (const string & s, const bool ack = true);
    void recv (OutputInterface * i);
    bool end  (OutputInterface * i);
    void fini ();
  protected:
    bool set_handle ();
};
// Vlastní klient
class TTSCP_Client {
  OutputInterface * iface;
  const char * server_name;
  const int    server_port;
  Connection   data;
  Connection   ctrl;
  public:
    explicit TTSCP_Client (const char * name, const int port = 8778) noexcept :
      iface(nullptr), server_name(name), server_port(port), data("data"), ctrl("ctrl") {}
    ~TTSCP_Client () {}
    void attach (OutputInterface * i) { iface = i; }
    bool say (const string & s);
  protected:
    bool init ();
    void fini ();
};

#endif // CLIENT_H
