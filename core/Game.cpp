#include "Game.h"

Game::Game()
{
    score_ = 0;
    live_ = 3;
}

int Game::getScore()
{
    return score_;
}

int Game::getLive()
{
    return live_;
}

void Game::draw(Canvas& canvas)
{
    canvas.drawLine(Line(Point(0,0),      Point(0,900)   ), (char)179);
    canvas.drawLine(Line(Point(0,900),    Point(1600,900)), (char)196);
    canvas.drawLine(Line(Point(1600,900), Point(1600,0)  ), (char)179);

    canvas.drawPoint(Point(0,900), (char)218);
    canvas.drawPoint(Point(1600,900), (char)191);
}