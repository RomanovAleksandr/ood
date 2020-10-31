#pragma once
#include <string>
#include <SFML/Graphics.hpp>

class Button
{
public:
	Button(std::string text, sf::Font& font, sf::Vector2f position, sf::Vector2f size);
	void Draw(sf::RenderWindow& window);

private:
	sf::RectangleShape m_shape;
	sf::Text m_text;
};