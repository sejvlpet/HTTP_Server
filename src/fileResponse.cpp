#include "fileResponse.h"
#include <fstream>
#include <unistd.h>

FileResponse::FileResponse(std::string root, std::string target, bool isHtml) :
        _root(std::move(root)), _target(std::move(target)), _isHtml(isHtml) {}

void FileResponse::WriteOut(int socket) {
    std::string response, tmp;
    std::ifstream file(_root + "/" + _target);

    // read content of given file
    while (std::getline(file, tmp)) {
        response.append(tmp);
    }

    file.close();

    std::string realResponse = (_isHtml ? HTML_HEADER : TEXT_HEADER) + std::to_string(response.size());
    realResponse.append("\n\n");
    realResponse.append(response);

    write(socket, realResponse.c_str(), realResponse.size());
    CreateLog();
}

void FileResponse::CreateLog() {
    std::map<std::string, std::string> res;
    res["status"] = "200";
    res["returned file"] = _target;

    _log.SetCustom(res);
}
