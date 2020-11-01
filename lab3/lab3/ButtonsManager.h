#pragma once
#include "Button.h"
#include <list>

class ButtonsManager
{
public:
	ButtonsManager(std::list<Shape*>& shapes, std::list<Shape*>& selectedShapes, sf::Font& font) : 
		m_shapes(shapes), m_selectedShapes(selectedShapes), m_font(font)
	{
		CreateButtons();
	}
	std::list<Button*> m_buttons;
private:
	void CreateButtons()
	{
		Button* addCircle = new Button("addCircle", m_font, sf::Vector2f(0, 0), sf::Vector2f(120, 40));
		addCircle->SetCommand(new AddNewShape("circle", m_shapes));
		m_buttons.push_back(addCircle);
		Button* changeColor = new Button("changeColorBlue", m_font, sf::Vector2f(0, 50), sf::Vector2f(120, 40));
		changeColor->SetCommand(new ChangeShapeColor(sf::Color::Blue, m_selectedShapes));
		m_buttons.push_back(changeColor);
	}
	std::list<Shape*>& m_shapes;
	std::list<Shape*>& m_selectedShapes;
	sf::Font& m_font;
};