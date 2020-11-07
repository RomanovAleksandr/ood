#pragma once
#include "Button.h"
#include <list>
#include "ShapesManager.h"

class ButtonsManager
{
public:
	std::list<Button*> m_buttons;
	std::list<Button*> m_colorButtons;
	void CreateButtons(InputManager& inputManager, ShapesManager& shapesManager, sf::Font& m_font);
	bool ButtonsClick(sf::Vector2i clickPosition);
	void DrawButtons(sf::RenderWindow& window);
private:
	//sf::Font& m_font;
};