#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <list>

class ShapesManager
{
public:
	ShapesManager();
	std::list<sf::Shape*> m_shapes;
	void ReadShapes(std::string fileName);

private:

};