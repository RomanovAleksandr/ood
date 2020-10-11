#include <SFML/Graphics.hpp>
#include <iostream>
#include "BaseShapeDecorator.h"
#include "CircleShapeDecorator.h"
#include "RectangleShapeDecorator.h"
#include "ShapeProcess.h"
#include "Composite.h"
#include <vector>

using namespace std;

int main()
{
    vector<sf::Shape*> shapes;
    ReadShapes(shapes, "input.txt");
    SaveShapes(shapes, "output.txt");

    sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");

    for (sf::Shape* shape : shapes)
    {
        window.draw(*shape);
    }

    window.display();

    bool shiftPressed = false;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::LShift)
                {
                    shiftPressed = true;
                }
            }
            if (event.type == sf::Event::KeyReleased)
            {
                if (event.key.code == sf::Keyboard::LShift)
                {
                    shiftPressed = false;
                }
            }
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left && shiftPressed)
                {
                    cout << "1\n";
                }
            }
        }

        /*window.clear();
        window.display();*/
    }

    return 0;
}