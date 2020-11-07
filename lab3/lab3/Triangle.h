#pragma once
#include "Shape.h"

class Triangle : public Shape
{
public:
    Triangle(sf::Vector2f a, sf::Vector2f b, sf::Vector2f c);
    bool ContainsPoint(sf::Vector2i point);
private:
    float GetArea(float x1, float y1, float x2, float y2, float x3, float y3);
};