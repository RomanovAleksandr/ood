#pragma once

class BaseShapeDecorator
{
public:
	~BaseShapeDecorator() {};
	virtual float GetArea() = 0;
	virtual float GetPerimeter() = 0;
};