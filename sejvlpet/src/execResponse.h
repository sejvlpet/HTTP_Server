#ifndef PA2_SERVER_EXECRESPONSE_H
#define PA2_SERVER_EXECRESPONSE_H


#include <utility>
#include <fstream>
#include <cstring>
#include <unistd.h>
#include "response.h"

class ExecResponse : public Response {
public:
    ExecResponse(std::string root, std::string target) : _root(std::move(root)), _target(std::move(target)) {}

    void WriteOut(int socket) override {
        std::string response, tmp;
        char buffer[128];
        FILE *pipe = popen((_root + _target).c_str(), "r");

        if (!pipe) {
            // todo somehow handle
        }

        // read content of given file
        while (!feof(pipe)) {
            if (fgets(buffer, 128, pipe) != nullptr) response += buffer;
        }


        std::string realResponse = HEADER + std::to_string(response.size());
        realResponse.append("\n\n");
        realResponse.append(response);

        write(socket, realResponse.c_str(), realResponse.size());

        pclose(pipe);
        CreateLog();
    };


private:
    std::string _root;
    std::string _target;
    const constexpr static char *HEADER{"HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: "};


    void CreateLog() override {
        std::map<std::string, std::string> res;
        res["returned testcase"] = _target;

        _log.SetCustom(res);
    }
};

#endif //PA2_SERVER_EXECRESPONSE_H
