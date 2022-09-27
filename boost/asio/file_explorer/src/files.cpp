#include "files.h"

Files::Files(const std::string &fs) : _fs{new fs::path(fs)} {}
auto Files::get_name() const -> auto{ return _fs->c_str(); }
auto Files::is_directory() const -> bool { return fs::is_directory(*_fs); }
auto operator<<(std::ostream &os, const Files &f) -> std::ostream & {
    os << html::fmt_file_dir(f.is_directory(), f.get_name());
#ifdef DEBUG
    os << f.is_directory() << " " << f.get_name();
#endif
    return os;
}
Files::Files(const Files &o) { this->_fs = o._fs; }
auto Files::read_path(fs::path &&path) -> std::vector<Files> {
    std::vector<Files> vf;
    try {
        for (const auto &entry : fs::directory_iterator(path)) {
            Files f(entry.path().c_str());
            vf.push_back(f);
        }
    } catch (fs::filesystem_error const &ex) {
        std::cout << "what():  " << ex.what() << '\n'
                  << "path1(): " << ex.path1() << '\n'
                  << "path2(): " << ex.path2() << '\n'
                  << "code().value():    " << ex.code().value() << '\n'
                  << "code().message():  " << ex.code().message() << '\n'
                  << "code().category(): " << ex.code().category().name()
                  << '\n';
    }
    return vf;
}
