#ifndef PA2_SERVER_RESPONSE_H
#define PA2_SERVER_RESPONSE_H

#include "responseLog.h"

class Response {
public:
    Log &GetLog();

    virtual void WriteOut(int socket);

    virtual ~Response()=default;

protected:
    ResponseLog _log;

    virtual void CreateLog();

private:
    const char *HELLO{"HTTP/1.1 500\nContent-Type: text/plain\nContent-Length: 20\n\nSomething went wrong"};

};


#endif //PA2_SERVER_RESPONSE_H
