#include "ButtonsManager.h"
#include "ShapesManager.h"

//ButtonsManager::ButtonsManager(sf::Font& font) : m_font(font), 
//{
//}
void ButtonsManager::CreateButtons(InputManager& inputManager, ShapesManager& shapesManager, sf::Font& m_font)
{
	sf::Color grey(169, 169, 169);
	sf::Color redColor(255, 169, 169);
	sf::Color greenColor(169, 255, 169);
	sf::Color blueColor(169, 169, 255);
	Button* addCircle = new Button("addCircle", m_font, grey, sf::Vector2f(0, 0), sf::Vector2f(120, 40));
	addCircle->SetCommand(new AddShapeCommand(shapesManager.m_shapes, Shapes::Circle));
	m_buttons.push_back(addCircle);
	Button* addRectangle = new Button("addRectangle", m_font, grey, sf::Vector2f(0, 300), sf::Vector2f(120, 40));
	addRectangle->SetCommand(new AddShapeCommand(shapesManager.m_shapes, Shapes::Rectangle));
	m_buttons.push_back(addRectangle);
	Button* addTriangle = new Button("addTriangle", m_font, grey, sf::Vector2f(0, 350), sf::Vector2f(120, 40));
	addTriangle->SetCommand(new AddShapeCommand(shapesManager.m_shapes, Shapes::Triangle));
	m_buttons.push_back(addTriangle);
	Button* changeColor = new Button("changeColor", m_font, grey, sf::Vector2f(0, 50), sf::Vector2f(120, 40));
	changeColor->SetCommand(new ChangeInputManagerStateCommand(inputManager, InputManagerStates::changeShapeColor));
	m_buttons.push_back(changeColor);
	Button* dragAndDrop = new Button("dragAndDrop", m_font, grey, sf::Vector2f(0, 100), sf::Vector2f(120, 40));
	dragAndDrop->SetCommand(new ChangeInputManagerStateCommand(inputManager, InputManagerStates::dragAndDrop));
	m_buttons.push_back(dragAndDrop);
	Button* red = new Button("red", m_font, redColor, sf::Vector2f(130, 0), sf::Vector2f(120, 40));
	red->SetCommand(new SetSelectedColor(inputManager, sf::Color::Red));
	m_colorButtons.push_back(red);
	Button* green = new Button("green", m_font, greenColor, sf::Vector2f(260, 0), sf::Vector2f(120, 40));
	green->SetCommand(new SetSelectedColor(inputManager, sf::Color::Green));
	m_colorButtons.push_back(green);
	Button* blue = new Button("blue", m_font, blueColor, sf::Vector2f(390, 0), sf::Vector2f(120, 40));
	blue->SetCommand(new SetSelectedColor(inputManager, sf::Color::Blue));
	m_colorButtons.push_back(blue);
	Button* setThickness5 = new Button("setThickness5", m_font, grey, sf::Vector2f(0, 150), sf::Vector2f(120, 40));
	setThickness5->SetCommand(new ChangeOtlineThicknessCommand(inputManager, 5));
	m_buttons.push_back(setThickness5);
	Button* setThickness10 = new Button("setThickness10", m_font, grey, sf::Vector2f(0, 200), sf::Vector2f(120, 40));
	setThickness10->SetCommand(new ChangeOtlineThicknessCommand(inputManager, 10));
	m_buttons.push_back(setThickness10);
	Button* setOutlineColor = new Button("setOutlineColor", m_font, grey, sf::Vector2f(0, 250), sf::Vector2f(120, 40));
	setOutlineColor->SetCommand(new ChangeOutlineColorCommand(inputManager));
	m_buttons.push_back(setOutlineColor);
}
bool ButtonsManager::ButtonsClick(sf::Vector2i clickPosition)
{
	bool clicked = false;
	for (Button* button : m_buttons)
	{
		if (button->ContainsPoint(clickPosition))
		{
			button->Execute();
			button->Click();
			clicked = true;
			for (Button* unclicked : m_buttons)
			{
				if (button != unclicked)
				{
					unclicked->UnClick();
				}
			}
		}
	}
	for (Button* button : m_colorButtons)
	{
		if (button->ContainsPoint(clickPosition))
		{
			button->Execute();
			button->Click();
			clicked = true;
			for (Button* unclicked : m_colorButtons)
			{
				if (button != unclicked)
				{
					unclicked->UnClick();
				}
			}
		}
	}
	return clicked;
}
void ButtonsManager::DrawButtons(sf::RenderWindow& window)
{
	for (Shape* button : m_buttons)
	{
		button->Draw(window);
	}
	for (Shape* button : m_colorButtons)
	{
		button->Draw(window);
	}
}