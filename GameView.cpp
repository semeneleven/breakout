#include "GameView.h"

#include <iostream>
#include <windows.h>

#include "core/Game.h"

#define SHIFTED 0x8000

GameView::GameView(int resolutionHeight, int resolutionWidth)
{
    resolutionHeight_ = resolutionHeight;
    resolutionWidth_ = resolutionWidth;

    Box box(Point(0,0), Point(1600,900));
    canvas_ = new Canvas(resolutionHeight_, resolutionWidth_, box);
}

void GameView::show()
{
    Game game;

    while(true)
    {
        bool exit = GetKeyState(VK_ESCAPE) & SHIFTED;
        if (exit)
            break;

        Sleep(100);

        canvas_->clear();
        game.draw(*canvas_);

        redraw();
    }
}

void GameView::redraw()
{
    system("cls");

    std::cout << canvas_->getImage();
}