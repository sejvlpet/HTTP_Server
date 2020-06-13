#ifndef PA2_SERVER_CONSOLELOGGER_H
#define PA2_SERVER_CONSOLELOGGER_H

#include <mutex>
#include "logger.h"

/**
 * Handles logging on std::cout, thread safe
 */
class ConsoleLogger : public Logger {
public:
    /**
     * saves format
     * @param format Format option
     */
    ConsoleLogger(const std::string &format);

    /**
     * @copydoc Logger::Log()
     */
    void Log(const class Log &log) const override;


private:
    mutable std::mutex _consMutex;

    /**
     *@copydoc Logger::WriteOut()
     */
    void WriteOut(const std::string &msg) const override;

};


#endif //PA2_SERVER_CONSOLELOGGER_H
