#ifndef PA2_SERVER_EXECRESPONSE_H
#define PA2_SERVER_EXECRESPONSE_H


#include <utility>
#include <fstream>
#include <cstring>
#include <unistd.h>
#include "response.h"

class ExecResponse : public Response {
public:
    ExecResponse(std::string root, std::string target) : _root(std::move(root)), _target(std::move(target)) {}

    void WriteOut(int socket) override;


private:
    std::string _root;
    std::string _target;
    std::map<std::string, std::string> _res;
    const constexpr static char *HEADER{"HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: "};


    void CreateLog() override;
};

#endif //PA2_SERVER_EXECRESPONSE_H
