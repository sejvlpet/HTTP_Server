#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <unistd.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <iostream>
#include <string>


const int PORT = 8080;

int main(int argc, char const *argv[]) {
    std::cout << "Test executable\n";


    int sock = 0;
    struct sockaddr_in serv_addr;
    const char *hello = "GET /tests/bin/helloWorld HTTP/1.1\n"
                        "Host: localhost:8080\n"
                        "Connection: keep-alive\n"
                        "Pragma: no-cache\n"
                        "Cache-Control: no-cache\n"
                        "Upgrade-Insecure-Requests: 1\n"
                        "User-Agent: Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/80.0.3987.163 Safari/537.36\n"
                        "Sec-Fetch-Dest: document\n"
                        "Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.9\n"
                        "Sec-Fetch-Site: none\n"
                        "Sec-Fetch-Mode: navigate\n"
                        "Sec-Fetch-User: ?1\n"
                        "Accept-Encoding: gzip, deflate, br\n"
                        "Accept-Language: en-US,en;q=0.9";
    char buffer[1024] = {0};
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        std::cout << "\n Socket creation error \n";
        return 1;
    }

    memset(&serv_addr, '0', sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        std::cout << "\nInvalid address/ Address not supported \n";
        return 1;
    }

    if (connect(sock, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        std::cout << "Connection Failed \n";
        return 1;
    }
    std::string expectedResult = "HTTP/1.1 200 OK\n"
                                 "Content-Type: text/plain\n"
                                 "Content-Length: 12\n"
                                 "\n"
                                 "Hello world";

    send(sock, hello, strlen(hello), 0);
    read(sock, buffer, expectedResult.size());
    close(sock);

    if (!strcmp(buffer, expectedResult.c_str())) {
        std::cout << "passed\n";
    } else {
        std::cout << "failed\n";
        std::cout << "expected:\n" << expectedResult << '\n';
        std::cout << "obtained:\n " << buffer << '\n';
    }
    return 0;
}