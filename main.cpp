#include <iostream>

#include "Application.h"

int main(int, char**) {
    Application* application = Application::getInstance();

    application->run();

    return 0;
}
