// ex1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Math.h"

using namespace std;

int main()
{
    
    cout << "17+16= " << Math::Add(17, 16);
    cout << endl;
    cout << "14+67+6= " << Math::Add(14, 67,6);
    cout << endl;
    cout << "17.5+16.5= " << Math::Add(17.5, 16.4);
    cout << endl;
    cout << "17.5+16.5+18.7= " << Math::Add(17.5, 16.4,18.7); 
    cout << endl;
    cout << "17*16= " << Math::Mul(17, 16);
    cout << endl;
    cout << "14*67*6= " << Math::Mul(14, 67, 6);
    cout << endl;
    cout << "17.0*16.8= " << Math::Mul(17.0, 16.8);
    cout << endl;
    cout << "14.2*67.11*6.6= " << Math::Mul(14.2, 67.11, 6.6);

    cout << endl;
    cout << "13+78+56+68+55= " << Math::Add(5, 13, 78, 56, 68, 55);

    cout << endl;
    cout << "avb+jer= " << Math::Add("avb", "jer");

    return 0;
   
}