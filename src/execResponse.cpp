#include <unistd.h>
#include <c++/7/cstring>
#include "execResponse.h"

void ExecResponse::WriteOut(int socket) {
    std::string response, tmp;
    char buffer[128];
    FILE *pipe = popen((_root + _target).c_str(), "r");

    if (!pipe) {
        _res["failed to run testcase"] = _target;
        return;
    }

    // read content of given file
    while (!feof(pipe)) {
        if (fgets(buffer, 128, pipe) != nullptr)
            response += buffer;
    }

    std::string realResponse = HEADER;
    if(response.size() > 0)
        realResponse += std::to_string(response.size());
    else
        realResponse += std::to_string(strlen(NO_OUTPUT));
    realResponse.append("\n\n");
    realResponse.append(response.size() > 0 ? response : NO_OUTPUT);

    write(socket, realResponse.c_str(), realResponse.size());

    pclose(pipe);

    _res["returned testcase"] = _target;
    CreateLog();
}

void ExecResponse::CreateLog() {
    _log.SetCustom(_res);
}
