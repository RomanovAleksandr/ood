#include <regex>
#include <fstream>
#include "ShapesManager.h"
#include "Circle.h"
#include "Triangle.h"
#include "Rectangle.h"

void ShapesManager::ReadShapes(std::string fileName)
{
	std::ifstream input(fileName);
	std::string line;
	while (std::getline(input, line))
	{
		if (line.find("TRIANGLE") != std::string::npos)
		{
			std::regex re("TRIANGLE: P1=(.+),(.+); P2=(.+),(.+); P3:(.+),(.+)");
			std::smatch match;
			std::regex_search(line, match, re);
			sf::Vector2f a(stof(match[1]), stof(match[2]));
			sf::Vector2f b(stof(match[3]), stof(match[4]));
			sf::Vector2f c(stof(match[5]), stof(match[6]));
			Triangle* triangle = new Triangle(a, b, c);
			m_shapes.push_back(triangle);
		}
		else if (line.find("CIRCLE") != std::string::npos)
		{
			std::regex re("CIRCLE: C=(.+),(.+); R=(.+)");
			std::smatch match;
			std::regex_search(line, match, re);
			sf::Vector2f position(stof(match[1]), stof(match[2]));
			Circle* circle = new Circle(position, stof(match[3]));
			m_shapes.push_back(circle);
		}
		else if (line.find("RECTANGLE") != std::string::npos)
		{
			std::regex re("RECTANGLE: P1=(.+),(.+); P2=(.+),(.+)");
			std::smatch match;
			std::regex_search(line, match, re);
			sf::Vector2f position(stof(match[1]), stof(match[2]));
			sf::Vector2f size(abs(stof(match[1]) - stof(match[3])), abs(stof(match[2]) - stof(match[4])));
			Rectangle* rectangle = new Rectangle(position, size);
			//rectangle->SetBorderColor(sf::Color::Transparent);
			m_shapes.push_back(rectangle);
		}
	}
}