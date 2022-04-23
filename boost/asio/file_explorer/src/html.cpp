#include "html.h"

html::html(const std::string &requestMsg) {
    std::regex _regex{R"((\w+)\s(\S+)(.*))"};
    std::smatch results;

    std::string tmp_req(requestMsg);

    std::transform(tmp_req.begin(), tmp_req.end(), tmp_req.begin(),
                   [](char c) { return (c < 30) ? ' ' : c; });

    auto matched = std::regex_match(tmp_req, results, _regex);

    if (matched) {
#ifdef DEBUG
        std::cout << "match\n";
        std::cout << _regex.mark_count() << "\n";
        for (auto &i : results) {
            std::cout << i << "\n";
        }
#endif
        if (results.size() > 2) {
            this->_method = str2method(results[1]);
            this->requested_path = results[2];
        } else {
            this->_method = UNKNOW;
        }
    } else {
        this->_method = UNKNOW;
    }
}
const std::string html::fmt_file_dir(bool is_dir, const std::string &name) {
    std::stringstream ss;
    ss << " <a href=";
    if (is_dir) {
        ss << name << "> " << name << "</a>";
        return ss.str();
    } else {
        return name;
    }
}

std::stringstream &&html::fill_header4http(const std::string &content) {
    static std::stringstream ss;
    ss.str("");

    const std::string &header4http(
        //                "aa");
        "HTTP/1.1 200 OK\nContent-Type:text/html\nConnection: "
        "close\nContent-Length:");
    const std::string &endOfHeader("\n\n");
    auto ss_size = std::to_string(content.length() + endOfHeader.length() +
                                  header4http.length());
    auto ss_s = ss_size.length() + stoi(ss_size) + 1;

    ss << header4http << ss_s << endOfHeader << content;
    return std::move(ss);
}

html::METHOD html::get_requested_method() { return this->_method; }
const std::string &html::get_requested_path() { return this->requested_path; }

html::METHOD html::str2method(const std::string &str) {
    static std::map<std::string, METHOD> mapping = {
        {"GET", GET}, {"POST", POST}, {"PUSH", PUSH}};
    return mapping[str];
}
