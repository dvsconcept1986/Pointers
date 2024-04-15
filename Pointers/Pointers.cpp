// Pointers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

enum CarColors {
    Red,
    Blue,
    Green,
    Yellow
};

struct Car {
    char Make[32];
    char Model[32];
    int Year;
    int Mileage;
    CarColors Color;
};

void RandomAddress();
void PrintIntAndAddress(int value, int* ptr);
void repaintCar(Car* ptrCar, CarColors newcolor);
void printCar(Car c);
void printCarPointer(Car* ptrCar);
void addMileage(Car* ptrCar, int milestoadd);

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
    std::cout << "\n\n";
    //Program 2 end

    //Program 3 start
    Car carArray[3];

    // Input information for each car
    for (int i = 0; i < 3; ++i) {
        std::cout << "Enter details for Car " << (i + 1) << ":\n";

        std::cout << "Make: ";
        std::cin.getline(carArray[i].Make, 32);

        std::cout << "Model: ";
        std::cin.getline(carArray[i].Model, 32);

        std::cout << "Year: ";
        std::cin >> carArray[i].Year;

        std::cout << "Mileage: ";
        std::cin >> carArray[i].Mileage;

        std::cout << "Color (0 for Red, 1 for Blue, 2 for Green, 3 for Yellow): ";
        int colorInput;
        std::cin >> colorInput;
        carArray[i].Color = static_cast<CarColors>(colorInput);


        std::cout << std::endl;
    }

    // Display all information for each car
    std::cout << "Printing cars...\n";
    for (int i = 0; i < 3; ++i) {
        std::cout << "Car " << (i + 1) << " - ";
        printCar(carArray[i]);
    }

    std::cout << "\nPrinting car pointers...\n";
    for (int i = 0; i < 3; ++i) {
        std::cout << "Car " << (i + 1) << " - ";
        printCarPointer(&carArray[i]);
    }

    std::cout << "Let's repaint a car. Which car would you like to repaint? (1, 2, or 3) ";
    int carChoice;
    std::cin >> carChoice;
    std::cout << "What color would you like to change it to? (0 for Red, 1 for Blue, 2 for Green, 3 for Yellow) ";
    int colorChoice;
    std::cin >> colorChoice;
    CarColors newColor = static_cast<CarColors>(colorChoice);
    repaintCar(&carArray[carChoice - 1], newColor);

    
    std::cout << "\nPrinting Updated Car information...\n";
    for (int i = 0; i < 3; ++i) {
        std::cout << "Car " << (i + 1) << " - ";
        printCarPointer(&carArray[i]);
    }

    std::cout << "\nWhich car have you been driving? (1, 2, or 3) ";
    int carMilesChoice;
    std::cin >> carMilesChoice;
    std::cout << "How many miles did you drive? ";
    int carMiles;
    std::cin >> carMiles;
    addMileage(&carArray[carChoice - 1], carMiles);

    std::cout << "\nPrinting Updated Car information...\n";
    for (int i = 0; i < 3; ++i) {
        std::cout << "Car " << (i + 1) << " - ";
        printCarPointer(&carArray[i]);
    }
    //Program 3 end


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

void repaintCar(Car* ptrCar, CarColors newcolor) {
    ptrCar->Color = newcolor;
}


void printCar(Car c) {
    const char* colorNames[] = { "Red", "Blue", "Green", "Yellow"}; // Add more color names as needed
    std::cout << c.Year << " " << colorNames[c.Color] << " " << c.Make << " " << c.Model << " with " << c.Mileage << " miles\n";
}


void printCarPointer(Car* ptrCar) {
    printCar(*ptrCar);
}

void addMileage(Car* ptrCar, int milestoadd) {
    ptrCar->Mileage += milestoadd;
}
