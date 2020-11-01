#pragma once
#include <string>
#include "Circle.h"
#include <list>

class Command
{
public:
	virtual ~Command()
	{
	}
	virtual void Execute() const = 0;
};

class AddNewShape : public Command
{
private:
	std::string m_shape;
	std::list<Shape*>& m_shapes;
public:
	AddNewShape(std::string shape, std::list<Shape*>& shapes) : m_shape(shape), m_shapes(shapes)
	{
	}
	void Execute() const
	{
		if (m_shape == "circle")
		{
			m_shapes.push_back(new Circle(sf::Vector2f(100, 100), 50));
		}
	}
};

class ChangeShapeColor : public Command
{
private:
	sf::Color m_shapeColor;
	std::list<Shape*>& m_shapes;
public:
	ChangeShapeColor(sf::Color color, std::list<Shape*>& shapes) : m_shapeColor(color), m_shapes(shapes)
	{
	}
	void Execute() const
	{
		for (Shape* shape : m_shapes)
		{
			shape->SetFillColor(m_shapeColor);
		}
	}
};