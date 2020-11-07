#include "Circle.h"

Circle::Circle(sf::Vector2f position, float radius)
{
    m_shape = new sf::CircleShape(radius);
    m_shape->setPosition(position);
    m_radius = radius;
}
bool Circle::ContainsPoint(sf::Vector2i point)
{
    sf::Vector2f position = m_shape->getPosition();
    if ((point.x - position.x - m_radius) * (point.x - position.x - m_radius) +
        (point.y - position.y - m_radius) * (point.y - position.y - m_radius) <= m_radius * m_radius)
        return true;
    else
        return false;
}