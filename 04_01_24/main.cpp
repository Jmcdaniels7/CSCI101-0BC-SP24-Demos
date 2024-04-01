#include <iostream>

int main()
{
    int magicNum = 79;
    int userNum = 0;

    std::cout << "Enter a number between 1 and 100: ";
    std::cin >> userNum;

    if (userNum <= magicNum)
    {
        std::cout << "My number is higher!!! I win!!" << std::endl;
    }
    else
    {
        std::cout << "Good guess!" << std::endl;
    }

    std::cout << "Thanks for playing!" << std::endl;

    return 0;
}