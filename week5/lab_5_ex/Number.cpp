#include "Number.h"
#include <cstring>
#include <iostream>
#include<cmath>


Number::Number(const char* value, int base) 
{
    this->value = new char[strlen(value)+1];
    strcpy(this->value , value);
    this->base = base;

}

Number::~Number()
{
    delete[]    value;
}

Number::Number(const Number& m)
{
    
    this->value = new char[strlen(m.value) + 1];
    strcpy(this->value, m.value);
    this->base = m.base;
}

Number& Number::operator++()
{
    Number a("01", 2);
    *this = *this + a;
    
    return *this;
}

Number Number::operator++(int)
{
    Number a(*this);
    ++(*this);
    return a;
}

Number& Number::operator--()
{
    Number a("01", 2);
    *this = *this - a;

    return *this;
}

Number Number::operator--(int)
{
    Number a(*this);
    --(*this);
    return a;
}

Number& Number::operator=(Number a)
{
    this->value = new char[a.GetDigitsCount() + 1];
    strcpy(this->value, (char*) a.GetValue());
    this->base = a.base;
    return *this;
}

char Number::operator[](int a)
{
    return this->value[a-1];
}



char* Number::GetValue()const
{
    return this->value;
}

void Number::SwitchBase(int newBase)
{
    
    int numar = 0;
    for (int i = strlen(value)-1; i >= 0; i--)
    {
        int nr;
        switch (value[i])
        {
        case '0':
            nr = 0;
            break;
        case '1':
            nr = 1;
            break;
        case '2':
            nr = 2;
            break;
        case '3':
            nr = 3;
            break;
        case '4':
            nr = 4;
            break;
        case '5':
            nr = 5;
            break;
        case '6':
            nr = 6;
            break;
        case '7':
            nr = 7;
            break;
        case '8':
            nr = 8;
            break;
        case '9':
            nr = 9;
            break;
        case 'A':
            nr = 10;
            break;
        case 'B':
            nr = 11;
            break;
        case 'C':
            nr = 12;
            break;
        case 'D':
            nr = 13;
            break;
        case 'E':
            nr = 14;
            break;
        case 'F':
            nr = 15;
            break;
        default:
            break;
        }
        numar = numar + int(pow(base, strlen(value) - 1-i)) * nr;
    }

    int copy_nr = numar;
    
    int j       = 0;
    while (copy_nr!=0)
    {
        copy_nr /= newBase;
        j++;
    }
    delete[] value;
    this->value = new char[j+1];
    this->base  = newBase;

    copy_nr = numar;
    value[j] = '\0';
    j--;
    while (copy_nr != 0)
    {
         int r = copy_nr % newBase;
         copy_nr /= newBase;
         char ch;
         switch (r)
         {
         case 0:
             ch = '0';
             break;
         case 1:
             ch = '1';
             break;
         case 2:
             ch = '2';
             break;
         case 3:
             ch = '3';
             break;
         case 4:
             ch = '4';
             break;
         case 5:
             ch = '5';
             break;
         case 6:
             ch = '6';
             break;
         case 7:
             ch = '7';
             break;
         case 8:
             ch = '8';
             break;
         case 9:
             ch = '9';
             break;
         case 10:
             ch = 'A';
             break;
         case 11:
             ch = 'B';
             break;
         case 12:
             ch = 'C';
             break;
         case 13:
             ch = 'D';
             break;
         case 14:
             ch = 'E';
             break;
         case 15:
             ch = 'F';
             break;
         default:
             break;
         }
         value[j] = ch;
         j--;

    }
    
    
}

void Number::Print()const
{
    std::cout << value;
    std::cout << '\n';
}

int Number::GetDigitsCount()const
{
    
    return strlen(value);
}

int Number::GetBase()const
{
    return base;
}

