// Pointers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <ctime>

void RandomAddress(int numArr[]);

int main()
{
    int numberArray[15];

    for (int i = 0; i < 15; ++i)
        numberArray[i] = std::rand() % 100 + 1;


    for (int i = 0; i < 15; ++i)
        std::cout << numberArray[i] << "\n";
    
    std::cout << "\n";
    std::cout << "Address of the numbers in the array:\n";
    RandomAddress(numberArray);
}

void RandomAddress(int numArr[])
{
    for (int i = 0; i < 15; ++i)
        std::cout << &numArr[i] << "\n";
}
