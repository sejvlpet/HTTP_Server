#ifndef PA2_SERVER_NOTFOUNDRESPONSE_H
#define PA2_SERVER_NOTFOUNDRESPONSE_H

#include "response.h"

class NotFoundResponse : public Response {
public:
    void WriteOut(int socket) override {
        write(socket, NOT_FOUND, strlen(NOT_FOUND));
        CreateLog();
    };


private:
    const char *NOT_FOUND{"HTTP/1.1 404\nContent-Type: text/html\nContent-Length: 36\n\nNot found<br> <a href=\"/\"> Home </a>"};


    void CreateLog() override {
        std::map<std::string, std::string> res;
        res["status"] = "404";

        _log.SetCustom(res);
    };

};


#endif //PA2_SERVER_NOTFOUNDRESPONSE_H
