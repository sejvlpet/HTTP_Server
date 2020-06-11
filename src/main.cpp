#include <iostream>
#include "server.h"

int main(int argc, char const *argv[]) {
    // NOTE - there was a note about bug - if runned twice at once, program was segfaulting
    // when I came back to solve, I couldn't simulate this situation again, no idea why
    // if anyone won't simulate it again, I'll consider it solved
    Server server;
    if (argc > 1)
        server.ReadOptions(argv[1]);
    server.Setup();
    if (server._setupStatus == Server::SETUP_STATUS::FAIL) {
        return Server::SETUP_FAIL;
    }
    return server.Listen();
}
