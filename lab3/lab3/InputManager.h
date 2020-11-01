#pragma once
#include "Shape.h"
#include "Button.h"
#include "InputState.h"
#include <SFML/Graphics.hpp>
#include <list>

class InputManager
{
public:
	void Update(sf::Event& event);
	InputManager(std::list<Shape*>& shapes, std::list<Shape*>& selectedShapes, std::list<Button*>& buttons);
	void ChangeState(InputState* state);
	sf::Vector2f mouseOffset;
	sf::Color selectedColor;
	Shape* selectedShape = nullptr;
private:
	sf::Vector2i m_prevMousePosition;
	sf::Vector2i m_newMousePosition;
	std::list<Shape*>& m_shapes;
	std::list<Shape*>& m_selectedShapes;
	std::list<Button*>& m_buttons;
	Shape* dragFigure = nullptr;
	InputState* m_state = nullptr;
};