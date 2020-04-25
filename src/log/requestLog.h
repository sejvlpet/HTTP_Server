#ifndef PA2_SERVER_REQUESTLOG_H
#define PA2_SERVER_REQUESTLOG_H

#include <map>
#include <vector>
#include "log.h"

class RequestLog : public Log {
public:
    std::string ToString() const override {
        return std::move(Serialize());
    }

    void SetCustom(std::map<std::string, std::string> &data) {
        for(const std::string &l : _toLog) {
            _customMessage.append(CreateLine(
                    l + ": " + data[l]
            ));
        }
    }

    void SetInvalid() {
        _customMessage.append(CreateLine("This request was invalid"));
    }

private:
    std::vector<std::string> _toLog {"target", "Host", "User-Agent", "Accept"};
    const char *HEADER{"Request Log"};

    std::string Serialize() const override {
        std::string response;
        response.append(CreateLine(HEADER));
        response.append((_customMessage));

        AddCommonPart(response);
        return response;
    }
};



#endif //PA2_SERVER_REQUESTLOG_H
