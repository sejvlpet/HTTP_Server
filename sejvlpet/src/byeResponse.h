#ifndef PA2_SERVER_BYERESPONSE_H
#define PA2_SERVER_BYERESPONSE_H

#include "response.h"

/**
 * Response returned after invoking server shutdown
 */
class ByeResponse : public Response {
public:
    /**
     * @copydoc Response::WriteOut()
     */
    void WriteOut(int socket) override;


private:
    const char *BYE{
            "HTTP/1.1 200\nContent-Type: text/html\nContent-Length: 174\n\n"
            "<!DOCTYPE html>\n"
            "<html lang=\"en\">\n"
            "<head>\n"
            "    <meta charset=\"UTF-8\">\n"
            "    <title>Server</title>\n"
            "</head>\n"
            "<body>\n"
            "<h1>\n"
            "    It's been an honor serving for you.\n"
            "</h1>\n"
            "</body>\n"
            "</html>"}; //<! response

    /**
     * @copydoc Response::CreateLog()
     */
    void CreateLog() override;

};

#endif //PA2_SERVER_BYERESPONSE_H
