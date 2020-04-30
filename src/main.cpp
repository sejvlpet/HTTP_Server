#include "server.h"

int main(int argc, char const *argv[]) {
    // BUG - I've just found out, that if program is runned twice, the second one segfaults
    Server server;
    if (argc > 1)
        server.ReadOptions(argv[1]);
    server.Setup();
    if (server._setupStatus == Server::SETUP_STATUS::FAIL) {
        return Server::SETUP_FAIL;
    }
    return server.Listen();
}
