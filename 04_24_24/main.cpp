#include <iostream>
#include <limits>
#include <cmath>
#include <string>

const int LIST_SIZE = 100;
void resetStream();

int main()
{
    int binaryDigit;
    unsigned long convertedNum = 0;
    int position = 0;
    int list[LIST_SIZE];
    std::string binNum;
    std::cout << "Enter a binary number: ";
    std::cin >> binNum;
    std::cout << std::endl;
    position = binNum.size() - 1;

    for (int i = 0; i < binNum.size(); i++)
    {
        if (binNum[i] != '0' && binNum[i] != '1')
        {
            std::cout << "A binary digit can only be a 1 or 0." << std::endl;
            break;
        }
        else
        {
            list[position] = binNum[i] - '0';
            position--;
        }
    }
    if (position == -1)
    {
        for (int i = 0; i < binNum.size(); i++)
        {
            convertedNum = convertedNum + list[i] * pow(2, i);
        }
    }

    std::cout << binNum << " converted to decimal is " << convertedNum << std::endl;

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
