#include "GameView.h"

#include <iostream>
#include <windows.h>

#define SHIFTED 0x8000

GameView::GameView(int resolutionHeight, int resolutionWidth)
{
    resolutionHeight_ = resolutionHeight;
    resolutionWidth_ = resolutionWidth;
}

void GameView::show()
{
    while(true)
    {
        bool exit = GetKeyState(VK_ESCAPE) & SHIFTED;
        if (exit)
            break;

        Sleep(100);

        redraw();
    }
}

void GameView::redraw()
{
    system("cls");

    Box box(Point(0,0), Point(1600,900));
    Canvas canvas(resolutionHeight_, resolutionWidth_, box);
    
    canvas.drawLine(Point(0,0),      Point(0,900),    (char)179);
    canvas.drawLine(Point(0,900),    Point(1600,900), (char)196);
    canvas.drawLine(Point(1600,900), Point(1600,0),   (char)179);

    canvas.drawPoint(Point(0,900), (char)218);
    canvas.drawPoint(Point(1600,900), (char)191);

    std::cout << canvas.getImage();
}