#include <SFML/Graphics.hpp>
#include "CircleShapeDecorator.h"
#include <iostream>

int main()
{
    sf::CircleShape *circle = new sf::CircleShape(100);
    circle->setFillColor(sf::Color::Green);
    CircleShapeDecorator* decorator = new CircleShapeDecorator(*circle);

    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");

    decorator->Display(window);
    window.display();

    std::cout << decorator->GetArea() << std::endl;

    /*sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);*/

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        //window.clear();
        //window.draw(shape);
        //window.display();
    }

    return 0;
}