#include "response.h"
#include <unistd.h>
#include <cstring>


Log &Response::GetLog() {
    return _log;
}

void Response::WriteOut(int socket) {
    write(socket, HELLO, strlen(HELLO));
    CreateLog();
}

void Response::CreateLog() {
    std::map<std::string, std::string> res;
    res["status"] = "500";
    res["returned"] = "default response";

    _log.SetCustom(res);
}
