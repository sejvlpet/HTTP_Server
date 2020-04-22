#ifndef PA2_SERVER_SERVER_H
#define PA2_SERVER_SERVER_H
#include <netinet/in.h>
#include <string>
#include <vector>
#include <set>

class Server {
private:
    // new implementation
    // options
    const static int PORT{8080};
    enum class SETUP_STATUS {
        OK, FAIL, NO_SETUP
    };
    const static int LISTEN_SUCCESS{0}; // value to be return from listen if succeeds
    const static int LISTEN_FAIL{1}; // to be return if fails, generally if server's not setuped well before listening
    // simple hello world response
    const constexpr static char *HELLO{"HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: 12\n\nHello world! prdel"};


public:
    static int _workersCount; // recent count of request being processed



    // to be removed or replaced
    const static int SETUP_FAIL{1}; // won't be used
    const static int SETUP_OK{0}; // won't be used
//    const static int LISTEN_FAIL{1};
    const static int LISTEN_OK{0}; // renamed
    const static int IGNORE{-1}; // wtf?
    const static int SUCCESS{1}; // wtf?


    const static char *WAIT;
    const static char *END;
    const static int BUFFER_READ_SIZE {30000};
    const static std::set<std::string> IGNORE_LIST;


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
