#pragma once
#include <SFML/Graphics.hpp>

class Shape
{
public:
	virtual ~Shape()
	{
	}
	virtual void Draw(sf::RenderWindow& window)
	{
		window.draw(*m_shape);
		UpdateBorder();
		UpdateBorderColor();
		window.draw(m_border);
	}
	bool virtual ContainsPoint(sf::Vector2i point) = 0;
	void SetParent(Shape* parent)
	{
		m_parent = parent;
	}
	Shape* GetRoot()
	{
		if (m_parent == nullptr)
		{
			return this;
		}
		else
		{
			return m_parent->GetRoot();
		}
	}
	virtual bool IsComposite() const
	{
		return false;
	}
	virtual void move(const sf::Vector2f& offset)
	{
		m_shape->move(offset);
	}
	virtual void SetFillColor(sf::Color color)
	{
		m_shape->setFillColor(color);
	}
	virtual void SetOutlineColor(sf::Color color)
	{
		m_shape->setOutlineColor(color);
	}
	virtual void SetOutlineThickness(float thickness)
	{
		m_shape->setOutlineThickness(thickness);
	}
	virtual void SetBorderColor(sf::Color color)
	{
		m_borderColor = color;
	}
	void UpdateBorder()
	{
		m_border.resize(5);
		m_border.setPrimitiveType(sf::LinesStrip);
		sf::FloatRect localBounds = m_shape->getGlobalBounds();
		m_border[0].position = sf::Vector2f(localBounds.left, localBounds.top);
		m_border[1].position = sf::Vector2f(localBounds.left + localBounds.width, localBounds.top);
		m_border[3].position = sf::Vector2f(localBounds.left, localBounds.top + localBounds.height);
		m_border[2].position = sf::Vector2f(localBounds.left + localBounds.width, localBounds.top + localBounds.height);
		m_border[4].position = sf::Vector2f(localBounds.left, localBounds.top);
	}
	void UpdateBorderColor()
	{
		for (std::size_t i = 0; i < m_border.getVertexCount(); ++i)
			m_border[i].color = m_borderColor;
	}
protected:
	Shape* m_parent = nullptr;
	sf::Shape* m_shape = nullptr;
	sf::VertexArray m_border;
	sf::Color m_borderColor = sf::Color::Transparent;
};