// Binary
#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    long num, i, bin;
    bin = 0;
    try {
        cout<<"Give a number to covert to binary: ";
        cin>>num;
    }
    catch (const std::exception& ex) {
        cout<<"Please provide a decimal number!\n";
        exit(1);
    }

    i = 0;
    while (1)
    {
        if(num==0){break;}

        bin += ((num%2)*pow(10, i));
        num = ((num - (num%2))/2);
        i++;
    }
    cout<<"binary: "<<bin<<"\n";

    return 0;
}

