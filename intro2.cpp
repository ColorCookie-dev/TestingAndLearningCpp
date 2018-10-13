#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

int main() {

    bool amIHappy = true;

    // variable = (condition) ? true : false;
    int favNum = (amIHappy) ? 7 : 3;

    // printing and typecasting
    cout << "favNum is " << (double) favNum << endl;

    // Arrays
    // nearly same as in C, if not completely same as C
    // can't be bothered to type all these


    // random number
    int randNum = (rand() % 100) + 1;

    



    return 0;
}
