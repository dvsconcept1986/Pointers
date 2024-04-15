// Pointers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <ctime>

void RandomAddress();
void PrintIntAndAddress(int value, int* ptr);

int main()
{
    //Program 1 start
    RandomAddress();
    std::cout << "\n";
    //Program 1 end

    //Program 2 start
    int numberArray[15];

    for (int i = 0; i < 15; ++i)
        numberArray[i] = std::rand() % 100 + 1;

    std::cout << "Array Values and corresponding Memory Address:\n";
    std::cout << "==============================================\n";
    for (int i = 0; i < 15; ++i)
        PrintIntAndAddress(numberArray[i], &numberArray[i]);
    //Program 2 end



}

void RandomAddress()
{
    int numberArray[15];

    for (int i = 0; i < 15; ++i)
        numberArray[i] = std::rand() % 100 + 1;


    for (int i = 0; i < 15; ++i)
        std::cout << numberArray[i] << "\n";

    std::cout << "\n";
    std::cout << "Address of the numbers in the array:\n";
    std::cout << "====================================\n";
    for (int i = 0; i < 15; ++i)
        std::cout << &numberArray[i] << "\n";
}

void PrintIntAndAddress(int value, int* ptr) {
    std::cout << "Value: " << value << " Memory Address: " << ptr << "\n";
}
