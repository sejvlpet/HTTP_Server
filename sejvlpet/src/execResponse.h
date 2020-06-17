#ifndef PA2_SERVER_EXECRESPONSE_H
#define PA2_SERVER_EXECRESPONSE_H



#include "response.h"

/**
 * Handles execution of executable files and returns standard output of such file
 */
class ExecResponse : public Response {
public:
	/**
 	 * saves members
 	 */
    ExecResponse(std::string root, std::string target) : _root(std::move(root)), _target(std::move(target)) {}

    /**
     * @copydoc Response::WriteOut()
     */
    void WriteOut(int socket) override;


private:
    std::string _root; //<! root directory
    std::string _target; //<! name of file to return
    std::map<std::string, std::string> _res;
    const constexpr static char *HEADER{"HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: "}; //<! HTTP header
    const constexpr static char *NO_OUTPUT{"Executable gave no output. Are you sure this was supposed to happen?"}; //<! response suspicous executable

    /**
     * @copydoc Response::CreateLog()
     */
    void CreateLog() override;
};

#endif //PA2_SERVER_EXECRESPONSE_H
