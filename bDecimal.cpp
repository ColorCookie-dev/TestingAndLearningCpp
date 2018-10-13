// binary to decimal
#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    long bin, num, dec, i;
    bool valid = false;
    i = 0;
    dec = 0;
    
    // checking if the number is binary or not
    while (1)
    {
        if(valid){break;}

        cout<<"Give a binary to covert to decimal: ";
        cin>>num;
        bin = num;

        while(1)
        {
            if (!((num%10==1)||(num%10==0))){
                cout<<"Give a valid binary!\n";break;
            }
            else{num = ((num - (num%10))/10);}

            if(num==0){valid=true;break;}
        }
    }

    // converting the binary to decimal
    while(1)
    {
        if(bin==0){break;}

        dec += ((bin%10)*pow(2,i));
        bin = ((bin-(bin%10))/10);
        i++;
    }

    cout<<"Decimal number is: "<<dec<<endl;

    return 0;
}

