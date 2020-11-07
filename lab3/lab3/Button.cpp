#include "Button.h"

Button::Button(std::string text, sf::Font& font, sf::Color color, sf::Vector2f position, sf::Vector2f size) 
	: Rectangle(position, size)
{
	m_text.setFont(font);
	m_text.setString(text);
	m_text.setCharacterSize(20);
	m_text.setFillColor(sf::Color::Black);
	m_text.setPosition(position);
	m_shape->setFillColor(color);
}
void Button::Draw(sf::RenderWindow& window)
{
	window.draw(*m_shape);
	window.draw(m_text);
}
void Button::SetCommand(Command* command)
{
	m_command = command;
}
void Button::Execute()
{
	m_command->Execute();
}
void Button::Click()
{
	if (!m_clicked)
	{
		sf::Color color = m_shape->getFillColor();
		color.r -= 40;
		color.g -= 40;
		color.b -= 40;
		m_shape->setFillColor(color);
	}
	m_clicked = true;
}
void Button::UnClick()
{
	if (m_clicked)
	{
		sf::Color color = m_shape->getFillColor();
		color.r += 40;
		color.g += 40;
		color.b += 40;
		m_shape->setFillColor(color);
	}
	m_clicked = false;
}