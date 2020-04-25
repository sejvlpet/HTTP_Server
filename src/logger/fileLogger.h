#ifndef PA2_SERVER_FILELOGGER_H
#define PA2_SERVER_FILELOGGER_H

#include "logger.h"

class FileLogger : public Logger {
public:
    // fixme why there has to be keyword class?
    void Log(const std::unique_ptr<class Log> &log) const override {
        std::cout << log->ToString();
    }
    void Log(const class Log &log) const override {
        std::cout << log.ToString();
    }
    void Log(const class Log *log) const override {
        std::cout << log->ToString();
    }
};


#endif //PA2_SERVER_FILELOGGER_H
