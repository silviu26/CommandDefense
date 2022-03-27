#pragma once
#define _CRT_SECURE_NO_WARNINGS
class Number

{
    // add data members
    char* value;
    int base;

  public:
    friend Number operator+(const Number& l, const Number& r);
    friend Number operator-(const Number& l, const Number& r);
    Number(const char* value, int base); // where base is between 2 and 16

    ~Number();

    // add operators and copy/move constructor
    Number(const Number& m);
    Number& operator++();
    Number operator++(int);
    Number& operator--();
    Number operator--(int);
    Number& operator=(Number a);
    char operator[](int a);
    
    char* GetValue()const;
    

    void SwitchBase(int newBase);

    void Print()const;

    int GetDigitsCount()const; // returns the number of digits for the current number

    int GetBase()const; // returns the current base
};


bool operator==(const Number& l, const Number& r);
bool operator!=(const Number& l, const Number& r);

bool operator<(const Number& l, const Number& r);
bool operator>(const Number& l, const Number& r);
bool operator>=(const Number& l, const Number& r);
bool operator<=(const Number& l, const Number& r);

