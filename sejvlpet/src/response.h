#ifndef PA2_SERVER_RESPONSE_H
#define PA2_SERVER_RESPONSE_H

#include <bits/unique_ptr.h>
#include <cstring>
#include <unistd.h>
#include "responseLog.h"

class Response {
public:
    std::unique_ptr<Log> GetLog() {
        return std::make_unique<ResponseLog>(_log);
    }

    virtual void WriteOut(int socket) {
        write(socket, HELLO, strlen(HELLO));
        CreateLog();
    };

    virtual ~Response()=default;

protected:
    ResponseLog _log;

    virtual void CreateLog() {
        std::map<std::string, std::string> res;
        res["status"] = "500";
        res["returned"] = "default response";

        _log.SetCustom(res);
    };

private:
    const char *HELLO{"HTTP/1.1 500\nContent-Type: text/plain\nContent-Length: 20\n\nSomething went wrong"};

};


#endif //PA2_SERVER_RESPONSE_H
