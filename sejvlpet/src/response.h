#ifndef PA2_SERVER_RESPONSE_H
#define PA2_SERVER_RESPONSE_H

#include "responseLog.h"
/**
 * Base class for responses, used as default response
 */
class Response {
public:
    /**
     * returns reference to log object
     * @return reference to log object
     */
    Log &GetLog();

    /**
     * accepts socket number and writes response there
     * @param socket
     */
    virtual void WriteOut(int socket);

    virtual ~Response() = default;

protected:
    ResponseLog _log; //<! log object for response

    /**
     * Creates log object and saves it to _log member
     */
    virtual void CreateLog();

private:
    const char *HELLO{"HTTP/1.1 500\nContent-Type: text/plain\nContent-Length: 20\n\nSomething went wrong"}; //<! default header

};


#endif //PA2_SERVER_RESPONSE_H
