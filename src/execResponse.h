#ifndef PA2_SERVER_EXECRESPONSE_H
#define PA2_SERVER_EXECRESPONSE_H



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
    const constexpr static char *NO_OUTPUT{"Executable gave no output. Are you sure this was supposed to happen?"};

    void CreateLog() override;
};

#endif //PA2_SERVER_EXECRESPONSE_H
