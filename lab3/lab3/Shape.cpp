#include "Shape.h"

Shape::~Shape()
{
}
void Shape::Draw(sf::RenderWindow& window)
{
	window.draw(*m_shape);
	UpdateBorder();
	UpdateBorderColor();
	window.draw(m_border);
}
void Shape::SetParent(Shape* parent)
{
	m_parent = parent;
}
Shape* Shape::GetRoot()
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
bool Shape::IsComposite() const
{
	return false;
}
void Shape::Move(const sf::Vector2f& offset)
{
	m_shape->move(offset);
}
void Shape::SetFillColor(sf::Color color)
{
	m_shape->setFillColor(color);
}
void Shape::SetOutlineColor(sf::Color color)
{
	m_shape->setOutlineColor(color);
}
void Shape::SetOutlineThickness(float thickness)
{
	m_shape->setOutlineThickness(thickness);
}
void Shape::SetBorderColor(sf::Color color)
{
	m_borderColor = color;
}
void Shape::UpdateBorder()
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
void Shape::UpdateBorderColor()
{
	for (std::size_t i = 0; i < m_border.getVertexCount(); ++i)
		m_border[i].color = m_borderColor;
}