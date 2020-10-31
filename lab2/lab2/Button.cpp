#include "Button.h"

Button::Button(std::string text, sf::Font& font, sf::Vector2f position, sf::Vector2f size)
{
	m_text.setFont(font);
	m_text.setString(text);
	m_text.setCharacterSize(24);
	m_text.setFillColor(sf::Color::Red);
	m_text.setPosition(position);
	m_shape.setPosition(position);
	m_shape.setSize(size);
	m_shape.setFillColor(sf::Color::Green);
}

void Button::Draw(sf::RenderWindow& window)
{
	window.draw(m_shape);
	window.draw(m_text);
}