#ifndef PA2_SERVER_ERRORLOG_H
#define PA2_SERVER_ERRORLOG_H

#include "log.h"

class ErrorLog : public Log {
public:

    std::string ToString() const override {
        return std::move(Serialize());
    }


private:
    const char *HEADER{"Error"};

    std::string Serialize() const override {
        std::string response;
        response.append(CreateLine(HEADER));
        response.append((CreateLine(_customMessage)));

        AddCommonPart(response);
        return response;
    }
};


#endif //PA2_SERVER_ERRORLOG_H
