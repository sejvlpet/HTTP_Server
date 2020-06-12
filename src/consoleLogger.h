#ifndef PA2_SERVER_CONSOLELOGGER_H
#define PA2_SERVER_CONSOLELOGGER_H

#include <mutex>
#include "logger.h"

class ConsoleLogger : public Logger {
public:
    ConsoleLogger(const std::string &format);

    void Log(const class Log &log) const override;


private:
    void WriteOut(const std::string &msg) const override;
    mutable std::mutex _consMutex;

};


#endif //PA2_SERVER_CONSOLELOGGER_H
