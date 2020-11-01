#pragma once
#include "Shape.h"
#include <list>

class Composite : public Shape
{
protected:
	std::list<Shape*> m_children;

public:
	bool IsComposite() const
	{
		return true;
	}
	void Add(Shape* component)
	{
		this->m_children.push_back(component);
		component->SetParent(this);
	}
	std::list<Shape*>& GetChildren()
	{
		return m_children;
	}
	void Draw(sf::RenderWindow& window)
	{
		for (Shape* c : m_children)
		{
			c->Draw(window);
		}
	}
	void move(const sf::Vector2f& offset)
	{
		for (Shape* c : m_children)
		{
			c->move(offset);
		}
	}
	void SetFillColor(sf::Color color)
	{
		for (Shape* c : m_children)
		{
			c->SetFillColor(color);
		}
	}
	void SetOutlineColor(sf::Color color)
	{
		for (Shape* c : m_children)
		{
			c->SetOutlineColor(color);
		}
	}
	void setOutlineThickness(float thickness)
	{
		for (Shape* c : m_children)
		{
			c->SetOutlineThickness(thickness);
		}
	}
	virtual void SetBorderColor(sf::Color color)
	{
		for (Shape* c : m_children)
		{
			c->SetBorderColor(color);
		}
	}
	bool ContainsPoint(sf::Vector2i point)
	{
		for (Shape* c : m_children)
		{
			if (c->ContainsPoint(point))
			{
				return true;
			}
		}
		return false;
	}
};