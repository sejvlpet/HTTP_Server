#ifndef PA2_SERVER_SERVER_H
#define PA2_SERVER_SERVER_H

#include <netinet/in.h>
#include <string>
#include <vector>
#include <set>

class Server {
public:
    enum SETUP_STATUS {
        OK, FAIL, DEFAULT
    };
    SETUP_STATUS _setupStatus{DEFAULT};

    Server();

    Server(const std::string & configFileName);
    // todo - implement config reading from file - notes:
    // check if socket port is within allowed ranges
    // check if logFile has proper rights
    // check root directory (not sure what to check yet, but surely there'll be something to check)
    // sets enum setup


    void Setup(const std::string &configFileName); // setups server from configFile, same todos as ctor with file as parametr
    int Listen(); // listen on configured port, if setup failed returns proper constant

    void ShutDown() {
        _shutDown = true;
    }

    bool ShutDownCalled(const std::string &reqUrl) {
        return _shutdownUrl == reqUrl;
    }

private:
    // new implementation
    // constants and enums
    enum LOG_LOCATION { // tells where do we want to log
        FILE, CONSOLE
    };
    enum LOG_LEVEL { // tells what should be logged
        INFO, DEBUG, WARN, ERROR
    };

    const static int LISTEN_SUCCESS{0}; // value to be return from listen if succeeds
    const static int LISTEN_FAIL{1}; // to be return if fails, generally if server's not setuped well before listening
    // simple hello world response
    const constexpr static char *HELLO{"HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: 12\n\nHello world!"};
    static int _workersCount; // recent count of request being processed
    const std::vector<std::string> TEST_CASES; // vector of unit test scenario names
    const std::vector<std::string> STATIC_EXTENSIONS; // extensions to be treated as static
    const std::vector<std::string> DYNAMIC_EXTENSIONS; // extensions to be treated as dynamic


    // options from configuration
    // todo - implement configuration reading
    int _port{8080};
    std::string _root; // name of root directory
    LOG_LOCATION _logger{CONSOLE};
    LOG_LEVEL _logLevel{INFO};
    std::string _logFile; // default empty as by default logs to console

    // members with default values
    bool _shutDown{false}; // sets to true if serer's about to shutDown
    sockaddr_in _address{};
    int _addrLen{0};
    int _serverFd{0};
    std::string _shutdownUrl = "shutdown"; // specifies name of shutdown url

    // methods
    void Setup(); // from options saved in members setups server











public:
    // to be removed or replaced
    const static int SETUP_FAIL{1}; // won't be used
    const static int SETUP_OK{0}; // won't be used
//    const static int LISTEN_FAIL{1};
    const static int LISTEN_OK{0}; // renamed
    const static int IGNORE{-1}; // wtf?
    const static int SUCCESS{1}; // wtf?
    const static int PORT{8080}; // to be removed



    const static char *WAIT;
    const static char *END;
    const static int BUFFER_READ_SIZE{30000};
    const static std::set<std::string> IGNORE_LIST;




private:

    // fixme add some logic
    // will throw exceptions if something happens
    static void Response(int socket);

    static int ProcessMessage(int socket, char buffer[BUFFER_READ_SIZE]);

    static std::string GetReq(char buffer[BUFFER_READ_SIZE]);
};

#endif //PA2_SERVER_SERVER_H
