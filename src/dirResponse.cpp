#include "dirResponse.h"

DirResponse::DirResponse(std::string root) : _root(std::move(root)) {

    DIR *dirp = opendir(_root.c_str());
    struct dirent *dp;
    while ((dp = readdir(dirp)) != nullptr) {
        _content.emplace_back(dp->d_name);
    }
    closedir(dirp);
}

void DirResponse::WriteOut(int socket) {
    std::string response = HTML_HEADER, subPath = _root.substr(_root.find_last_of('/') + 1);

    std::string add;
    if(_root.empty() || _root[_root.size() - 1] != '/')
        add = subPath + "/";

    for (const std::string &item : _content) {
        response.append("<a href=\"" + add  + item + "\">" + item + "<a\"><br />\n");
    }
    response.append(HTML_FOOTER);

    std::string realResponse = HEADER + std::to_string(response.size());
    realResponse.append("\n\n");
    realResponse.append(response);

    write(socket, realResponse.c_str(), realResponse.size());
    CreateLog();
}

void DirResponse::CreateLog() {
    std::map<std::string, std::string> res;
    res["status"] = "200";
    res["returned dir"] = _root;

    _log.SetCustom(res);

}
