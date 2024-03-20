#include <iostream>
#include <climits>

int main()
{
    int x;
    int y;

    double decimal;
    x = 5;
    y = 2;
    int answer = x / y;

    std::cout << "5/2 = " << 5 / 2.0 << std::endl;
    std::cout << "10 = " << 1 * 2 + 0 * 1 << std::endl;

    std::cout << "Enter a decimal number: ";
    std::cin >> decimal;
    std::cout << std::endl;

    std::cout << decimal << std::endl;
    std::cout << "decimal / 2 = " << decimal / 2 << std::endl;

    return 0;
}