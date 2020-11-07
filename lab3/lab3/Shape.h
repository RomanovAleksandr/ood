#pragma once
#include <SFML/Graphics.hpp>

class Shape
{
public:
	virtual ~Shape();
	virtual void Draw(sf::RenderWindow& window);
	bool virtual ContainsPoint(sf::Vector2i point) = 0;
	void SetParent(Shape* parent);
	Shape* GetRoot();
	virtual bool IsComposite() const;
	virtual void Move(const sf::Vector2f& offset);
	virtual void SetFillColor(sf::Color color);
	virtual void SetOutlineColor(sf::Color color);
	virtual void SetOutlineThickness(float thickness);
	virtual void SetBorderColor(sf::Color color);
protected:
	void UpdateBorder();
	void UpdateBorderColor();
	Shape* m_parent = nullptr;
	sf::Shape* m_shape = nullptr;
	sf::VertexArray m_border;
	sf::Color m_borderColor = sf::Color::Transparent;
};