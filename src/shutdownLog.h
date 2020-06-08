#ifndef PA2_SERVER_SHUTDOWNLOG_H
#define PA2_SERVER_SHUTDOWNLOG_H

#include "log.h"

class ShutDownLog : public Log {
public:
    ShutDownLog(bool final) : _final(final) {}

    std::string ToString(const std::string &format) const override {
        return Serialize(format);
    }


private:
    const char *HEADER_NOT_FINAL{"Shutdown called Log"};
    const char *HEADER_FINAL{"Shutdown final Log"};
    bool _final{false};

    std::string Serialize(const std::string &format) const override {
        std::string response = format;

        FindAndReplace(response,HEADER_NAME, _final ? HEADER_FINAL : HEADER_NOT_FINAL);
        FindAndReplace(response,CUSTOM_NAME, _customMessage);

        AddCommonPart(response);
        return response;
    }

};

#endif //PA2_SERVER_SHUTDOWNLOG_H
