#include "Math.h"
#include <cstdarg>
#include <stdlib.h>
#include <string.h>


int Math::Add(int a, int b)
{
    return a+b;
}

int Math::Add(int a, int b, int c)
{
    return a+b+c;
}

int Math::Add(double a, double b)
{
    return a+b;
}

int Math::Add(double a, double b, double c)
{
    return a+b+c;
}

int Math::Mul(int a, int b)
{
    return a*b;
}

int Math::Mul(int a, int b, int c)
{
    return a*b*c;
}

int Math::Mul(double a, double b)
{
    return a*b;
}

int Math::Mul(double a, double b, double c)
{
    return a*b*c;
}

int Math::Add(int count, ...)
{
    int suma = 0;
    va_list args;
    va_start (args, count);
    
    for (int i=0;i<count;i++)
    {
        suma += va_arg(args,int);
    }
    
    va_end(args);

    return suma;
}

char* Math::Add(const char* a, const char* b)
{
    if (a==nullptr ||b==nullptr) return nullptr;
    else
    {
        char* buffer;
        buffer = (char*) malloc(strlen(a) + strlen(b) + 1);
        int i  = 0;
        for (; i < strlen(a) + strlen(b); i++)
        {
            if (i < strlen(a))
                buffer[i] = a[i];
            else
                buffer[i] = b[i - strlen(a)];
        }
        buffer[i] = '\0';
        return buffer;
    }
}
