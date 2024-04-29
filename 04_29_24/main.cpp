#include <iostream>
#include <limits>
#include <iomanip>
#include <string>

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
int main()
{
    carOrderType carOrder;
    carOrder.top = ROOT;
    carOrderType johnsOrder;
    johnsOrder.top = STORM;
    johnsOrder.cusLastName = "Brown";

    carOrder = johnsOrder;
    if (carOrder.top == johnsOrder.top && carOrder.body == johnsOrder.body && carOrder.trim == johnsOrder.trim)
        std::cout << "The car orders are the same." << std::endl;

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
