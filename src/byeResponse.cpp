#include <cstring>
#include <unistd.h>
#include "byeResponse.h"

void ByeResponse::WriteOut(int socket) {
    write(socket, BYE, strlen(BYE));
    CreateLog();
}

void ByeResponse::CreateLog() {
    std::map<std::string, std::string> res;
    res["status"] = "200";

    _log.SetCustom(res);
}
