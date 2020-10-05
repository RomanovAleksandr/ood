#include "ShapeProcess.h"
#include "CircleShapeDecorator.h"
#include "RectangleShapeDecorator.h"
#include "TriangleShapeDecorator.h"
#include <regex>
#include <fstream>
#include <iostream>

void ReadShapes(std::vector<sf::Shape*>& shapes, std::string fileName)
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
			shapes.push_back(triangle);
		}
		else if (line.find("CIRCLE") != std::string::npos)
		{
			std::regex re("CIRCLE: C=(.+),(.+); R=(.+)");
			std::smatch match;
			std::regex_search(line, match, re);
			sf::CircleShape* circle = new sf::CircleShape();
			circle->setRadius(stof(match[3]));
			circle->setPosition(stof(match[1]), stof(match[2]));
			shapes.push_back(circle);
		}
		else if (line.find("RECTANGLE") != std::string::npos)
		{
			std::regex re("RECTANGLE: P1=(.+),(.+); P2=(.+),(.+)");
			std::smatch match;
			std::regex_search(line, match, re);
			sf::RectangleShape* rectangle = new sf::RectangleShape();
			rectangle->setSize(sf::Vector2f(abs(stof(match[1]) - stof(match[3])), abs(stof(match[2]) - stof(match[4]))));
			rectangle->setPosition(stof(match[1]), stof(match[2]));
			shapes.push_back(rectangle);
		}
	}
}

void SaveShapes(std::vector<sf::Shape*>& shapes, std::string fileName)
{
	std::ofstream output(fileName);
	for (sf::Shape* shape : shapes)
	{
		BaseShapeDecorator* shapeDecorator;
		if (dynamic_cast<sf::CircleShape*>(shape))
		{
			shapeDecorator = new CircleShapeDecorator(shape);
			output << "CIRCLE: P=" << shapeDecorator->GetPerimeter() << "; S=" << shapeDecorator->GetArea() << '\n';
		}
		else if (dynamic_cast<sf::RectangleShape*>(shape))
		{
			shapeDecorator = new RectangleShapeDecorator(shape);
			output << "RECTANGLE: P=" << shapeDecorator->GetPerimeter() << "; S=" << shapeDecorator->GetArea() << '\n';
		}
		else if (dynamic_cast<sf::ConvexShape*>(shape))
		{
			shapeDecorator = new TriangleShapeDecorator(shape);
			output << "TRIANGLE: P=" << shapeDecorator->GetPerimeter() << "; S=" << shapeDecorator->GetArea() << '\n';
		}
	}
}