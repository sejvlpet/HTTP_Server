#ifndef PA2_SERVER_SHUTDOWNLOG_H
#define PA2_SERVER_SHUTDOWNLOG_H

#include "log.h"

class ShutDownLog : public Log {
public:
    ShutDownLog(bool final);

    std::string ToString(const std::string &format) const override;


private:
    const char *HEADER_NOT_FINAL{"Shutdown called Log"};
    const char *HEADER_FINAL{"Shutdown final Log"};
    bool _final{false};

    std::string Serialize(const std::string &format) const override;

};

#endif //PA2_SERVER_SHUTDOWNLOG_H
