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
    if (argc < 2) {
        std::cout << "Too few arguments \n";
        return 1;
    }

    int sock = 0;
    struct sockaddr_in serv_addr;
    const char *hello = "THREAD_TEST";
    char buffer[1024] = {0};
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        std::cout << "\n Socket creation error \n";
        return 1;
    }

    memset(&serv_addr, '0', sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        std::cout << "\nInvalid address/ Address not supported \n";
        return 1;
    }

    if (connect(sock, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        std::cout << "Connection Failed \n";
        return 1;
    }
    send(sock, hello, strlen(hello), 0);
    read(sock, buffer, 1024);

    std::string expectedResult = "TEST_PASSED-";
    expectedResult.push_back(*argv[1]); // fixme read value at expectedResult initialisation
    if (!strcmp(buffer, expectedResult.c_str())) {
        std::cout << "passed\n";
    } else {
        std::cout << "failed\n";
        std::cout << "expected " << expectedResult << '\n';
        std::cout << "obtained " << buffer << '\n';
    }
    return 0;
}