#ifndef PA2_SERVER_CONSOLELOGGER_H
#define PA2_SERVER_CONSOLELOGGER_H

#include "logger.h"

class ConsoleLogger : public Logger {
public:
    ConsoleLogger(const std::string &format) : Logger(format) {}

    // fixme why there has to be keyword class?
    void Log(const std::unique_ptr<class Log> &log) const override {
        std::cout << log->ToString(_format);
    }

    void Log(const class Log &log) const override {
        std::cout << log.ToString(_format);
    }

};


#endif //PA2_SERVER_CONSOLELOGGER_H
