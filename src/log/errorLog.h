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
        response.append(HEADER);
        response.push_back('\n');
        response.append(TimeToString());
        response.push_back('\n');
        response.append("Testing polymorfism\n");
        AddSeparators(response);
        return response;
    }
};


#endif //PA2_SERVER_ERRORLOG_H
