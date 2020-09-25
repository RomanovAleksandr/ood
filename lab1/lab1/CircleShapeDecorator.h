#pragma once

class CircleShapeDecorator : public sf::Shape
{
public:
	sf::CircleShape& m_circle;

	CircleShapeDecorator(sf::CircleShape &circle) : m_circle(circle)
	{
	}

	void Display(sf::RenderWindow &window)
	{
		window.draw(m_circle);
	}

	float GetArea()
	{
		return 3.14f * pow(m_circle.getRadius(), 2);
	}

	float GetPerimeter()
	{
		return 2 * 3.14f * m_circle.getRadius();
	}

	std::size_t getPointCount() const override
	{
		return 0;
	}
	sf::Vector2f getPoint(std::size_t index) const override
	{
		return sf::Vector2f{ 0,0 };
	}

private:

};