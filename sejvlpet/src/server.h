#ifndef PA2_SERVER_SERVER_H
#define PA2_SERVER_SERVER_H

#include <netinet/in.h>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <mutex>
#include "logger.h"



class Server {
public:
    enum SETUP_STATUS {
        OK, FAIL, DEFAULT
    }; //<! possible states after setup
    SETUP_STATUS _setupStatus{DEFAULT}; //<!default setup status
    const static int SETUP_FAIL{1}; //<! code for setup fail

    /**
     * default const setups things needed from the very begging
     */
    Server();

    /**
     * simply reads options from config file
     * @param configFileName filer with config
     */
    void ReadOptions(const std::string &configFileName);

    /**
     * from options saved in members setups server
     */
    void Setup();

    /**
     * listen on configured port, if setup failed returns proper constant
     * @return result of listening
     */
    int Listen();

    /**
     * Logs and sets shutdown indicating member to true
     */
    void ShutDown();

    /**
     * @param reqUrl Url to be tested
     * @return true if given reqUrl should invoke shutdown
     */
    bool ShutDownCalled(const std::string &reqUrl) const;

    /**
     * Incremets worker count, thread sage
     * @return returns new count of workers
     */
    int IncWorkers();

    /**
     * Decrements count of worker, thread safe
     * @return new count of workers
     */
    int DecWorkers();

    /**
     * logs message taken as parameter
     * @param log Log to be logged
     */
    void Log(const class Log &log) const;

    /**
     * @return refernce to root directory
     */
    const std::string &GetRoot() const;

private:
    const char DELIMETER = ':'; //<! delimiter in cofig file
    const char COMMENT = ';'; //<! comment in cofig file
    // constants and enums
    enum LOG_LOCATION {
        FILE, CONSOLE
    }; //<! tells where do we want to log

    const static int LISTEN_SUCCESS{0}; //<! value to be return from listen if succeeds
    const static int LISTEN_FAIL{1}; //<! to be return if fails, generally if server's not setuped well before listening

    std::map<std::string, std::string>  _options{{
                                                        {"port", "8080"},
                                                        {"logLocation", "CONSOLE"},
                                                        {"root", "examples/"},
                                                        {"logFile", "default"}, // if log to file is set and file empty => error
                                                        {"shutdownUrl", "E5gySqfwoPjevP3RYP5o"},
                                                        {"userDefinedShutdownUrl", "E5gySqfwoPjevP3RYP5o"},
                                                        {"address", "0.0.0.0"},
                                                        {"logFormat","$HEADER$$NEWLINE$Time: $TIME$$NEWLINE$$CUSTOM$$NEWLINE$$SEPERATOR$"},
                                                        {"maxThreads", "10"},
                                                        {"maxQueue", "100"}
                                                }}; //<! options for configurtion with their default values

    std::map<const std::string, const LOG_LOCATION> _locations{{
                                                           {"CONSOLE", CONSOLE},
                                                           {"FILE", FILE}
                                                   }}; //<! translator from Enum to string


    // members with default values
    bool _shutDown{false}; //<! sets to true if serer's about to shutDown
    sockaddr_in _address{}; //<! address of socket
    int _addrLen{0}; //<! length of address
    int _serverFd{0}; //<! server fd
    std::unique_ptr<Logger> _logger; //<! object handling logginf
    mutable std::mutex _serverMutex; //<! mutex if thread safety is needed
    int _workersCount{0}; //<! recent count of request being processed or in queue


    /**
     * checks validity of options and sets them to our server options
     * @param options options to be setupted
     */
    void SetupOptions(const std::map<std::string, std::string> &options);

    /**
     * logs Error and sets status
     * @param message message to be logged
     */
    void Error(const std::string &message);

};

#endif //PA2_SERVER_SERVER_H