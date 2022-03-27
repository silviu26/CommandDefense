// lab_5_ex.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Number.h"

using namespace std;

int main()
{
    Number n1("10110010", 2);
    
    Number n3("734", 8);
    Number n2 = n3 - n1;
    Number n4(n1);
    
    n1.Print();
    (--n1).Print();
    n1.Print();
    n1 = n2;
    n1.Print();
    cout<<n1.GetBase()<<endl;
    cout << n1[2]<<endl;
    n4 = n4 + n1;
    n4.SwitchBase(2);
    n4.Print();
    n1.Print();
    if (n4 < n1)
        n4.Print();
    else
        n1.Print();

    return 0;
}

