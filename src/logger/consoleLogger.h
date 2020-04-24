#ifndef PA2_SERVER_CONSOLELOGGER_H
#define PA2_SERVER_CONSOLELOGGER_H

#include "logger.h"

class ConsoleLogger : public Logger {
public:
    // fixme why there has to be keyword class?
    void Log(const std::unique_ptr<class Log> &log) const override {
        std::cout << log->ToString();
    }

    ConsoleLogger *Clone() override {
        return new ConsoleLogger(*this);
    }
};


#endif //PA2_SERVER_CONSOLELOGGER_H
