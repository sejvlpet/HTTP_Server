#ifndef PA2_SERVER_SERVER_H
#define PA2_SERVER_SERVER_H
#include <netinet/in.h>
#include <string>
#include <vector>
#include <set>

class Server {
public:
    const static int PORT{8080};
    const static int SETUP_FAIL{1};
    const static int SETUP_OK{0};
    const static int LISTEN_FAIL{1};
    const static int LISTEN_OK{0};
    const static int IGNORE{-1};
    const static int SUCCESS{1};

    const static char *HELLO;
    const static char *WAIT;
    const static char *END;
    const static int BUFFER_READ_SIZE {30000};
    const static std::set<std::string> IGNORE_LIST;

    static int _workersCount;
    int Setup();
    int Listen();

private:
    sockaddr_in _address{};
    int _addrLen{0};
    int _serverFd{0};

    // fixme add some logic
    // will throw exceptions if something happens
    static void Response(int socket);
    static int ProcessMessage(int socket, char buffer[BUFFER_READ_SIZE]);
    static std::string GetReq(char buffer[BUFFER_READ_SIZE]);
};

#endif //PA2_SERVER_SERVER_H
