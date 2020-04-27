#include "src/logic/server.h"

int main(int argc, char const *argv[]) {
    // todo implement config file reading
    Server server;
    if (argc > 1)
        server.ReadOptions(argv[1]);
    server.Setup();
    if (server._setupStatus == Server::SETUP_STATUS::FAIL) {
        return Server::SETUP_FAIL;
    }
    return server.Listen();
}
