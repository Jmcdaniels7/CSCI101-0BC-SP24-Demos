#include <iostream>
#include <limits>
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

userTaskType inputUserTask();
void resetStream();
std::string outputUserTask(userTaskType theTask);

// lecture activity make a fish enum with at least 3 kinds of fish
// create an input function
// create an output function
// make a fish variable in the main and call the input and output functions
// to demonstrate that they work.

int main()
{
    int x;
    userTaskType userTask = inputUserTask();
    std::cout << std::endl;

    std::cout << userTask << std::endl; // outputs the integer that is aliased to the enum value name
    std::cout << outputUserTask(userTask) << std::endl;
    // userTaskType userTask2 = userTask + 1;

    return 0;
}

userTaskType inputUserTask()
{
    int task;
    userTaskType userTask;
    std::cout << "Choose the task you want to do on your computer from the following list:" << std::endl;
    std::cout << "1. Android Studio" << std::endl;
    std::cout << "2. Visual Studio Code" << std::endl;
    std::cout << "3. Gaming" << std::endl;
    std::cout << "4. Web Browsing with Chrome" << std::endl;
    std::cout << "5. Multiple Programming Tasks (both Android Studio and Visual Studio Code)" << std::endl;
    std::cout << "6. Zoom" << std::endl;
    std::cout << "7. Email" << std::endl;
    std::cout << "8. Create and edit documents" << std::endl;
    std::cout << "9. Everything listed above" << std::endl;
    std::cin >> task;
    while (!std::cin || task < 1 || task > 9)
    {
        if (!std::cin)
        {
            resetStream();
        }
        std::cout << "You have entered an invalid value." << std::endl;
        std::cin >> task;
    }

    switch (task)
    {
    case 1:
        userTask = ANDROID_STUDIO;
        break;
    case 2:
        userTask = VISUAL_STUDIO_CODE;
        break;
    case 3:
        userTask = GAMING;
        break;
    case 4:
        userTask = WEB;
        break;
    case 5:
        userTask = MULTIPLE_PROGRAM;
        break;
    case 6:
        userTask = ZOOM;
        break;
    case 7:
        userTask = EMAIL;
        break;
    case 8:
        userTask = DOCS;
        break;
    case 9:
        userTask = EVERYTHING;
        break;
    default:
        userTask = EVERYTHING;
    }
    return userTask;
}

void resetStream()
{
    std::cout << "You entered something that is not a number!" << std::endl;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

std::string outputUserTask(userTaskType theTask)
{
    std::string userTaskStr;
    switch (theTask)
    {
    case WEB:
        userTaskStr = "Web Browsing with Chrome";
        break;
    case ANDROID_STUDIO:
        userTaskStr = "Android Studio";
        break;
    case EVERYTHING:
        userTaskStr = "All Tasks";
        break;
    case VISUAL_STUDIO_CODE:
        userTaskStr = "Visual Studio Code";
        break;
    case DOCS:
        userTaskStr = "Create and edit documents";
        break;
    case ZOOM:
        userTaskStr = "Zoom";
        break;
    case MULTIPLE_PROGRAM:
        userTaskStr = "Multiple Programming Tasks (both Android Studio and Visual Studio Code)";
        break;
    case EMAIL:
        userTaskStr = "Email";
        break;
    case GAMING:
        userTaskStr = "Gaming";
        break;
    default:
        userTaskStr = "Unknown task";
    }
    return userTaskStr;
}
