#include <iostream>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <fstream>
#include <iomanip>

int main()
{
    srand(time(0));
    int numDays = 0;
    int calDay = 0;
    double sum = 0;
    int count = 0;
    int topCal = 0, nextTopCal = 0, lowCal = 0;

    /*  std::cout << "How many days to you want to enter calorie data for? ";
     std::cin >> numDays;
     std::cout << std::endl; */
    do
    {

        if (!std::cin)
        {
            std::cout << "You did not enter a number. " << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else if (numDays < 3)
        {
            std::cout << "The number of days must be positive." << std::endl;
        }
        std::cout << "How many days to you want to enter calorie data for? ";
        std::cin >> numDays;
        std::cout << std::endl;
    } while (!std::cin || numDays < 3);

    /* while (count < numDays)
    { */
    for (count = 0; count < numDays; count++)
    {
        std::cout << "Enter the number of calories for day #" << count + 1 << ": ";
        std::cin >> calDay;
        while (!std::cin || calDay < 0)
        {
            if (!std::cin)
            {
                std::cout << "You did not enter a number. " << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            else
            {
                std::cout << "The number of calories must be positive. " << std::endl;
            }
            std::cout << "Enter the number of calories for day #" << count + 1 << ": ";
            std::cin >> calDay;
        }
        sum += calDay; // sum = sum + calDay;
        if (calDay > topCal)
        {
            lowCal = nextTopCal;
            nextTopCal = topCal;
            topCal = calDay;
        }
        else if (calDay > nextTopCal)
        {
            lowCal = nextTopCal;
            nextTopCal = calDay;
        }
        else if (calDay > lowCal)
        {
            lowCal = calDay;
        }
        // count++;       // count = count + 1;
    }

    std::cout << "The average number of calories burned is " << sum / numDays << std::endl;

    char playGame = 'Y';
    std::cout << "Welcome to the number guessing game." << std::endl;
    std::cout << "Do you want to play? ";
    std::cin >> playGame;
    playGame = toupper(playGame);
    while (playGame != 'Y' && playGame != 'N')
    {
        std::cout << "I do not understand. I was expecting Y or N." << std::endl;
        std::cout << "Do you want to play? ";
        std::cin >> playGame;
        playGame = toupper(playGame);
    }
    while (playGame != 'N')
    {

        int winner = rand() % 100 + 1;
        int guess = 0;
        bool isGuessed = false;
        while (guess != winner)
        {
            std::cout << "Guess the number between 1 and 100: ";
            std::cin >> guess;
            while (!std::cin || guess < 1 || guess > 100)
            {
                if (!std::cin)
                {
                    std::cout << "You did not enter a number. " << std::endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                else
                {
                    std::cout << "You need to guess a number between 1 and 100." << std::endl;
                }
                std::cout << "Guess the number between 1 and 100: ";
                std::cin >> guess;
            }
            if (guess == winner)
            {
                std::cout << "Congrats you guessed correctly!" << std::endl;
                isGuessed = true;
                continue;
            }
            else if (guess < winner)
            {
                std::cout << "Your guess is too low." << std::endl;
            }
            else
            {
                std::cout << "Your guess is too high." << std::endl;
            }
        }
        std::cout << "Do you want to play again? ";
        std::cin >> playGame;
        if (playGame == 'N' || playGame == 'Y')
            continue;
        playGame = toupper(playGame);
        while (playGame != 'Y' && playGame != 'N')
        {
            std::cout << "I do not understand. I was expecting Y or N." << std::endl;
            std::cout << "Do you want to play? ";
            std::cin >> playGame;
            playGame = toupper(playGame);
        }
    }

    std::ifstream order;
    order.open("order.txt");

    char prod;
    int quantity;

    std::cout << "+" << std::setw(5) << std::setfill('-') << "-"
              << "+" << std::setw(10) << "-"
              << "+" << std::endl;
    std::cout << "|" << std::setw(5) << std::setfill(' ') << std::left << "Prod"
              << "|" << std::setw(10) << "Quantity"
              << "|" << std::endl;
    while (!order.eof())
    {
        order >> prod >> quantity;
        std::cout << "+" << std::setw(5) << std::setfill('-') << "-"
                  << "+" << std::setw(10) << "-"
                  << "+" << std::endl;
        std::cout << "|" << std::setw(5) << std::setfill(' ') << std::left << prod
                  << "|" << std::setw(10) << quantity
                  << "|" << std::endl;
    }
    std::cout << "+" << std::setw(5) << std::setfill('-') << "-"
              << "+" << std::setw(10) << "-"
              << "+" << std::endl;

    return 0;
}