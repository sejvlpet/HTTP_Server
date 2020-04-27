#ifndef PA2_SERVER_DIRRESPONSE_H
#define PA2_SERVER_DIRRESPONSE_H

#include <dirent.h>
#include <vector>
#include "response.h"

class DirResponse : public Response {
public:
    DirResponse(std::string root) : _root(std::move(root)) {

        DIR* dirp = opendir(_root.c_str());
        struct dirent * dp;
        while ((dp = readdir(dirp)) != nullptr) {
            _content.emplace_back(dp->d_name);
        }
        closedir(dirp);
    }

    void WriteOut(int socket) override {
        std::string response = HTML_HEADER, subPath = _root.substr(_root.find_last_of('/') + 1);
        for(const std::string &item : _content) {
            response.append("<a href=\"" + subPath + "/" + item + "\">" + item + "<a\"><br />\n");
        }
        response.append(HTML_FOOTER);

        std::string realResponse = HEADER + std::to_string(response.size());
        realResponse.append("\n\n");
        realResponse.append(response);

        write(socket, realResponse.c_str(), realResponse.size());
        CreateLog();
    };
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
                                             "<body>"};

    const constexpr static char *HTML_FOOTER{"</body>\n"
                                             "</html>"};
    void CreateLog() override {
        std::map<std::string, std::string> res;
        res["status"] = "200";
        res["returned dir"] = _root;

        _log.SetCustom(res);

    };
};


#endif //PA2_SERVER_DIRRESPONSE_H
