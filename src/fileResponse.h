#ifndef PA2_SERVER_FILERESPONSE_H
#define PA2_SERVER_FILERESPONSE_H


#include "response.h"

/**
 * Handles returning of file content
 */
class FileResponse : public Response {
public:
    /**
     * saves parametrs as member values
     */
    FileResponse(std::string root, std::string target, bool isHtml = true);

    /**
     * @copydoc Response::WriteOut()
     */
    void WriteOut(int socket) override;


private:
    std::string _root; //<! root directory
    std::string _target; //<! target of gicen file
    const constexpr static char *HTML_HEADER{"HTTP/1.1 200 OK\nContent-Type: text/html\nContent-Length: "}; //<! html header
    const constexpr static char *TEXT_HEADER{"HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: "}; //<! plain text header
    bool _isHtml{true};

    /**
     * @copydoc Response::CreateLog()
     */
    void CreateLog() override;
};


#endif //PA2_SERVER_FILERESPONSE_H
