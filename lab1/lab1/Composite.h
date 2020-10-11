#pragma once
#include <SFML/Graphics.hpp>
#include <list>

class Composite : public sf::Shape
{
protected:
	std::list<sf::Shape*> m_children;

public:
	void Add(sf::Shape* component)
	{
		this->m_children.push_back(component);
	}
	void Remove(sf::Shape* component)
	{
		m_children.remove(component);
	}
	void move(const sf::Vector2f& offset)
	{
		for (sf::Shape* c : m_children)
		{
			c->move(offset);
		}
	}
	void setFillColor(const sf::Color& color)
	{
		for (sf::Shape* c : m_children)
		{
			if (dynamic_cast<Composite*>(c))
			{
				dynamic_cast<Composite*>(c)->setFillColor(color);
			}
			else
			{
				c->setFillColor(color);
			}
		}
	}
	std::size_t getPointCount() const override
	{
		return 0;
	}
	sf::Vector2f getPoint(std::size_t index) const  override
	{
		return sf::Vector2f(0, 0);
	}
};