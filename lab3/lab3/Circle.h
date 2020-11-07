#pragma once
#include "Shape.h"

class Circle : public Shape
{
public:
	Circle(sf::Vector2f position, float radius = 0);
	bool ContainsPoint(sf::Vector2i point);
private:
    float m_radius;
};