#include <iostream>
#include <cctype>
#include <cstdlib>
#include <ctime>

int main()
{
    srand(time(0));
    int numDays = 0;
    int calDay = 0;
    double sum = 0;
    int count = 0;

    std::cout << "How many days to you want to enter calorie data for? ";
    std::cin >> numDays;
    std::cout << std::endl;
    if (!std::cin)
    {
        std::cout << "You did not enter a number. The program will now exit." << std::endl;
        return 0;
    }
    if (numDays < 0)
    {
        std::cout << "The number of days must be positive. The program will now exit." << std::endl;
        return 0;
    }
    while (count < numDays)
    {
        std::cout << "Enter the number of calories for day #" << count + 1 << ": ";
        std::cin >> calDay;
        if (!std::cin)
        {
            std::cout << "You did not enter a number. The program will now exit." << std::endl;
            return 0;
        }
        if (calDay < 0)
        {
            std::cout << "The number of calories must be positive. The program will now exit." << std::endl;
            return 0;
        }
        sum += calDay; // sum = sum + calDay;
        count++;       // count = count + 1;
    }

    std::cout << "The average number of calories burned is " << sum / numDays << std::endl;

    char playGame = 'Y';
    std::cout << "Welcome to the number guessing game." << std::endl;
    std::cout << "Do you want to play? ";
    std::cin >> playGame;
    playGame = toupper(playGame);
    if (playGame != 'Y' && playGame != 'N')
    {
        std::cout << "I do not understand. I was expecting Y or N." << std::endl;
        return 0;
    }
    while (playGame != 'N')
    {

        int winner = rand() % 100 + 1;
        int guess = 0;
        bool isGuessed = false;
        while (!isGuessed)
        {
            std::cout << "Guess the number between 1 and 100: ";
            std::cin >> guess;
            if (guess == winner)
            {
                std::cout << "Congrats you guessed correctly!" << std::endl;
                isGuessed = true;
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
        playGame = toupper(playGame);
        if (playGame != 'Y' && playGame != 'N')
        {
            std::cout << "I do not understand. I was expecting Y or N." << std::endl;
            return 0;
        }
    }

    return 0;
}