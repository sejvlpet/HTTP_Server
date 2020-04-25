#ifndef PA2_SERVER_RESPONSELOG_H
#define PA2_SERVER_RESPONSELOG_H

#include <map>
#include "log.h"

class ResponseLog : public Log {
public:
    std::string ToString() const override {
        return std::move(Serialize());
    }

    void SetCustom(const std::map<std::string, std::string> &data) {
        // saves everything
        for(const auto &l : data) {
            _customMessage.append(CreateLine(
                    l.first + ": " + l.second
            ));
        }
    }

private:
    const char *HEADER{"Reponse Log"};

    std::string Serialize() const override {
        std::string response;
        response.append(CreateLine(HEADER));
        response.append(_customMessage);

        AddCommonPart(response);
        return response;
    }
};


#endif //PA2_SERVER_RESPONSELOG_H
