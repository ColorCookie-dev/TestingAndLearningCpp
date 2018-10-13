#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    // for loop
    for (int i = 0; i < 5; i++) {
        cout << "Iter - " << i << endl;
    }

    // While loop
    int i = -1;
    while (i < 5) {
        cout << "Iter - " << i << endl;
        i++;
    }

    // Do while loops
    i = 0;
    do {
        cout << "In the do - while loop!" << endl; 
    } while (i > 50);
}
