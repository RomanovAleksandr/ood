#pragma once
#include "Shape.h"
#include "Button.h"
#include <SFML/Graphics.hpp>
#include <list>
#include "InputManagerState.h"
#include "ShapesManager.h"
#include "ButtonsManager.h"

class InputManager
{
public:
	void Update(sf::Event& event);
	InputManager(ShapesManager& shapesManager, ButtonsManager& buttonsManager);
	sf::Vector2f mouseOffset;
	sf::Color selectedColor;
	void TransitionTo(InputManagerState* state);
	ShapesManager& m_shapesManager;
private:
	sf::Vector2i m_prevMousePosition;
	sf::Vector2i m_newMousePosition;
	InputManagerState* m_state;
	ButtonsManager& m_buttonsManager;
};