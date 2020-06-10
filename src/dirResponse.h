#ifndef PA2_SERVER_DIRRESPONSE_H
#define PA2_SERVER_DIRRESPONSE_H

#include <dirent.h>
#include <vector>
#include "response.h"

class DirResponse : public Response {
public:
    DirResponse(std::string root);

    void WriteOut(int socket) override;

private:
    std::string _root;
    std::vector<std::string> _content;
    const constexpr static char *HEADER{"HTTP/1.1 200 OK\nContent-Type: text/html\nContent-Length: "};
    const constexpr static char *HTML_HEADER{"<!DOCTYPE html>\n"
                                             "<html lang=\"en\">\n"
                                             "<head>\n"
                                             "    <meta charset=\"UTF-8\">\n"
                                             "    <title>Directory passing</title>\n"
                                             "</head>\n"
                                             "<body>\n"};

    const constexpr static char *HTML_FOOTER{"</body>\n"
                                             "</html>"};

    void CreateLog() override;
};


#endif //PA2_SERVER_DIRRESPONSE_H
