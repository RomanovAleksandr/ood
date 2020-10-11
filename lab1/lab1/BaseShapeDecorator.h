#pragma once

class BaseShapeDecorator
{
public:
	sf::Shape* m_shape;
	BaseShapeDecorator(sf::Shape* shape) : m_shape(shape)
	{
	}
	~BaseShapeDecorator() {};
	virtual float GetArea() = 0;
	virtual float GetPerimeter() = 0;
};