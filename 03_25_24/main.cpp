#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <fstream>

int main()
{
    std::cout << std::setprecision(2) << std::fixed << std::showpoint;
    int numPeople = 0;
    int large = 0;
    int medium = 0;
    int small = 0;
    int numSlices = 0;
    std::string orderName;
    char changes;
    double total = 0;
    double tax = 0;
    double tip = 0;
    const double DELIVERY_FEE = 3.5;

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

    std::cout << "What is the name for the order? ";
    std::cin >> std::ws;
    getline(std::cin, orderName);
    std::cout << std::endl;

    std::cout << "Enter a character to continue: ";
    std::cin >> std::ws;
    std::cin.get(changes);
    std::cout << std::endl;

    total = large * 15 + medium * 12 + small * 9;
    tax = total * .08;
    tip = (total + tax + DELIVERY_FEE) * .2;
    std::cout << "The total for the pizzas is $" << total << "." << std::endl;
    std::cout << "The delivery fee is $" << DELIVERY_FEE << ". The tax amount is $" << tax << "." << std::endl;
    std::cout << "The 20% tip (after adding the tax and delivery fee to the pizza cost) is $" << tip << "." << std::endl;
    std::cout << "The total cost is $" << total + tax + DELIVERY_FEE + tip << " which is $" << (total + tax + DELIVERY_FEE + tip) / numPeople << " per person." << std::endl;
    // std::cout << exp(2) << std::endl;

    /* You ordered 3 large, 2 medium, and 1 small pizzas.
    That is 40 total slices, and 3 per person.
    The total for the pizzas is $78.00.
    The delivery fee is $3.50. The tax amount is $6.24.
    The 20% tip (after adding the tax and delivery fee to the pizza cost) is $17.55.
    The total cost is $105.29 which is $8.77 per person. */

    std::ifstream order;
    order.open("order.txt");

    char prod;
    int quantity;

    order >> prod >> quantity;
    std::cout << "+" << std::setw(5) << std::setfill('-') << "-"
              << "+" << std::setw(10) << "-"
              << "+" << std::endl;
    std::cout << "|" << std::setw(5) << std::setfill(' ') << std::left << "Prod"
              << "|" << std::setw(10) << "Quantity"
              << "|" << std::endl;
    std::cout << "+" << std::setw(5) << std::setfill('-') << "-"
              << "+" << std::setw(10) << "-"
              << "+" << std::endl;
    std::cout << "|" << std::setw(5) << std::setfill(' ') << std::left << prod
              << "|" << std::setw(10) << quantity
              << "|" << std::endl;
    std::cout << "+" << std::setw(5) << std::setfill('-') << "-"
              << "+" << std::setw(10) << "-"
              << "+" << std::endl;

    order >> prod >> quantity;
    std::cout << "|" << std::setw(5) << std::setfill(' ') << std::left << prod
              << "|" << std::setw(10) << quantity
              << "|" << std::endl;
    std::cout << "+" << std::setw(5) << std::setfill('-') << "-"
              << "+" << std::setw(10) << "-"
              << "+" << std::endl;

    order >> prod >> quantity;
    std::cout << "|" << std::setw(5) << std::setfill(' ') << std::left << prod
              << "|" << std::setw(10) << quantity
              << "|" << std::endl;
    std::cout << "+" << std::setw(5) << std::setfill('-') << "-"
              << "+" << std::setw(10) << "-"
              << "+" << std::endl;

    order >> prod >> quantity;
    std::cout << "|" << std::setw(5) << std::setfill(' ') << std::left << prod
              << "|" << std::setw(10) << quantity
              << "|" << std::endl;
    std::cout << "+" << std::setw(5) << std::setfill('-') << "-"
              << "+" << std::setw(10) << "-"
              << "+" << std::endl;

    order.seekg(0);

    std::ofstream myOutputFile;
    myOutputFile.open("formatOrder.txt");

    // lecture activity take the code from lines 74 - 114 change it to use myOuputFile instead of cout.

    // NOTE: string concatenation str1 + " " + str2

    return 0;
}