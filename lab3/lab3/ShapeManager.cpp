#include <regex>
#include <fstream>
#include "ShapesManager.h"
#include "Circle.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Composite.h"

void ShapesManager::ReadShapes(std::string fileName)
{
	std::ifstream input(fileName);
	std::string line;
	m_shapes.clear();
	while (std::getline(input, line))
	{
		if (line.find("TRIANGLE") != std::string::npos)
		{
			std::regex re("TRIANGLE: P1=(.+),(.+); P2=(.+),(.+); P3=(.+),(.+)");
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
			m_shapes.push_back(rectangle);
		}
	}
}
void ShapesManager::SelectShapes(sf::Vector2i clickPosition)
{
	for (Shape* shape : m_shapes)
	{
		if (shape->ContainsPoint(clickPosition))
		{
			Shape* root = shape->GetRoot();
			if (std::find(m_selectedShapes.begin(), m_selectedShapes.end(), root) != m_selectedShapes.end())
			{
				root->SetBorderColor(sf::Color::Transparent);
				m_selectedShapes.remove(root);
			}
			else
			{
				root->SetBorderColor(sf::Color::Red);
				m_selectedShapes.push_back(root);
			}
		}
	}
}
bool ShapesManager::SelectShape(sf::Vector2i clickPosition)
{
	bool selected = false;
	for (Shape* shape : m_shapes)
	{
		if (shape->ContainsPoint(clickPosition))
		{
			selected = true;
			selectedShape = shape->GetRoot();
		}
	}
	return selected;
}
void ShapesManager::ComposeShapes()
{
	if (m_selectedShapes.size() > 1)
	{
		Composite* composite = new Composite();
		for (Shape* shape : m_selectedShapes)
		{
			m_shapes.remove(shape);
			composite->Add(shape);
		}
		m_shapes.push_back(composite);
		ClearSelectedShapes();
	}
}
void ShapesManager::DecomposeShapes()
{
	for (Shape* shape : m_selectedShapes)
	{
		if (shape->IsComposite())
		{
			std::list<Shape*> decomposed = dynamic_cast<Composite*>(shape)->GetChildren();
			for (Shape* c : decomposed)
			{
				c->SetParent(nullptr);
				m_shapes.push_back(c);
				c->SetBorderColor(sf::Color::Transparent);
			}
			m_shapes.remove(shape);
			delete(shape);
		}
		else
		{
			shape->SetBorderColor(sf::Color::Transparent);
		}
	}
	m_selectedShapes.clear();
}
void ShapesManager::ClearSelectedShapes()
{
	for (Shape* shape : m_selectedShapes)
	{
		shape->SetBorderColor(sf::Color::Transparent);
	}
	m_selectedShapes.clear();
}
void ShapesManager::DrawShapes(sf::RenderWindow& window)
{
	for (Shape* shape : m_shapes)
	{
		shape->Draw(window);
	}
}