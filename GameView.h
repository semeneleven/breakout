#ifndef BREAKOUT_GAMEVIEW_H
#define BREAKOUT_GAMEVIEW_H

#include "View.h"

class GameView : public View 
{
public:
    GameView(int resolutionHeight, int resolutionWidth);

    virtual void show() override;

    void redraw();
};

#endif/*BREAKOUT_GAMEVIEW_H*/