#pragma once
#include "Shape.h"
#include <list>

class ShapesManager
{
public:
	std::list<Shape*> m_shapes;
	std::list<Shape*> m_selectedShapes;
	void ReadShapes(std::string fileName);
	void SelectShapes(sf::Vector2i clickPosition);
	bool SelectShape(sf::Vector2i clickPosition);
	void ComposeShapes();
	void DecomposeShapes();
	void ClearSelectedShapes();
	void DrawShapes(sf::RenderWindow& window);
	Shape* selectedShape = nullptr;
};