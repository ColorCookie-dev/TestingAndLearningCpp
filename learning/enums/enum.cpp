#include <iostream>

int main() {
    enum Example {
        A = 6, B, C
    };

    Example myVal = A;
    myVal = B;
    // Example myVal = 7; not possible
    // Example myVal = 2; is not possible
}
