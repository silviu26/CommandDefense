#include "sort.h"


sort::sort(int nr_elemente, int min, int max)
{
    this->nr_elemente = nr_elemente;
    this->lista = new int[nr_elemente];
    for (int index=0;index<nr_elemente;index++)
    {
        lista[index] = rand()/max+min;
    }
}

sort::sort(int* v,int n)
{
    this->nr_elemente = n;
    this->lista       = new int[n];
    for (int index = 0; index < nr_elemente; index++)
    {
        lista[index] = v[index];
    }
}

sort::sort(int* v)
{
    this->nr_elemente = sizeof(v);
    this->lista       = new int[nr_elemente];
    for (int index = 0; index < nr_elemente; index++)
    {
        lista[index] = v[index];
    }
}

sort::sort(int nr_parametri, ...)
{
    this->nr_elemente = nr_parametri;
    this->lista       = new int[nr_elemente];
    va_list args;
    va_start(args, nr_parametri);
    for (int i = 0; i < nr_parametri; i++)
    {
        lista[i] = va_arg(args, int);
    }
    va_end(args);
}

sort::sort(const char* sir)
{
    char* a = new char[strlen(sir)];
    strcpy(a, sir);
    char* p;
    p     = strtok(a, ",");
    int i = 0;
    while (p != nullptr)
    {
        i++;
        p = strtok(NULL, ",");
    }
    this->nr_elemente = i;
    this->lista       = new int[nr_elemente];
    strcpy(a, sir);

    p = strtok(a, ",");
    i = 0;
    while (p != nullptr)
    {
        int nr         = atoi(p);
        this->lista[i] = nr;
        p              = strtok(NULL, ",");
        i++;
    }

}

void sort::InsertSort(bool ascendent)
{
    int i, key, j;
    for (i = 1; i < nr_elemente; i++)
    {
        key = lista[i];
        j   = i - 1;

        if (ascendent == true)
        {
            while (j >= 0 && lista[j] > key)
            {
                lista[j + 1] = lista[j];
                j = j - 1;
            }
            lista[j + 1] = key;
        }
        else
        {
            while (j >= 0 && lista[j] < key)
            {
                lista[j + 1] = lista[j];
                j = j - 1;
            }
            lista[j + 1] = key;
        
        }
    }
}

void sort::QuickSort(bool ascendent)
{
   
}

void sort::BubbleSort(bool ascendent)
{
    for (int i = 0; i < nr_elemente - 1; i++)
        for (int j = 0; j < nr_elemente; j++)
            if (ascendent == true)
            {
                if (lista[i] > lista[j])
                {
                    int aux   = lista[i];
                    lista[i]  = lista[j];
                    lista[j]  = aux;
                }
            }
            else
            {
                if (lista[i] < lista[j])
                {
                    int aux   = lista[i];
                    lista[i] = lista[j];
                    lista[j]  = aux;
                }
            }
}

void sort::Print()
{
    for (int index = 0; index < nr_elemente; index++)
    {
        std::cout << lista[index] << " ";
    }
    std::cout << '\n';
}

int sort::GetElementsCount()
{
    return this->nr_elemente;
}

int sort::GetElementFromIndex(int index)
{
    if (index >= 0 && index < nr_elemente)
        return this->lista[index];
    else
        return -1;
}


