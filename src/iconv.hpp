#ifndef __ICONV_HPP
#define __ICONV_HPP
#include <errno.h>
#include <iconv.h>
#include <string>
#include <vector>

namespace iconvpp {

class converter {
 public:
  converter(const std::string& out_encode,
            const std::string& in_encode,
            size_t buf_size = 0x1000)
      : iconv_ ((iconv_t) -1),
        buf_size_(buf_size)  {

    iconv_t conv = ::iconv_open(out_encode.c_str(), in_encode.c_str());
    if (conv == (iconv_t)-1) {
      fprintf(stderr, "iconv create err = %d\n", errno);
    }
    iconv_ = conv;
  }

  ~converter() {
    if ((long) iconv_ < 0) return;
    iconv_close(iconv_);
  }

  void convert(const std::string& input, std::string& output) const {
    if ((long) iconv_ < 0) return;
    // copy the string to a buffer as iconv function requires a non-const char
    // pointer.
    std::vector<char> in_buf(input.begin(), input.end());
    char * src_ptr  = &in_buf[0];
    size_t src_size = input.size();

    std::vector<char> buf(buf_size_);
    std::string dst;
    while (0 < src_size) {
      char * dst_ptr  = &buf[0];
      size_t dst_size = buf.size();
      size_t res = ::iconv(iconv_, &src_ptr, &src_size, &dst_ptr, &dst_size);
      if (res == (size_t)-1) {
        if (errno == E2BIG)  {
          // ignore this error
        } else  {
          // skip character
          fprintf(stderr, "icnv convert err = %d\n", errno);
          ++src_ptr;
          --src_size;
        }
      }
      dst.append(&buf[0], buf.size() - dst_size);
    }
    dst.swap(output);
  }

 private:
  iconv_t iconv_;
  bool ignore_error_;
  const size_t buf_size_;
};

}  // namespace iconvpp
#endif //  __ICONV_HPP
