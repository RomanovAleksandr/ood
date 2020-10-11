#pragma once
#include "BaseShapeDecorator.h"
#include <SFML/Graphics.hpp>

class RectangleShapeDecorator : public BaseShapeDecorator
{
public:
	RectangleShapeDecorator(sf::Shape* rectangle) : BaseShapeDecorator(rectangle)
	{
	}

	float GetArea() override
	{
		return static_cast<sf::RectangleShape*>(m_shape)->getSize().x * static_cast<sf::RectangleShape*>(m_shape)->getSize().y;
	}

	float GetPerimeter() override
	{
		return static_cast<sf::RectangleShape*>(m_shape)->getSize().x * 2 + static_cast<sf::RectangleShape*>(m_shape)->getSize().y * 2;
	}
};