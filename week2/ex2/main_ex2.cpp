#include <iostream>
#include "wave.h"
#include "operatii.h"

/*
	Design a C++ class that reflects the properties of an wave of  enemies. The class should include the following:
 - methods to set and get the name of the wave
 - methods to set and get the number of enemies  (must be bigger than 0)
 - methods to set and get the starting health (bigger than 0)
 - methods to set and get the money per enemy (must be a float value)


	Create 2 global functions that compare two wave in terms of: number of enemies and money per enemy.
If two waves are equal the return value of such a function will be 0. If the first wave is bigger than the second one, the return value will be 1, otherwise -1.
	Make sure that you have the following:
a cpp file for the methods specific to the class
a header file for the global functions
a cpp file for the global functions implementation
a main.cpp file that shows how the methods and global functions can be used.

*/


int main()
{
    wave w1,w2;
    char* nume1, *nume2;
    nume1 = (char*) "wave1";
    nume2 = (char*) "wave2";
    w1.init(nume1,7,10,9.51 );
    w2.init(nume2, 9, 8, 10.5);

    w1.set_nr_enemies(14);
    switch (compare_money(w1, w2))
    {
    case -1:
        std::cout << nume2;
        break;
    case 0:
        std::cout << nume2 << " "<<nume1;
        break;
    case 1:
        std::cout << nume1;
        break;
    default:
        break;
    }

    std::cout << '\n';

    switch (compare_number(w1, w2))
    {
    case -1:
        std::cout << nume2;
        break;
    case 0:
        std::cout << nume2 << " " << nume1;
        break;
    case 1:
        std::cout << nume1;
        break;
    default:
        break;
    }
    

    return 0;
}