#include <iostream>

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

int main()
{
    int x;
    userTaskType userTask = EVERYTHING;
    std::cout << "Enter the task: ";

    std::cout << std::endl;
    std::cout << userTask << std::endl;
    // userTaskType userTask2 = userTask + 1;

    return 0;
}
