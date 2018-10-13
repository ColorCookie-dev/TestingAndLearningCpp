#include <iostream>
#include <string>

using String = std::string;

int main() {
    char * myString;
    myString = "Hello World";
    myString = "Hi, Bro";

    String newString = myString;

    std::cout << myString << std::endl;
    std::cout << newString << std::endl;
}
