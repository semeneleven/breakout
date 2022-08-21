#include "Application.h"

#include <iostream>

#include "geometry/Geometry.h"
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

    activeView_ = std::make_unique<GameView>(30,80);

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