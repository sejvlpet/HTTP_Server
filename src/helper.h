#ifndef PA2_SERVER_HELPER_H
#define PA2_SERVER_HELPER_H
#include <string>

bool fileOk(const std::string &file);

// inspired on https://stackoverflow.com/questions/5719694/how-to-check-if-file-is-executable-in-c
bool isExecutable(const std::string &file);

// inspired on https://stackoverflow.com/questions/18100097/portable-way-to-check-if-directory-exists-windows-linux-c
bool dirOk(const std::string &dir);

bool isDir(const std::string &dir);

#endif //PA2_SERVER_HELPER_H
