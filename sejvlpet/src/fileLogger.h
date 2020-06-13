#ifndef PA2_SERVER_FILELOGGER_H
#define PA2_SERVER_FILELOGGER_H
#include <mutex>
#include "logger.h"

/**
 * Handles logging to file given in configuration, thread safe
 */
class FileLogger : public Logger {
public:
    FileLogger(const std::string &format, std::string fileName);

    /**
     * @copydoc Logger::Log()
     */
    void Log(const class Log &log) const override;

private:
    std::string _fileName;
    mutable std::mutex _fileMutex;

    /**
     *@copydoc Logger::WriteOut()
     */
    void WriteOut(const std::string &msg) const override;
};


#endif //PA2_SERVER_FILELOGGER_H
