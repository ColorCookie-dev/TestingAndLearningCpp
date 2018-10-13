#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <time.h>

using namespace std;

int main() {

    // random number
    srand( time(NULL) );  // choosing a random seed based on time
    int randNum = (rand() % 100) + 1;
    int guessedNum = 0;
    string guessedNumS;

    cout << "Guess a number b/w 1 and 100... ";
    do {
        getline(cin, guessedNumS);
        guessedNum = stoi(guessedNumS); // string to integer
        
        // Replying
        if (guessedNum < randNum) {
            cout << "Very Low\n";
        } else if (guessedNum > randNum) {
            cout << "Very High\n";
        }
    } while (guessedNum != randNum);

    cout << "You Win\n";

    return 0;
}
