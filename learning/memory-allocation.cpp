#include <iostream>
#include <cstring>

#define Log(x) std::cout << x << std::endl

int main(int argc, char** argv) {
    int * ptr = nullptr;
    
    char * buffer = new char[8];
    // memset fills certain block of memory with the given value
    memset(buffer, 0, 8);

    strcpy(buffer, "Hwlloow!");

    char ** newptr = &buffer;

    Log(buffer);
    delete[] buffer;
}
