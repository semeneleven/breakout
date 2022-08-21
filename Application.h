#ifndef APPLICATION_H
#define APPLICATION_H

#include <memory>

#include "View.h"

class Application
{
public:
    static Application* getInstance();
    void run();

    Application(Application&) = delete;
    void operator=(Application&) = delete;

    void changeView(std::unique_ptr<View> view);
    void exit();

protected:
    Application() {
        running_ = false;  
    };
    ~Application() {};

    bool running_;
    std::unique_ptr<View> activeView_;

    static Application* application_;
};

#endif/*APPLICATION_H*/