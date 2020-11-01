#pragma once
#include "Shape.h"
#include <list>

class ShapesManager
{
public:
	std::list<Shape*> m_shapes;
	std::list<Shape*> m_selectedShapes;
	void ReadShapes(std::string fileName);
};