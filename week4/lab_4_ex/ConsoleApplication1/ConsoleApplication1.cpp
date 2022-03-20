
#include <iostream>
#include "sort.h"

using namespace std;


int main()
{
    int vector[] = { 1, 2, 43, 57, 6 };
    int n        = 5;
    sort a(vector,n);
    a.Print();

    sort b(5, 44, 53, 6, 7, 1);
    b.Print();

    sort c("12,45,67,58,55");
    c.Print();


    return 0;
}
