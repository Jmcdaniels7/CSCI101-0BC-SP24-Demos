#include <iostream>
#include <cctype>
#include <algorithm>

// lecture activity create a flow diagram for 1 of the two programming assignments this week. Use draw.io or similar tool use rectangles for sequential operations and diamonds for conditionals. export as image or pdf

int main()
{
    int magicNum = 79;
    int userNum = 0;
    char yOrN;
    std::string food;

    std::cout << "Enter a number between 1 and 100: ";
    std::cin >> userNum;
    if (!std::cin)
    {
        std::cout << "You entered something that is not a number" << std::endl;
        std::cout << "The program will now exit." << std::endl;
        return 0;
    }
    else if (userNum > 100)
    {
        std::cout << "You entered a number that is not between 1 and 100." << std::endl;
        std::cout << "You will be given a value of 1 for being a cheater!" << std::endl;
        userNum = 1;
    }

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
    if (yOrN == 'y' || yOrN == 'n')
    {
        if (yOrN == 'y')
        {
            std::cout << "Don't forget to like and subscribe." << std::endl;
        }
        else
        {
            std::cout << "That's ok maybe next time." << std::endl;
        }
    }
    else
    {
        std::cout << "You entered something I don't understand." << std::endl;
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
    else
    {
        std::cout << "My favorite food is pizza!" << std::endl;
    }

    bool x = 1.0 == 3.0 / 7.0 + 2.0 / 7.0 + 2.0 / 7.0;
    std::cout << 3.0 / 7.0 + 2.0 / 7.0 + 2.0 / 7.0 << std::endl;

    return 0;
}