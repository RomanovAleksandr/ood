#pragma once
#include <SFML/Graphics.hpp>
#include <list>
#include <vector>

class Composite : public sf::Shape
{
protected:
	std::list<sf::Shape*> m_children;

public:
	void Add(sf::Shape* component)
	{
		this->m_children.push_back(component);
		component->SetParent(this);
	}
	void Remove(sf::Shape* component)
	{
		m_children.remove(component);
		component->SetParent(nullptr);
	}
	std::list<sf::Shape*> GetChildren()
	{
		return m_children;
	}
	void setOutlineColor(const sf::Color& color)
	{
		for (sf::Shape* c : m_children)
		{
			c->setOutlineColor(color);
		}
	}
	void SetBorderColor(const sf::Color& color)
	{
		for (sf::Shape* c : m_children)
		{
			c->SetBorderColor(color);
		}
	}
	bool ContainsPoint(sf::Vector2i point)
	{
		for (sf::Shape* c : m_children)
		{
			if (c->ContainsPoint(point))
			{
				return true;
			}
		}
		return false;
	}
	void move(const sf::Vector2f& offset)
	{
		for (sf::Shape* c : m_children)
		{
			c->move(offset);
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