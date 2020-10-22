#pragma once
#include <SFML/Graphics.hpp>
#include <list>

class InputManager
{
public:
	void Update(sf::Event& event);
	InputManager(std::list<sf::Shape*>& shapes) : m_shapes(shapes)
	{
	}

private:
	sf::Vector2i m_prevMousePosition;
	sf::Vector2i m_newMousePosition;
	std::list<sf::Shape*>& m_shapes;
	std::list<sf::Shape*> m_tempShapes;
	sf::Shape* dragFigure = nullptr;
};