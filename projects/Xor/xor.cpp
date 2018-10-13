// xor.cpp
#include "xor.h"

int main(int argc, char** argv) {
    
    // checking if argv is present
    if (argc != 3) {
        std::cout << "Use it properly\n";
        exit(1);
    }

    const std::string message = (std::string) argv[1];
    const std::string key = (std::string) argv[2];

    const std::string encrypted = xor_encrypt(message, key);
    std::cout << encrypted << std::endl;
}

