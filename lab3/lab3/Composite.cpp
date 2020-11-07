#include "Composite.h"

bool Composite::IsComposite() const
{
	return true;
}
void Composite::Add(Shape* component)
{
	this->m_children.push_back(component);
	component->SetParent(this);
}
std::list<Shape*>& Composite::GetChildren()
{
	return m_children;
}
void Composite::Draw(sf::RenderWindow& window)
{
	for (Shape* c : m_children)
	{
		c->Draw(window);
	}
}
void Composite::Move(const sf::Vector2f& offset)
{
	for (Shape* c : m_children)
	{
		c->Move(offset);
	}
}
void Composite::SetFillColor(sf::Color color)
{
	for (Shape* c : m_children)
	{
		c->SetFillColor(color);
	}
}
void Composite::SetOutlineColor(sf::Color color)
{
	for (Shape* c : m_children)
	{
		c->SetOutlineColor(color);
	}
}
void Composite::SetOutlineThickness(float thickness)
{
	for (Shape* c : m_children)
	{
		c->SetOutlineThickness(thickness);
	}
}
void Composite::SetBorderColor(sf::Color color)
{
	for (Shape* c : m_children)
	{
		c->SetBorderColor(color);
	}
}
bool Composite::ContainsPoint(sf::Vector2i point)
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