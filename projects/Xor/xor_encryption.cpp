#include <iostream>
#include <string>

const std::string xor_encrypt(const std::string& message, const std::string& key) {
    std::string encrypted = "";

    for (int i = 0; i < message.size(); i++)
        encrypted += (char) (((char) message[i]) ^ ((char) key[i%key.size()]));
    return encrypted;
}

