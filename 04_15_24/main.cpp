#include <iostream>
#include <cmath>

int main()
{
    long memCells;
    int mar;
    std::cout << "Enter the amount of memory in bytes: ";
    std::cin >> memCells;
    std::cout << std::endl;

    // input validation

    mar = ceil(log2(memCells));
    std::cout << "The minimum memory address size for " << memCells << " bytes of memory is " << mar << " bits." << std::endl;

    std::cout << "What is the size of the mar in bits? ";
    std::cin >> mar;
    std::cout << std::endl;

    // input validation

    memCells = exp2(mar);
    std::cout << "The maximum memory cells for a " << mar << " bit mar is " << memCells << std::endl;
    return 0;
}