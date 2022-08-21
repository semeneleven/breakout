#ifndef BREAKOUT_GAME_H
#define BREAKOUT_GAME_H

#include "../visualization/Canvas.h"

class Game
{
public:
    Game();

    void start();

    int getScore();
    int getLive();

    void draw(Canvas& canvas);

private:
    int score_;
    int live_;
};

#endif/*BREAKOUT_GAME_H*/