#pragma once
#include <string>
#include "Rectangle.h"
#include "Command.h"

class Button : public Rectangle
{
public:
	Button(std::string text, sf::Font& font, sf::Color color, sf::Vector2f position, sf::Vector2f size);
	void Draw(sf::RenderWindow& window);
	void SetCommand(Command* m_command);
	void Execute();
	void Click();
	void UnClick();
private:
	sf::Text m_text;
	Command* m_command = nullptr;
	bool m_clicked = false;
};