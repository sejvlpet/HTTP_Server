#include <iostream>
#include "server.h"

/**
 * Creates server, if file with options is on input -> saves options, then setups options. If everythings
 * OK, server can start listenig
 * @param argc
 * @param argv
 * @return 0 for success, 1 for fail
 */
int main(int argc, char const *argv[]) {

    Server server;
    if (argc > 1)
        server.ReadOptions(argv[1]);
    server.Setup();
    if (server.GetStatus() == Server::SETUP_STATUS::FAIL) {
        return Server::SETUP_FAIL;
    }
    return server.Listen();
}
