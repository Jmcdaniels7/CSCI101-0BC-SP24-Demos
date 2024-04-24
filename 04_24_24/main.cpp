#include <iostream>
#include <limits>
#include <cmath>

const int LIST_SIZE = 100;
void resetStream();
void binNumConvert();

int main()
{

    // standard array processing for loop
    /*  for (int i = 0; i < LIST_SIZE; i++)
     {
     } */

    return 0;
}

void resetStream()
{
    std::cout << "You entered something that is not a number." << std::endl;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void binNumConvert()
{
    int binaryDigit;
    unsigned long convertedNum = 0;
    int position = 0;
    int list[LIST_SIZE];
    int exp = 0;

    while (binaryDigit != -1)
    {
        std::cout << "Enter the " << position + 1;
        if (position == 0)
        {
            std::cout << "st";
        }
        else if (position == 1)
        {
            std::cout << "nd";
        }
        else if (position == 2)
        {
            std::cout << "rd";
        }
        else
        {
            std::cout << "th";
        }
        std::cout << " binary digit (Enter -1 to complete the conversion): ";
        std::cin >> binaryDigit;
        if (binaryDigit == -1)
        {
            break;
        }
        if (!std::cin)
        {
            resetStream();
            continue;
        }
        else if (binaryDigit != 0 && binaryDigit != 1)
        {
            std::cout << "A binary digit can only be a 1 or 0." << std::endl;
            continue;
        }

        list[position] = binaryDigit;
        position++;
    }
    for (int i = position - 1; i >= 0; i--)
    {
        convertedNum = convertedNum + list[i] * pow(2, exp);
        exp++;
    }
    for (int i = 0; i < position; i++)
    {
        std::cout << list[i];
    }
    std::cout << " converted to decimal is " << convertedNum << std::endl;
}
