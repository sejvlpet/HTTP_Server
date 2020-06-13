#ifndef PA2_SERVER_DIRRESPONSE_H
#define PA2_SERVER_DIRRESPONSE_H

#include "response.h"
#include <vector>

/**
 * Reads and creates response with for directory
 */
class DirResponse : public Response {
public:
    /**
     * saves content of director passed as parametr
     * @param root dir name
     */
    DirResponse(std::string root);
    /**
     * @copydoc Response::WriteOut()
     */
    void WriteOut(int socket) override;

private:
    std::string _root; //<! root name
    std::vector<std::string> _content; //<! content of root
    const constexpr static char *HEADER{"HTTP/1.1 200 OK\nContent-Type: text/html\nContent-Length: "}; //<! http header
    const constexpr static char *HTML_HEADER{"<!DOCTYPE html>\n"
                                             "<html lang=\"en\">\n"
                                             "<head>\n"
                                             "    <meta charset=\"UTF-8\">\n"
                                             "    <title>Directory passing</title>\n"
                                             "</head>\n"
                                             "<body>\n"}; //<! html header

    const constexpr static char *HTML_FOOTER{"</body>\n"
                                             "</html>"}; //<! html footer
    /**
     * @copydoc Response::CreateLog()
     */
    void CreateLog() override;
};


#endif //PA2_SERVER_DIRRESPONSE_H
