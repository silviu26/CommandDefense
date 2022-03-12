
#include <iostream>
#include "Canvas.h"
 
using namespace std;

int main()
{
    Canvas a(70, 50);
    
    a.DrawRect(5, 5, 10, 10,'a');
 
    a.Clear();
    a.FillCircle(25, 25, 10, 'b');
    a.Print();
    std::cout << endl;
    a.Clear();
    a.DrawLine(5, 5, 25, 24,'u');
    a.Print();

    return 0;
}