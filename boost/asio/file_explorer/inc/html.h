#ifndef HTML_H_
#define HTML_H_
#include <algorithm>
#include <regex>
#include <string>

class html {

  public:
    enum METHOD { GET = 1, POST = 2, PUSH = 3, UNKNOW };

    html() = delete;
    html(const std::string &requestMsg);

    METHOD get_requested_method();
    const std::string &get_requested_path();
    static const std::string fmt_file_dir(bool is_dir, const std::string &name);
    static std::stringstream &&fill_header4http(const std::string &content);

    static METHOD str2method(const std::string &str);

  private:
    METHOD _method;
    std::string requested_path;
    std::string client_host_addr;
};

#endif // HTML_H_
