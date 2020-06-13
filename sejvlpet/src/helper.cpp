#include "helper.h"
#include <fstream>
#include <sys/stat.h>
#include <dirent.h>
#include <iostream>
#include <fstream>
#include <iostream>
#include <filesystem>


bool fileOk(const std::string &file) {
    std::ifstream ifile;
    ifile.open(file);
    return ifile && true;
}

bool isExecutable(const std::string &file) {
    // inspired on https://stackoverflow.com/questions/5719694/how-to-check-if-file-is-executable-in-c
    struct stat st{};

    if (stat(file.c_str(), &st) < 0)
        return false;
    return (st.st_mode & S_IEXEC) != 0;
}

bool dirOk(const std::string &dir) {
    try {
        const auto &p = std::filesystem::directory_iterator(dir);
    } catch (...) {
        return false;
    }

    return true;
}

bool isDir(const std::string &dir) {
    // inspired on https://stackoverflow.com/questions/18100097/portable-way-to-check-if-directory-exists-windows-linux-c
    struct stat info{};

    if (stat(dir.c_str(), &info) != 0)
        return false;
    else return (info.st_mode & S_IFDIR) != 0;
}
