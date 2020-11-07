#include "Application.h"
#include <SFML/Graphics.hpp>
#include "ShapesManager.h"
#include "InputManager.h"
#include "ButtonsManager.h"

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
    sf::Font font;
    if (!font.loadFromFile("sansation.ttf"))
    {
        return;
    }
    ButtonsManager buttonsManager;
    InputManager inputManager(shapesManager, buttonsManager);
    buttonsManager.CreateButtons(inputManager, shapesManager, font);
    sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");
    
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
        shapesManager.DrawShapes(window);
        buttonsManager.DrawButtons(window);
        window.display();
    }
}