#pragma once
#include "BaseShapeDecorator.h"
#include <SFML/Graphics.hpp>

class CircleShapeDecorator : public BaseShapeDecorator
{
public:
	sf::Shape* m_circle;

	CircleShapeDecorator(sf::Shape* circle) : m_circle(circle)
	{
	}

	float GetArea() override
	{
		return 3.14f * pow(static_cast<sf::CircleShape*>(m_circle)->getRadius(), 2);
	}

	float GetPerimeter() override
	{
		return 2 * 3.14f * static_cast<sf::CircleShape*>(m_circle)->getRadius();
	}
};