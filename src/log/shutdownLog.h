#ifndef PA2_SERVER_SHUTDOWNLOG_H
#define PA2_SERVER_SHUTDOWNLOG_H

#include "log.h"

class ShutDownLog : public Log {
public:
    ShutDownLog(bool final) : _final(final) {}

    std::string ToString() const override {
        return std::move(Serialize());
    }


private:
    const char *HEADER_NOT_FINAL{"Shutdown called Log"};
    const char *HEADER_FINAL{"Shutdown final Log"};
    bool _final{false};

    std::string Serialize() const override {
        std::string response;
        response.append(CreateLine(_final ? HEADER_FINAL : HEADER_NOT_FINAL));
        response.append((CreateLine(_customMessage)));

        AddCommonPart(response);
        return response;
    }
};

#endif //PA2_SERVER_SHUTDOWNLOG_H
