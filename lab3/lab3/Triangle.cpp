#include "Triangle.h"

Triangle::Triangle(sf::Vector2f a, sf::Vector2f b, sf::Vector2f c)
{
    sf::ConvexShape* triangle = new sf::ConvexShape(3);
    triangle->setPoint(0, a);
    triangle->setPoint(1, b);
    triangle->setPoint(2, c);
    m_shape = triangle;
}
float Triangle::GetArea(float x1, float y1, float x2, float y2, float x3, float y3)
{
    return abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0f);
}
bool Triangle::ContainsPoint(sf::Vector2i point)
{
    sf::Vector2f v1 = m_shape->getTransform().transformPoint(m_shape->getPoint(0));
    sf::Vector2f v2 = m_shape->getTransform().transformPoint(m_shape->getPoint(1));
    sf::Vector2f v3 = m_shape->getTransform().transformPoint(m_shape->getPoint(2));
    /* Calculate area of triangle ABC */
    float A = GetArea(v1.x, v1.y, v2.x, v2.y, v3.x, v3.y);
    /* Calculate area of triangle PBC */
    float A1 = GetArea((float)point.x, (float)point.y, v2.x, v2.y, v3.x, v3.y);
    /* Calculate area of triangle PAC */
    float A2 = GetArea(v1.x, v1.y, (float)point.x, (float)point.y, v3.x, v3.y);
    /* Calculate area of triangle PAB */
    float A3 = GetArea(v1.x, v1.y, v2.x, v2.y, (float)point.x, (float)point.y);
    /* Check if sum of A1, A2 and A3 is same as A */
    if ((A == A1 + A2 + A3))
    {
        return true;
    }
    return false;
}