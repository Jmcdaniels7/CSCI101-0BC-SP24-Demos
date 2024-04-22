#include <iostream>
#include <cmath>
#include <string>
#include <cctype>
#include <limits>

int getPositiveInt(std::string prompt);
char getByteUnit();
long calculateMemoryCells(int memSize, char unit);
int secret(int x);
void resetStream();
void memInByteUnits(int mar, int &memSize, char &unit);

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
    memInByteUnits(mar, memSize, byteUnit);
    if (byteUnit == 'B')
    {
        memCells = exp2(mar);
        std::cout << "The maximum memory cells for a " << mar << " bit mar is " << memCells << std::endl;
    }
    else
    {
        std::cout << "The maximum amount of memory for a " << mar << " bit mar is " << memSize << byteUnit << "B" << std::endl;
    }
    int x = secret(2);
    x = secret(-63);
    x = secret(6);
    return 0;
}

int getPositiveInt(std::string prompt)
{
    int num;
    std::cout << prompt;
    std::cin >> num;
    std::cout << std::endl;

    while (!std::cin || num <= 0)
    {
        if (!std::cin)
        {
            resetStream();
        }
        std::cout << "Please enter a number greater than 0." << std::endl;
        std::cout << prompt;
        std::cin >> num;
        std::cout << std::endl;
    }

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

int secret(int x)
{
    if (x > 5)
        return 2 * x;
    return x;
}

void resetStream()
{
    std::cout << "You did not enter a number. " << std::endl;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void memInByteUnits(int mar, int &memSize, char &unit)
{
    if (mar >= 40)
    {
        mar = mar - 40;
        unit = 'T';
    }
    else if (mar >= 30)
    {
        mar = mar - 30;
        unit = 'G';
    }
    else if (mar >= 20)
    {
        mar = mar - 20;
        unit = 'M';
    }
    else if (mar >= 10)
    {
        mar = mar - 10;
        unit = 'K';
    }
    else
    {
        unit = 'B';
    }
    memSize = pow(2, mar);
}