#include "server.h"

int main(int argc, char const *argv[]) {
    Server server;
    int s;
    if ((s = server.Setup()) != Server::SETUP_OK) {
        return s;
    }
    return server.Listen();
}
