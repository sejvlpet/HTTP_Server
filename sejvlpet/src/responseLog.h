#ifndef PA2_SERVER_RESPONSELOG_H
#define PA2_SERVER_RESPONSELOG_H

#include <map>
#include "log.h"

class ResponseLog : public Log {
public:
    std::string ToString(const std::string &format) const override {
        return Serialize(format);
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

    std::string Serialize(const std::string &format) const override {
        std::string response;
        response.append(CreateLine(HEADER));
        response.append(_customMessage);

        // todo format logs
//        size_t index = response.find("$CUSTOM$");
//        if (index != std::string::npos) {
//            response.replace(index, 9, _customMessage);
//        }

        AddCommonPart(response);
        return response;
    }
};


#endif //PA2_SERVER_RESPONSELOG_H
