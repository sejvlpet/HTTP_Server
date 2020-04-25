#ifndef PA2_SERVER_RESPONSE_H
#define PA2_SERVER_RESPONSE_H

#include <bits/unique_ptr.h>
#include <cstring>
#include <unistd.h>
#include "../../log/responseLog.h"

class Response {
public:
    // todo - hopefully unique_ptr returned like this'll thread safe (it really should), if no use shared_ptr
    std::unique_ptr<Log> GetLog() {
        return std::make_unique<ResponseLog>(_log);
    }

    virtual void WriteOut(int socket) {
        write(socket, HELLO, strlen(HELLO));
    };

    virtual ~Response()=default;

protected:
    ResponseLog _log;

    virtual void CreateLog() {};

private:
    const constexpr static char *HELLO{"HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: 21\n\nSomething went wrong"};

};


#endif //PA2_SERVER_RESPONSE_H
