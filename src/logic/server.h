#ifndef PA2_SERVER_SERVER_H
#define PA2_SERVER_SERVER_H

#include <netinet/in.h>
#include <string>
#include <vector>
#include <set>
#include <utility>
#include <memory>
#include <map>
#include "../logger/logger.h"
#include "../logger/consoleLogger.h"


class Server {
public:
    enum SETUP_STATUS {
        OK, FAIL, DEFAULT
    };
    SETUP_STATUS _setupStatus{DEFAULT};
    const static int SETUP_FAIL{1};
    const static std::set<std::string> IGNORE_LIST;
    // simply reads options from config file
    void ReadOptions(const std::string &configFileName);
    // methods
    void Setup(); // from options saved in members setups server

    int Listen(); // listen on configured port, if setup failed returns proper constant

    void ShutDown();

    // fixme due to work with map, this cannot be const
    bool ShutDownCalled(const std::string &reqUrl) {
        return _options["shutdownUrl"] == reqUrl || _options["userDefinedShutdownUrl"] == reqUrl;
    }

    int IncWorkers() { // increments worker counts and returns it
        return ++_workersCount;
    }

    int DecWorkers() { // increments worker counts and returns it
        return --_workersCount;
    }

//     logs message taken as parameter
    void Log(const std::unique_ptr<Log> log) const {
        _logger->Log(log);
    }

    void Log(const class Log &log) const {
        _logger->Log(log);
    }

    const std::string &GetRoot() {
        return _options["root"];
    }

private:
    // new implementation
    // constants and enums
    enum LOG_LOCATION { // tells where do we want to log
        FILE, CONSOLE
    };
    enum LOG_LEVEL { // tells what should be logged
        INFO, WARN, ERROR
    };

    const static int LISTEN_SUCCESS{0}; // value to be return from listen if succeeds
    const static int LISTEN_FAIL{1}; // to be return if fails, generally if server's not setuped well before listening
    const std::vector<std::string> TEST_CASES; // vector of unit test scenario names
    const std::vector<std::string> STATIC_EXTENSIONS; // extensions to be treated as static
    const std::vector<std::string> DYNAMIC_EXTENSIONS; // extensions to be treated as dynamic

    int _workersCount{0}; // recent count of request being processed


    // options for configurtion with ther default values
    // todo add test options
    std::map<std::string, std::string> _options{{
                                                        {"port", "8080"},
                                                        {"logLocation", "CONSOLE"}, // todo how to parse string to enum?
                                                        {"root", "router/"}, // todo at least this option has to be passed
                                                        {"logLevel", "INFO"},
                                                        {"logFile", ""}, // if log to file is set and file empty => error
                                                        {"shutdownUrl", "E5gySqfwoPjevP3RYP5o"},
                                                        {"userDefinedShutdownUrl", "E5gySqfwoPjevP3RYP5o"},
                                                        {"maxPendingRequests", "20"}

                                                }};
    std::map<const std::string, const LOG_LOCATION> _locations{{
                                                           {"CONSOLE", CONSOLE},
                                                           {"FILE", FILE}
                                                   }};

    std::map<const std::string, const LOG_LEVEL> _levels{{
                                                     {"INFO", INFO},
                                                     {"WARN", WARN},
                                                     {"ERROR", ERROR}
                                             }};

    // members with default values
    bool _shutDown{false}; // sets to true if serer's about to shutDown
    sockaddr_in _address{};
    int _addrLen{0};
    int _serverFd{0};
    std::unique_ptr<Logger> _logger{std::make_unique<ConsoleLogger>()};

    // checks validity of options and sets them to our server options
    void SetupOptions(std::map<std::string, std::string> &options);
    // logs Error and sets status
    void Error(const std::string &message);

};

#endif //PA2_SERVER_SERVER_H