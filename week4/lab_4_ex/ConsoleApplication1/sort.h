#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <iostream>
#include<cstdarg>
#include<cstring>


class sort
{
    // adaugă membri de date
    int* lista;
    int nr_elemente;
   
  public:
    // adaugă constructori
    
    sort(int nr_elemente,int min,int max);
    sort(int* v,int n);
    sort(int* v);
    sort(int nr_parametri, ...);
    sort(const char* sir);
   

    void InsertSort(bool ascendent = false);

    void QuickSort(bool ascendent = false);

    void BubbleSort(bool ascendent = false);

    void Print();

    int GetElementsCount();

    int GetElementFromIndex(int index);
};
