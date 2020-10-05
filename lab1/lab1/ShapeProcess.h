#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

void ReadShapes(std::vector<sf::Shape*>& shapes, std::string fileName);
void SaveShapes(std::vector<sf::Shape*>& shapes, std::string fileName);
