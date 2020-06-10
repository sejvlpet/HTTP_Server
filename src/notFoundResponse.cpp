#include "notFoundResponse.h"

void NotFoundResponse::WriteOut(int socket) {
    write(socket, NOT_FOUND, strlen(NOT_FOUND));
    CreateLog();
}

void NotFoundResponse::CreateLog() {
    std::map<std::string, std::string> res;
    res["status"] = "404";

    _log.SetCustom(res);
}
