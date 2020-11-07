#pragma once
#include "Shape.h"

class Rectangle : public Shape
{
public:
	Rectangle(sf::Vector2f position, sf::Vector2f size);
	bool ContainsPoint(sf::Vector2i point);
};