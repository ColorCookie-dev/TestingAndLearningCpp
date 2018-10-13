// pointers.cpp

#include <iostream>

#define Log(x) std::cout << x << std::endl

int main(int argc, char** argv) {
    int * ptr = nullptr;
    
    int var = 5;
    ptr = &var;
    *ptr = 10;

    // refernces
    int & ref = *ptr;
    ref++;

    Log(*ptr);
}
