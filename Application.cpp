#include "Application.h"

#include <iostream>
#include <windows.h>

#include "geometry/Box.h"
#include "visualization/Canvas.h"
#include "GameView.h"

Application* Application::application_ = nullptr;

Application* Application::getInstance()
{
    if (application_ == nullptr)
        application_ = new Application();
    
    return application_;
}

void Application::run()
{
    if (running_)
        return;

    running_ = true;

    setWindowSize(31, 121);

    activeView_ = std::make_unique<GameView>(30,120);

    while(running_)
        activeView_->show();
}

void Application::changeView(std::unique_ptr<View> view)
{
    activeView_ = std::move(view);
}

void Application::exit()
{
    running_ = false;
}

void Application::setWindowSize(int height, int width)
{
    _COORD coord; 
    coord.X = width; 
    coord.Y = height; 

    _SMALL_RECT Rect; 
    Rect.Top = 0; 
    Rect.Left = 0; 
    Rect.Bottom = height - 1; 
    Rect.Right = width - 1; 

    HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);      // Get Handle 
    SetConsoleScreenBufferSize(Handle, coord);            // Set Buffer Size 
    SetConsoleWindowInfo(Handle, TRUE, &Rect);            // Set Window Size 

    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(Handle, &cursorInfo);
    cursorInfo.bVisible = false; // set the cursor visibility
    SetConsoleCursorInfo(Handle, &cursorInfo);
}