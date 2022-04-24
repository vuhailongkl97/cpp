#ifndef FILES_H_
#define FILES_H_
#include "html.h"
#include <experimental/filesystem>
#include <iostream>
#include <memory>
#include <string>

namespace fs = std::experimental::filesystem;

class Files {
  public:
    Files(Files &&o) = delete;
    explicit Files(const std::string &fs);
    auto get_name() const -> auto;
    auto is_directory() const -> bool;
    friend auto operator<<(std::ostream &os, const Files &f) -> std::ostream &;
    Files(const Files &o);
    static auto read_path(fs::path &&path) -> std::vector<Files>;

  private:
    std::shared_ptr<fs::path> _fs;
};

#endif // FILES_H_
