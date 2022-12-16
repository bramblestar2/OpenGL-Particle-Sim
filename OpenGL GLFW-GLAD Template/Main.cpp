#include <iostream>

#include "Windows/Window2D.h"
#include "Events/Events.h"
#include "Essentials/Mouse/Mouse.h"
#include "View/View.h"

#include "Sand.h"

int main()
{
    Window2D window(300, 300, "Window");
    glfwSwapInterval(1);

    Events event;
    event.setEventWindow(window.getWindow());

    View v1(Vec2f(300,300));
    window.setView(&v1);

    Sand a;
    a.setSize({ 10,10 });
    a.setCellPosition({ 1,0 });

    while (window.isOpen())
    {
        //EVENTS
        while (event.pollEvents())
        {
            switch (event.type())
            {
            case EventTypes::Key:
                if (event.event().keys.action == GLFW_PRESS)
                {
                    switch (event.event().keys.key)
                    {
                    case GLFW_KEY_ESCAPE:
                        window.close();
                        break;
                    }
                }
                break;
            }
        }

        window.clear(20,20,20);
        a.render();
        window.display();
    }

    return 0;
}