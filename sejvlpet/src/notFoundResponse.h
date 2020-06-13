#ifndef PA2_SERVER_NOTFOUNDRESPONSE_H
#define PA2_SERVER_NOTFOUNDRESPONSE_H

#include "response.h"

/**
 * Handles response for case where target wasn't found on server
 */
class NotFoundResponse : public Response {
public:
    /**
     * @copydoc Response::WriteOut()
     */
    void WriteOut(int socket) override;

private:
    const char *NOT_FOUND{
            "HTTP/1.1 404\nContent-Type: text/html\nContent-Length: 36\n\nNot found<br> <a href=\"/\"> Home </a>"}; // <! response

    /**
     * @copydoc Response::WriteOut()
     */
    void CreateLog() override;

};


#endif //PA2_SERVER_NOTFOUNDRESPONSE_H
