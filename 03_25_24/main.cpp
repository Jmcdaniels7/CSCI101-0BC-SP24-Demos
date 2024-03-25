#include <iostream>

int main()
{
    int numPeople = 0;
    int large = 0;
    int medium = 0;
    int small = 0;
    int numSlices = 0;
    std::cout << "How many people are getting pizza? ";
    std::cin >> numPeople;
    std::cout << std::endl;
    std::cout << "A large pizza ($15) has 8 slices, how many large pizzas do you want? ";
    std::cin >> large;
    std::cout << std::endl;
    std::cout << "A medium pizza ($12) has 6 slices, how many medium pizzas do you want? ";
    std::cin >> medium;
    std::cout << std::endl;
    std::cout << "A small pizza ($9) has 4 slices, how many small pizzas do you want? ";
    std::cin >> small;
    std::cout << std::endl;

    std::cout << "You ordered " << large << " large, " << medium << " medium, and " << small << " small pizzas." << std::endl;
    numSlices = large * 8 + medium * 6 + small * 4;
    std::cout << "That is " << numSlices << " total slices, and " << numSlices / numPeople << " per person." << std::endl;

    /* You ordered 3 large, 2 medium, and 1 small pizzas.
    That is 40 total slices, and 3 per person.
    The total for the pizzas is $78.00.
    The delivery fee is $3.50. The tax amount is $6.24.
    The 20% tip (after adding the tax and delivery fee to the pizza cost) is $17.55.
    The total cost is $105.29 which is $8.77 per person. */
    return 0;
}