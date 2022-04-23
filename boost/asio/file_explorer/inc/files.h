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
    Files(const std::string &fs);
    Files(Files &&o) = delete;
    const auto get_name() const;
    bool is_directory() const;
    friend std::ostream &operator<<(std::ostream &os, const Files &f);
    Files(const Files &o);
    static std::vector<Files> read_path(fs::path &&path);

  private:
    std::shared_ptr<fs::path> _fs;
};

#endif // FILES_H_
