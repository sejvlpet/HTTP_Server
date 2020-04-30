#ifndef PA2_SERVER_FILERESPONSE_H
#define PA2_SERVER_FILERESPONSE_H

#include <utility>
#include <fstream>
#include <cstring>
#include <unistd.h>
#include "response.h"

class FileResponse : public Response {
public:
    FileResponse(std::string root, std::string target, bool isHtml = true) :
            _root(std::move(root)), _target(std::move(target)), _isHtml(isHtml) {}

    void WriteOut(int socket) override {
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
    };


private:
    std::string _root;
    std::string _target;
    const constexpr static char *HTML_HEADER{"HTTP/1.1 200 OK\nContent-Type: text/html\nContent-Length: "};
    const constexpr static char *TEXT_HEADER{"HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: "};
    bool _isHtml{true};


    void CreateLog() override {
        std::map<std::string, std::string> res;
        res["status"] = "200";
        res["returned file"] = _target;

        _log.SetCustom(res);
    }
};


#endif //PA2_SERVER_FILERESPONSE_H
