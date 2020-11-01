#pragma once
#include <SFML/Graphics.hpp>
#include <list>
#include "Shape.h"
#include "Button.h"
#include "State.h"

class InputManager
{
public:
	void Update(sf::Event& event);
	InputManager(std::list<Shape*>& shapes, std::list<Shape*>& selectedShapes, std::list<Button*>& buttons) :
		m_shapes(shapes), m_selectedShapes(selectedShapes), m_buttons(buttons)
	{
	}
	sf::Vector2f mouseOffset;
	sf::Color selectedColor;
private:
	sf::Vector2i m_prevMousePosition;
	sf::Vector2i m_newMousePosition;
	std::list<Shape*>& m_shapes;
	std::list<Shape*>& m_selectedShapes;
	std::list<Button*>& m_buttons;
	Shape* dragFigure = nullptr;
	State* state = nullptr;
	void Execute();
};