Number operator+(const Number& l, const Number& r)
{
    char* rezultat;
    int baza;
    int j;     
    if (l.GetBase() < r.GetBase())
    {
        baza = r.GetBase();
        j = r.GetDigitsCount() + 2;
    }
    else
    {
        baza = l.GetBase();
        j    = l.GetDigitsCount() + 2;
    }

    Number a(l);
    Number b(r);
    a.SwitchBase(baza);
    b.SwitchBase(baza);
    if (l.GetDigitsCount() < r.GetDigitsCount())
        rezultat = new char[r.GetDigitsCount() + 2];
    else
        rezultat = new char[l.GetDigitsCount() + 2];

    a.SwitchBase(10);
    b.SwitchBase(10);

    int nr = atoi(a.GetValue()) + atoi(b.GetValue());
    
   
    int copy_nr  = nr;
    rezultat[j] = '\0';
    j--;
    while (copy_nr != 0)
    {
        int r = copy_nr % baza;
        copy_nr /= baza;
        char ch;
        switch (r)
        {
        case 0:
            ch = '0';
            break;
        case 1:
            ch = '1';
            break;
        case 2:
            ch = '2';
            break;
        case 3:
            ch = '3';
            break;
        case 4:
            ch = '4';
            break;
        case 5:
            ch = '5';
            break;
        case 6:
            ch = '6';
            break;
        case 7:
            ch = '7';
            break;
        case 8:
            ch = '8';
            break;
        case 9:
            ch = '9';
            break;
        case 10:
            ch = 'A';
            break;
        case 11:
            ch = 'B';
            break;
        case 12:
            ch = 'C';
            break;
        case 13:
            ch = 'D';
            break;
        case 14:
            ch = 'E';
            break;
        case 15:
            ch = 'F';
            break;
        default:
            break;
        }
        rezultat[j] = ch;
        j--;
    }
    while (j > -1)
    {
        strcpy(rezultat, rezultat + 1);
        j--;
    }
    return {rezultat,baza};
}

Number operator-(const Number& l, const Number& r)
{
    char* rezultat;
    int baza;
    int j;
    if (l.GetBase() < r.GetBase())
    {
        baza = r.GetBase();
        j    = r.GetDigitsCount() + 2;
    }
    else
    {
        baza = l.GetBase();
        j    = l.GetDigitsCount() + 2;
    }

    Number a(l);
    Number b(r);
    a.SwitchBase(baza);
    b.SwitchBase(baza);
    if (l.GetDigitsCount() < r.GetDigitsCount())
        rezultat = new char[r.GetDigitsCount() + 2];
    else
        rezultat = new char[l.GetDigitsCount() + 2];

    a.SwitchBase(10);
    b.SwitchBase(10);

    int nr = atoi(a.GetValue()) - atoi(b.GetValue());

    
    int copy_nr = nr;
    rezultat[j] = '\0';
    j--;
    while (copy_nr != 0)
    {
        int r = copy_nr % baza;
        copy_nr /= baza;
        char ch;
        switch (r)
        {
        case 0:
            ch = '0';
            break;
        case 1:
            ch = '1';
            break;
        case 2:
            ch = '2';
            break;
        case 3:
            ch = '3';
            break;
        case 4:
            ch = '4';
            break;
        case 5:
            ch = '5';
            break;
        case 6:
            ch = '6';
            break;
        case 7:
            ch = '7';
            break;
        case 8:
            ch = '8';
            break;
        case 9:
            ch = '9';
            break;
        case 10:
            ch = 'A';
            break;
        case 11:
            ch = 'B';
            break;
        case 12:
            ch = 'C';
            break;
        case 13:
            ch = 'D';
            break;
        case 14:
            ch = 'E';
            break;
        case 15:
            ch = 'F';
            break;
        default:
            break;
        }
        rezultat[j] = ch;
        j--;
    }
    while (j > -1)
    {
        strcpy(rezultat, rezultat + 1);
        j--;
    }
    return { rezultat, baza };
}

bool operator==(const Number& l, const Number& r)
{
    Number a(l);
    Number b(r);
    a.SwitchBase(10);
    b.SwitchBase(10);
    if (atoi(a.GetValue()) == atoi(b.GetValue()))
        return true;
    return false;
}

bool operator!=(const Number& l, const Number& r)
{
    return !(l==r);
}

bool operator<(const Number& l, const Number& r)
{
    Number a(l);
    Number b(r);
   
    a.SwitchBase(10);
    b.SwitchBase(10);
    if (atoi(a.GetValue()) < atoi(b.GetValue()))
        return true;
    return false;
}

bool operator>(const Number& l, const Number& r)
{
    return l != r && !(l<r);
}

bool operator>=(const Number& l, const Number& r)
{
    return !(l<r);
}

bool operator<=(const Number& l, const Number& r)
{
    return !(l>r);
}

