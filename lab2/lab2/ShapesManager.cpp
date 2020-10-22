#include "ShapesManager.h"
#include <regex>

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
			sf::ConvexShape* triangle = new sf::ConvexShape();
			triangle->setPointCount(3);
			triangle->setPoint(0, sf::Vector2f(stof(match[1]), stof(match[2])));
			triangle->setPoint(1, sf::Vector2f(stof(match[3]), stof(match[4])));
			triangle->setPoint(2, sf::Vector2f(stof(match[5]), stof(match[6])));
			triangle->SetBorderColor(sf::Color::Transparent);
			m_shapes.push_back(triangle);
		}
		else if (line.find("CIRCLE") != std::string::npos)
		{
			std::regex re("CIRCLE: C=(.+),(.+); R=(.+)");
			std::smatch match;
			std::regex_search(line, match, re);
			sf::CircleShape* circle = new sf::CircleShape();
			circle->setRadius(stof(match[3]));
			circle->setPosition(stof(match[1]), stof(match[2]));
			circle->SetBorderColor(sf::Color::Transparent);
			m_shapes.push_back(circle);
		}
		else if (line.find("RECTANGLE") != std::string::npos)
		{
			std::regex re("RECTANGLE: P1=(.+),(.+); P2=(.+),(.+)");
			std::smatch match;
			std::regex_search(line, match, re);
			sf::RectangleShape* rectangle = new sf::RectangleShape();
			rectangle->setSize(sf::Vector2f(abs(stof(match[1]) - stof(match[3])), abs(stof(match[2]) - stof(match[4]))));
			rectangle->setPosition(stof(match[1]), stof(match[2]));
			rectangle->SetBorderColor(sf::Color::Transparent);
			m_shapes.push_back(rectangle);
		}
	}
}

ShapesManager::ShapesManager()
{

}