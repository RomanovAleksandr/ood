#include "Rectangle.h"

Rectangle::Rectangle(sf::Vector2f position, sf::Vector2f size)
{
    m_shape = new sf::RectangleShape(size);
    m_shape->setPosition(position);
}
bool Rectangle::ContainsPoint(sf::Vector2i point)
{
    sf::FloatRect position = m_shape->getGlobalBounds();
    if (position.contains((sf::Vector2f)point))
    {
        return true;
    }
    return false;
}