#include "Application.h"
#include "ShapesManager.h"
#include "InputManager.h"
#include "Button.h"
#include <iostream>

using namespace std;

Application* Application::application_ = nullptr;

Application* Application::GetInstance()
{
    if (application_ == nullptr) {
        application_ = new Application();
    }
    return application_;
}

void Application::Run()
{
    ShapesManager shapesManager;
    shapesManager.ReadShapes("input.txt");
    list<sf::Shape*> shapes = shapesManager.m_shapes;
    InputManager inputManager(shapesManager.m_shapes);

    sf::Font font;
    if (!font.loadFromFile("sansation.ttf"))
    {
        return;
    }
    Button addCircle("addCircle", font, sf::Vector2f(0, 0), sf::Vector2f(120, 40));

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
        addCircle.Draw(window);
        window.display();
    }
}