#include <iostream>
#include <string>

#define Log(x) std::cout << x << std::endl

int main() {
    std::string name = "Hello";
    name += " World";
    Log(name);
    Log(name.size());
}
