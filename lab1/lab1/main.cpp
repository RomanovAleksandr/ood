#include <SFML/Graphics.hpp>
#include <iostream>
#include "BaseShapeDecorator.h"
#include "CircleShapeDecorator.h"
#include "RectangleShapeDecorator.h"
#include "ShapeProcess.h"
#include <vector>

using namespace std;

int main()
{
    vector<sf::Shape*> shapes;
    ReadShapes(shapes, "input.txt");
    SaveShapes(shapes, "output.txt");

    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");

    for (sf::Shape* shape : shapes)
    {
        window.draw(*shape);
    }

    window.display();

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