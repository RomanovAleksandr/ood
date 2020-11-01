#pragma once
#include <SFML/Graphics.hpp>

class Command
{
public:
	virtual ~Command()
	{
	}
	virtual void Execute() const = 0;
};

class AddNewShape : public Command
{
private:
	std::string m_shape;
public:
	AddNewShape(std::string shape) : m_shape(shape)
	{
	}
	void Execute() const;
};