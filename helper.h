#ifndef PA2_SERVER_HELPER_H
#define PA2_SERVER_HELPER_H
#include <cstdio>

/**
 * Helper for development purposes, shouldn't be (at least not like that) in final version
 */
class Helper {
public:
    const static size_t WAIT = 200000000000;
    static void Wait(size_t  length);
    static void Wait();
};


#endif //PA2_SERVER_HELPER_H
