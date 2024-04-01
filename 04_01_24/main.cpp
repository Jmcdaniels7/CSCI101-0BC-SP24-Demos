#include <iostream>
#include <cctype>
#include <algorithm>

int main()
{
    int magicNum = 79;
    int userNum = 0;
    char yOrN;
    std::string food;

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

    std::cout << "Did you have fun? ";
    std::cin >> yOrN;
    yOrN = tolower(yOrN);
    if (yOrN == 'y')
    {
        std::cout << "Don't forget to like and subscribe." << std::endl;
    }

    std::cout << "What is your favorite food? ";
    std::cin >> std::ws;
    getline(std::cin, food);
    std::string foodCpy = food;
    std::transform(food.begin(), food.end(), foodCpy.begin(), ::toupper);
    if (foodCpy == "PIZZA")
    {
        std::cout << "I love pizza too!" << std::endl;
    }

    return 0;
}