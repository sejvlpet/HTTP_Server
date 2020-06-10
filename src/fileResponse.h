#ifndef PA2_SERVER_FILERESPONSE_H
#define PA2_SERVER_FILERESPONSE_H

#include <utility>
#include <fstream>
#include <cstring>
#include <unistd.h>
#include "response.h"

class FileResponse : public Response {
public:
    FileResponse(std::string root, std::string target, bool isHtml = true);

    void WriteOut(int socket) override;;


private:
    std::string _root;
    std::string _target;
    const constexpr static char *HTML_HEADER{"HTTP/1.1 200 OK\nContent-Type: text/html\nContent-Length: "};
    const constexpr static char *TEXT_HEADER{"HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: "};
    bool _isHtml{true};


    void CreateLog() override;
};


#endif //PA2_SERVER_FILERESPONSE_H
