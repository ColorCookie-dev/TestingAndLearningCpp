#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

int main() {
    
    string myname = "Pratyus";
    string name;
    cin >> name;

    cout << "Hello, " << name << endl;
    cout << "string length of name " << name.size() << endl;
    cout << "Is empty? " << name.empty() << endl;


    // comparision
    string dogString = "Dog";
    string catString = "Cat";

    cout << dogString.compare(catString) << endl;
    
    return 0;
}
