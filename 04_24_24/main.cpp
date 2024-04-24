#include <iostream>
#include <limits>
#include <cmath>
#include <string>
enum userTaskType
{
    ANDROID_STUDIO,
    VISUAL_STUDIO_CODE,
    GAMING,
    WEB,
    MULTIPLE_PROGRAM,
    ZOOM,
    EMAIL,
    DOCS,
    EVERYTHING
};
const int LIST_SIZE = 10;
const int NUM_TASKS = 9;
const userTaskType tasks[NUM_TASKS] = {ANDROID_STUDIO,
                                       VISUAL_STUDIO_CODE,
                                       GAMING,
                                       WEB,
                                       MULTIPLE_PROGRAM,
                                       ZOOM,
                                       EMAIL,
                                       DOCS,
                                       EVERYTHING};
const std::string taskToStr[NUM_TASKS] = {"Android Studio",
                                          "Visual Studio Code",
                                          "Gaming",
                                          "Web Browsing with Chrome",
                                          "Multiple Programming Tasks (both Android Studio and Visual Studio Code)",
                                          "Zoom",
                                          "Email"
                                          "Create and edit documents",
                                          "All Tasks"};

void resetStream();
void binNumConvert();
// write a loop using the list in main that finds the sum and average of the numbers
void sortList(int list[], int listSize);
void findLargest(int list[], int &largestPos, int listSize);
void printList(int list[], int listSize);

int main()
{
    int list[LIST_SIZE];
    int numElem = 0;
    // standard array processing for loop
    for (int i = 0; i < LIST_SIZE; i++)
    {
        list[i] = 0;
    }
    for (int i = 0; i < LIST_SIZE; i++)
    {
        std::cout << "Enter a number: ";
        std::cin >> list[i];
        while (!std::cin)
        {
            resetStream();
            std::cout << "Enter a number: ";
            std::cin >> list[i];
        }
        numElem++;
    }
    printList(list, numElem);

    int largestPos;
    findLargest(list, largestPos, numElem);

    std::cout << "The largest number is " << list[largestPos] << " at position " << largestPos << std::endl;
    std::cout << list << std::endl;

    sortList(list, numElem);
    printList(list, numElem);

    userTaskType userTask = ANDROID_STUDIO;
    std::cout << userTask << " " << taskToStr[userTask] << std::endl;

    return 0;
}

void resetStream()
{
    std::cout << "You entered something that is not a number." << std::endl;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void binNumConvert()
{
    int binaryDigit;
    unsigned long convertedNum = 0;
    int position = 0;
    int list[LIST_SIZE];
    int exp = 0;

    while (binaryDigit != -1)
    {
        std::cout << "Enter the " << position + 1;
        if (position == 0)
        {
            std::cout << "st";
        }
        else if (position == 1)
        {
            std::cout << "nd";
        }
        else if (position == 2)
        {
            std::cout << "rd";
        }
        else
        {
            std::cout << "th";
        }
        std::cout << " binary digit (Enter -1 to complete the conversion): ";
        std::cin >> binaryDigit;
        if (binaryDigit == -1)
        {
            break;
        }
        if (!std::cin)
        {
            resetStream();
            continue;
        }
        else if (binaryDigit != 0 && binaryDigit != 1)
        {
            std::cout << "A binary digit can only be a 1 or 0." << std::endl;
            continue;
        }

        list[position] = binaryDigit;
        position++;
    }
    for (int i = position - 1; i >= 0; i--)
    {
        convertedNum = convertedNum + list[i] * pow(2, exp);
        exp++;
    }
    for (int i = 0; i < position; i++)
    {
        std::cout << list[i];
    }
    std::cout << " converted to decimal is " << convertedNum << std::endl;
}

void sortList(int list[], int listSize)
{
    int largestPos;
    for (int unsorted = listSize - 1; unsorted > 0; unsorted--)
    {
        findLargest(list, largestPos, unsorted + 1);
        int temp = list[unsorted];
        list[unsorted] = list[largestPos];
        list[largestPos] = temp;
    }
}

void findLargest(int list[], int &largestPos, int listSize)
{
    largestPos = 0;
    for (int i = 1; i < listSize; i++)
    {
        if (list[largestPos] < list[i])
        {
            largestPos = i;
        }
    }
}

void printList(int list[], int listSize)
{
    for (int i = 0; i < listSize; i++)
    {
        std::cout << list[i] << std::endl;
    }
}
