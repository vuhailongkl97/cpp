#include "files.h"

Files::Files(const std::string &fs) : _fs{new fs::path(fs)} {}
const auto Files::get_name() const { return _fs->c_str(); }
bool Files::is_directory() const { return fs::is_directory(*_fs); }
std::ostream &operator<<(std::ostream &os, const Files &f) {
    os << html::fmt_file_dir(f.is_directory(), f.get_name());
#ifdef DEBUG
    os << f.is_directory() << " " << f.get_name();
#endif
    return os;
}
Files::Files(const Files &o) { this->_fs = o._fs; }
std::vector<Files> Files::read_path(fs::path &&path) {
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
