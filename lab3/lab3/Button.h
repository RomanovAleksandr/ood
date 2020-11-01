#pragma once
#include <string>
#include "Rectangle.h"
#include "Command.h"

class Button : public Rectangle
{
public:
	Button(std::string text, sf::Font& font, sf::Vector2f position, sf::Vector2f size) : Rectangle(position, size)
	{
		m_text.setFont(font);
		m_text.setString(text);
		m_text.setCharacterSize(24);
		m_text.setFillColor(sf::Color::Red);
		m_text.setPosition(position);
		m_shape->setFillColor(sf::Color::Green);
	}
	void Draw(sf::RenderWindow& window)
	{
		window.draw(*m_shape);
		window.draw(m_text);
	}
	void SetCommand(Command* command)
	{
		m_command = command;
	}
	void Execute()
	{
		m_command->Execute();
	}
	~Button()
	{
		delete(m_command);
	}
private:
	sf::Text m_text;
	Command* m_command = nullptr;
};