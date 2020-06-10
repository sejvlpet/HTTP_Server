#ifndef PA2_SERVER_ERRORLOG_H
#define PA2_SERVER_ERRORLOG_H

#include "log.h"

class ErrorLog : public Log {
public:
    ErrorLog(const std::string &message, bool fatal = true);

    std::string ToString(const std::string &format) const override;


private:
    const char *ERROR_HEADER{"Error"};
    const char *WARNING_HEADER{"Warning"};
    bool _fatal{true};

    std::string Serialize(const std::string &format) const override;
};


#endif //PA2_SERVER_ERRORLOG_H
