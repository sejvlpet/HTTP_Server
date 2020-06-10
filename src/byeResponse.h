//
// Created by petrsejvl on 10.06.20.
//

#ifndef PA2_SERVER_BYERESPONSE_H
#define PA2_SERVER_BYERESPONSE_H

#include "response.h"

class ByeResponse : public Response {
public:
    void WriteOut(int socket) override {
        write(socket, BYE, strlen(BYE));
        CreateLog();
};


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
            "</html>"};


    void CreateLog() override {
        std::map<std::string, std::string> res;
        res["status"] = "200";

        _log.SetCustom(res);
    };

};

#endif //PA2_SERVER_BYERESPONSE_H
