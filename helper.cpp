#include <iostream>
#include "helper.h"


void Helper::Wait(size_t  length) {
    std::cout << "waiting\n";
    for (size_t i = 0; i < length; i++) {}
}

void Helper::Wait() {
    std::cout << "waiting\n";
    for (size_t i = 0; i < WAIT; i++) {}
}