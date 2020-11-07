#pragma once
#include "Shape.h"
#include <list>

class Composite : public Shape
{
protected:
	std::list<Shape*> m_children;

public:
	bool IsComposite() const;
	void Add(Shape* component);
	std::list<Shape*>& GetChildren();
	void Draw(sf::RenderWindow& window);
	void Move(const sf::Vector2f& offset);
	void SetFillColor(sf::Color color);
	void SetOutlineColor(sf::Color color);
	void SetOutlineThickness(float thickness);
	void SetBorderColor(sf::Color color);
	bool ContainsPoint(sf::Vector2i point);
};