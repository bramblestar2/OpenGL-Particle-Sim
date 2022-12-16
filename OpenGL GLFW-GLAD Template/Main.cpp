#include <iostream>

#include "Windows/Window2D.h"
#include "Events/Events.h"
#include "Essentials/Mouse/Mouse.h"
#include "View/View.h"

#include "Sand.h"
#include "Essentials/Clock/Clock.h"

int main()
{
    Window2D window(300, 300, "Window");
    glfwSwapInterval(1);

    Events event;
    event.setEventWindow(window.getWindow());

    View v1(Vec2f(300,300));
    window.setView(&v1);

    Cell*** a;
    a = new Cell * *[10];
    for (int i = 0; i < 10; i++)
        a[i] = new Cell * [10];

    for (int i = 0; i < 10; i++)
    {
        for (int k = 0; k < 10; k++)
        {
            a[i][k] = new Cell();
        }
    }
    delete a[2][1];
    a[2][1] = new Sand(Vec2f(10,10), Vec2i(2,1));

    Clock c;

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

        if (c.getElapsedTime() > 1)
        {
            for (int i = 0; i < 10; i++)
                for (int k = 0; k < 10; k++)
                    if (a[i][k]->getID() != (int)CellType::AIR)
                        a[i][k]->update(a, Vec2i(20/300, 20/300));

            c.reset();
        }

        window.clear(20,20,20);
        
        for (int i = 0; i < 10; i++)
            for (int k = 0; k < 10; k++)
                a[i][k]->render();

        window.display();
    }

    for (int i = 0; i < 10; i++)
    {
        for (int k = 0; k < 10; k++)
            delete a[i][k];
        delete[] a[i];
    }
    delete[] a;

    return 0;
}