#pragma once
#include "BaseShapeDecorator.h"
#include <SFML/Graphics.hpp>

class CircleShapeDecorator : public BaseShapeDecorator
{
public:
	CircleShapeDecorator(sf::Shape* circle) : BaseShapeDecorator(circle)
	{
	}

	float GetArea() override
	{
		return 3.14f * pow(static_cast<sf::CircleShape*>(m_shape)->getRadius(), 2);
	}

	float GetPerimeter() override
	{
		return 2 * 3.14f * static_cast<sf::CircleShape*>(m_shape)->getRadius();
	}
};