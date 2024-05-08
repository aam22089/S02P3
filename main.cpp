#include <SFML/Graphics.hpp>
#include "Grid.hpp"
using namespace sf;

int numCells = 70;
int width = 700;
int height = 700;

int main()
{
    bool play = false;
    RenderWindow window(VideoMode(width, height), "SFML works!");
    window.setFramerateLimit(60);
    Grid grid(numCells, width, height);
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();

            if (event.type == Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == Mouse::Left)
                {
                    int x = event.mouseButton.x;
                    int y = event.mouseButton.y;
                    grid.toggle(x, y);
                }
            }
        }

        grid.update();
        grid.drawTo(window);
        window.display();
    }

    return 0;
}
