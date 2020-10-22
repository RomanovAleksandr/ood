#include <SFML/Graphics.hpp>
#include <iostream>
#include "ShapesManager.h"
#include "InputManager.h"
#include <list>

using namespace std;

int main()
{
    ShapesManager shapesManager;
    shapesManager.ReadShapes("input.txt");
    list<sf::Shape*> shapes = shapesManager.m_shapes;
    InputManager inputManager(shapesManager.m_shapes);

    sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");

    window.display();

    bool shiftPressed = false;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            inputManager.Update(event);
        }

        window.clear();
        for (sf::Shape* shape : shapes)
        {
            window.draw(*shape);
        }
        window.display();
    }

    return 0;
}