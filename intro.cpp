// This is a comment
/*
 * multiline comment
*/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;


// main function
int main() {
    // printing to the screen
    cout << "Hello World" << endl;

    /* data types */
    const double PI = 3.1415926535;  // const means cannot be changed

    char myGrade = 'A';

    bool isHappy = true;

    int myage = 16;

    float favNum = 3.141592;

    double otherFavNum = 1.6180339887;

    cout << "My Favorute number: " << otherFavNum << endl;

    cout << "Size of myage variable: " << sizeof(myage) << endl;

    // here i went bigger than the size what can be contained in int and results are interesting
    int largestInt = 2147483648;
    cout << "Largest Int: " << largestInt << endl;

    // Basic switch statement
    switch (myGrade) {
        case 'A':
            cout << "Great\n";
            break;
        case 'D':
            cout << "Worst Exam ever?";
            break;
        default:
            cout << "Meh, You're average!";
    }

    return 0;
}
