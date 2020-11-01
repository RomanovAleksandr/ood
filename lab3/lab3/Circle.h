#pragma once
#include "Shape.h"

class Circle : public Shape
{
public:
	Circle(sf::Vector2f position, float radius = 0)
	{
		m_shape = new sf::CircleShape(radius);
		m_shape->setPosition(position);
        m_radius = radius;
	}

    bool ContainsPoint(sf::Vector2i point)
    {
        sf::Vector2f position = m_shape->getPosition();
        if ((point.x - position.x - m_radius) * (point.x - position.x - m_radius) +
            (point.y - position.y - m_radius) * (point.y - position.y - m_radius) <= m_radius * m_radius)
            return true;
        else
            return false;
    }
private:
    float m_radius;
};