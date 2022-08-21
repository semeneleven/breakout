#ifndef BREAKOUT_VIEW_H
#define BREAKOUT_VIEW_H

#include "visualization/Canvas.h"

class View
{
public:
    virtual void show() = 0;

protected:
    int resolutionHeight_;
    int resolutionWidth_;
};

#endif/*BREAKOUT_VIEW_H*/