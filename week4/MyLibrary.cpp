#define _CRT_SECURE_NO_WARNINGS
#include "MyLibrary.h"
#include <cstdio>
#include <cstdlib>     /* srand, rand */
#include <ctime>       /* time */
#include <fstream>
#include<cstdarg>
#include<cstring>


int MyLibrary::get_books_count() const
{
    return books_number;
}

int MyLibrary::get_book_index_by_id(int i) const
{
    if (i < books_number && i>=0)
        return books[i];
    
    return -1;
}

MyLibrary::MyLibrary(const MyLibrary& m) : output_stream(m.output_stream)
{
    books_number = m.books_number;
    this->books  = new int[books_number];
    for (int i = 0; i < books_number; i++)
    {
        this->books[i] = m.books[i];
    }

}

MyLibrary::MyLibrary(ostream& output_stream) : output_stream(output_stream)
{
    this->books_number = -1;
    this->books        = nullptr;
}

MyLibrary::MyLibrary(ostream& output_stream, int books_number, int* books) : output_stream(output_stream)
{
   
    this->books_number = books_number;
    this->books=new int[books_number];
    for (int i=0;i<books_number;i++)
    {
        this->books[i] = books[i];
    }
}

MyLibrary::MyLibrary(ostream& output_stream, int books_number, int min, int max) : output_stream(output_stream)
{
    this->books_number = books_number;
    this->books        = new int[books_number];
    for (int i = 0; i < books_number; i++)
    {
        
         this->books[i] = rand()%max+min;
    }
}

MyLibrary::MyLibrary(ostream& output_stream, const char* books_values) : output_stream(output_stream)
{
    char* a = new char[strlen(books_values)];
    strcpy(a,(char*) books_values);
    char* p;
    p = strtok( a, ";");
    int i = 0;
    while (p!=nullptr)
    {
        i++;
        p = strtok(NULL, ";");
    }
    this->books_number = i;
    this->books        = new int[books_number];
    strcpy(a, (char*) books_values);

    p = strtok(a, ";");
    i = 0;
    while (p != nullptr)
    {
        int nr = atoi(p);
        this->books[i] = nr;
        p = strtok(NULL, ";");
        i++;
    }
}

MyLibrary::MyLibrary(ostream& output_stream, int books_count, ...) : output_stream(output_stream)
{
    this->books_number = books_count;
    this->books        = new int[books_count];
    va_list args;
    va_start(args, books_count);
    for (int i=0;i<books_count;i++)
    {
        books[i] = va_arg(args, int);
    }
    va_end(args);

}

void MyLibrary::print_books()
{
    output_stream << "Found " << books_number << " books" << endl;
    for (int i = 0; i < books_number; i++)
        output_stream << "Book: " << i << " " << books[i] << endl;
}

MyLibrary::~MyLibrary()
{
    delete[] books;
}

void MyLibrary::update_books_id_by_index(int book_index, int book_id)
{
    if (book_index < books_number)
        this->books[book_index] = book_id;
}
