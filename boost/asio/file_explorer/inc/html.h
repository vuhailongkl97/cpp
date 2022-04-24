#ifndef HTML_H_
#define HTML_H_
#include <algorithm>
#include <regex>
#include <string>

const int READABLE_CHAR_LIMIT = 30;
class html {

  public:
    enum METHOD { GET = 1, POST = 2, PUSH = 3, UNKNOW };

    html() = delete;
    explicit html(const std::string &requestMsg);

    auto get_requested_method() -> METHOD;
    auto get_requested_path() -> const std::string &;
    static auto fmt_file_dir(bool is_dir, const std::string &name)
        -> std::string;
    static auto fill_header4http(const std::string &content)
        -> std::stringstream &&;

    static auto str2method(const std::string &str) -> METHOD;

  private:
    METHOD _method;
    std::string requested_path;
    std::string client_host_addr;
};

#endif // HTML_H_
