#ifndef PA2_SERVER_SERVER_H
#define PA2_SERVER_SERVER_H

#include <netinet/in.h>
#include <string>
#include <vector>
#include <set>
#include <utility>
#include <memory>
#include <map>
#include "logger.h"
#include "consoleLogger.h"
#include "helper.h"


class Server {
public:
    enum SETUP_STATUS {
        OK, FAIL, DEFAULT
    };
    SETUP_STATUS _setupStatus{DEFAULT};
    const static int SETUP_FAIL{1};
    const static std::set<std::string> IGNORE_LIST;

    // default const setups things needed from the very begging - at least logger
    Server();
    // simply reads options from config file
    void ReadOptions(const std::string &configFileName);
    // methods
    void Setup(); // from options saved in members setups server

    int Listen(); // listen on configured port, if setup failed returns proper constant

    void ShutDown();

    bool ShutDownCalled(const std::string &reqUrl) const;

    int IncWorkers();

    int DecWorkers();

    // logs message taken as parameter
    // passing value by reference seems nicer to me, but as server runs in more threads, it is not always possible
    void Log(const class Log &log) const;

    const std::string &GetRoot() const;

private:
    const char DELIMETER = ':';
    const char COMMENT = ';';
    // constants and enums
    enum LOG_LOCATION { // tells where do we want to log
        FILE, CONSOLE
    };

    const static int LISTEN_SUCCESS{0}; // value to be return from listen if succeeds
    const static int LISTEN_FAIL{1}; // to be return if fails, generally if server's not setuped well before listening
    const std::vector<std::string> TEST_CASES; // vector of unit test scenario names
    const std::vector<std::string> STATIC_EXTENSIONS; // extensions to be treated as static
    const std::vector<std::string> DYNAMIC_EXTENSIONS; // extensions to be treated as dynamic

    int _workersCount{0}; // recent count of request being processed or in queue


    // options for configurtion with ther default values
    // todo add test options
    std::map<std::string, std::string> _options{{
                                                        {"port", "8080"},
                                                        {"logLocation", "CONSOLE"}, // todo how to parse string to enum?
                                                        {"root", "router/"}, // todo at least this option has to be passed
                                                        {"logFile", "default"}, // if log to file is set and file empty => error
                                                        {"shutdownUrl", "E5gySqfwoPjevP3RYP5o"},
                                                        {"userDefinedShutdownUrl", "E5gySqfwoPjevP3RYP5o"},
                                                        {"address", "0.0.0.0"},
                                                        {"logFormat","$HEADER$$NEWLINE$Time: $TIME$$NEWLINE$$CUSTOM$$NEWLINE$$SEPERATOR$"},
                                                        {"maxThreads", "4"},
                                                        {"maxQueue", "100"}

                                                }};
    std::map<const std::string, const LOG_LOCATION> _locations{{
                                                           {"CONSOLE", CONSOLE},
                                                           {"FILE", FILE}
                                                   }};


    // members with default values
    bool _shutDown{false}; // sets to true if serer's about to shutDown
    sockaddr_in _address{};
    int _addrLen{0};
    int _serverFd{0};
    std::unique_ptr<Logger> _logger;

    // checks validity of options and sets them to our server options
    void SetupOptions(const std::map<std::string, std::string> &options);
    // logs Error and sets status
    void Error(const std::string &message);

};

#endif //PA2_SERVER_SERVER_H