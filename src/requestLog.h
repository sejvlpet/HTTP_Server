#ifndef PA2_SERVER_REQUESTLOG_H
#define PA2_SERVER_REQUESTLOG_H
#include <map>
#include <vector>
#include "log.h"

class RequestLog : public Log {
public:
    std::string ToString(const std::string &format) const override;

    void SetCustom(std::map<std::string, std::string> &data);

private:
    std::vector<std::string> _toLog{"target", "Host", "User-Agent", "id"};
    const char *HEADER{"Request Log"};

    std::string Serialize(const std::string &format) const override;
};


#endif //PA2_SERVER_REQUESTLOG_H
