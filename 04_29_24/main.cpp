#include <iostream>
#include <limits>
#include <iomanip>
#include <string>
#include <cctype>
#include <fstream>
#include <algorithm>

const int TOTAL_COLORS = 13;

enum carColorType
{
    SUNSET,
    CHERRY,
    PHANTOM,
    TITANIUM,
    GEAUX,
    LIGHTNING,
    FOREST,
    MIDNIGHT,
    PASSION,
    ROOT,
    STORM,
    OCEAN,
    GLACIAL
};

struct carOrderType
{
    std::string cusLastName;
    carColorType top;
    carColorType body;
    carColorType trim;
};
const carColorType colors[13] = {SUNSET,
                                 CHERRY,
                                 PHANTOM,
                                 TITANIUM,
                                 GEAUX,
                                 LIGHTNING,
                                 FOREST,
                                 MIDNIGHT,
                                 PASSION,
                                 ROOT,
                                 STORM,
                                 OCEAN,
                                 GLACIAL};
const std::string colorToStr[13] = {"Sunset Orange",
                                    "Cherry Bomb",
                                    "Phantom Black",
                                    "Titanium Silver",
                                    "Geaux Gold",
                                    "Lightning Yellow",
                                    "Forest Green",
                                    "Midnight Blue",
                                    "Passion Purple",
                                    "Root Beer",
                                    "Storm Surge",
                                    "Ocean's Rip",
                                    "Glacial White"};

carOrderType getCarOrder();
carColorType getColor(std::string part);
void displayColorMenu();
void displayCarOrder(carOrderType theOrder);
void printCarOrder(std::ostream &out, carOrderType theOrder);
void resetStream();

int main()
{
    carOrderType carOrder;
    carOrder.top = ROOT;
    carOrderType johnsOrder;
    johnsOrder.top = STORM;
    johnsOrder.cusLastName = "Brown";
    char cont;
    carOrder = johnsOrder;
    if (carOrder.top == johnsOrder.top && carOrder.body == johnsOrder.body && carOrder.trim == johnsOrder.trim)
        std::cout << "The car orders are the same." << std::endl;

    carOrder = getCarOrder();
    displayCarOrder(carOrder);
    std::cout << "Do you want to continue with your order? ";
    std::cin >> cont;
    cont = toupper(cont);
    while (cont != 'Y' && cont != 'N')
    {
        std::cout << "Please enter Y or N." << std::endl;
        std::cout << "Do you want to continue with your order? ";
        std::cin >> cont;
        cont = toupper(cont);
    }

    if (cont == 'Y')
    {
        std::ofstream fileOut;
        std::string lnameCpy = carOrder.cusLastName;
        std::transform(carOrder.cusLastName.begin(), carOrder.cusLastName.end(), lnameCpy.begin(), ::tolower);
        fileOut.open(lnameCpy + ".txt");
        printCarOrder(fileOut, carOrder);
        fileOut.close();
    }
    displayCarOrder(johnsOrder);
    // std::cout << carOrder << std::endl;
    // std::cin >> carOrder;

    return 0;
}

carOrderType getCarOrder()
{
    carOrderType theOrder;
    std::cout << "Enter the name for the order: ";
    std::cin >> std::ws;
    getline(std::cin, theOrder.cusLastName);
    theOrder.body = getColor("body");
    theOrder.top = getColor("top");
    theOrder.trim = getColor("trim");
    return theOrder;
}

carColorType getColor(std::string part)
{

    int colorInt;
    std::cout << "Please choose a color for the " << part << std::endl;
    displayColorMenu();
    std::cin >> colorInt;
    while (!std::cin || colorInt < 1 || colorInt > TOTAL_COLORS)
    {
        if (!std::cin)
        {
            resetStream();
        }
        std::cout << "Please enter the number next to the color you want to choose: ";
        std::cin >> colorInt;
    }
    return colors[colorInt - 1];
}

void resetStream()
{
    std::cout << "You entered something that is not a number." << std::endl;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void displayColorMenu()
{
    for (int i = 0; i < TOTAL_COLORS; i++)
    {
        std::cout << i + 1 << ". " << colorToStr[i] << std::endl;
    }
}

void displayCarOrder(carOrderType theOrder)
{
    // You have chosen Phantom Black for the body, Phantom Black for the top, and Titanium Silver for the trim.
    std::cout << "You have chosen " << colorToStr[theOrder.body] << " for the body, ";
    std::cout << colorToStr[theOrder.top] << " for the top, and ";
    std::cout << colorToStr[theOrder.trim] << " for the trim." << std::endl;
}

void printCarOrder(std::ostream &out, carOrderType theOrder)
{
    out << theOrder.top << std::endl;
    out << theOrder.body << std::endl;
    out << theOrder.trim << std::endl;
}