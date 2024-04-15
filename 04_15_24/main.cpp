#include <iostream>
#include <cmath>
#include <string>
#include <cctype>

int getPositiveInt(std::string prompt);
char getByteUnit();
long calculateMemoryCells(int memSize, char unit);

int main()
{
    long memCells;
    int mar;
    int memSize = getPositiveInt("Enter the memory size: ");
    char byteUnit = getByteUnit();
    memCells = calculateMemoryCells(memSize, byteUnit);

    // input validation

    mar = ceil(log2(memCells));
    std::cout << "The minimum memory address size for " << memCells << " bytes of memory is " << mar << " bits." << std::endl;

    mar = getPositiveInt("What is the size of the mar in bits? ");

    memCells = exp2(mar);
    std::cout << "The maximum memory cells for a " << mar << " bit mar is " << memCells << std::endl;
    return 0;
}

int getPositiveInt(std::string prompt)
{
    int num;
    std::cout << prompt;
    std::cin >> num;
    std::cout << std::endl;

    // input validation

    return num;
}

char getByteUnit()
{
    char unit;
    std::cout << "Enter the byte units for memory (B for bytes, K for KB, M for MB, G for GB, T for TB): ";
    std::cin >> unit;
    unit = toupper(unit);

    while (unit != 'B' && unit != 'K' && unit != 'M' && unit != 'G' && unit != 'T')
    {
        std::cout << "That is not a valid byte unit." << std::endl;
        std::cout << "Enter the byte units for memory (B for bytes, K for KB, M for MB, G for GB, T for TB): ";
        std::cin >> unit;
        unit = toupper(unit);
    }
    return unit;
}

long calculateMemoryCells(int memSize, char unit)
{
    int exponent = 0;
    unit = toupper(unit);
    switch (unit)
    {
    case 'B':
        exponent = 0;
        break;
    case 'K':
        exponent = 10;
        break;
    case 'M':
        exponent = 20;
        break;
    case 'G':
        exponent = 30;
        break;
    case 'T':
        exponent = 40;
        break;
    }
    long memCells = memSize * pow(2, exponent);

    return memCells;
}