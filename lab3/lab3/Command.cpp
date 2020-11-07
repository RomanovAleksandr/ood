#include "Command.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "InputManager.h"

AddShapeCommand::AddShapeCommand(std::list<Shape*>& shapes, Shapes shape) : m_shapes(shapes), m_shape(shape)
{
}

void AddShapeCommand::Execute() const
{
	if (m_shape == Shapes::Circle)
	{
		m_shapes.push_back(new Circle(sf::Vector2f(100, 100), 50));
	}
	else if (m_shape == Shapes::Rectangle)
	{
		m_shapes.push_back(new Rectangle(sf::Vector2f(100, 100), sf::Vector2f(100, 100)));
	}
	else if (m_shape == Shapes::Triangle)
	{
		m_shapes.push_back(new Triangle(sf::Vector2f(200, 200), sf::Vector2f(100, 300), sf::Vector2f(300, 300)));
	}
}

ChangeInputManagerStateCommand::ChangeInputManagerStateCommand(InputManager& inputManager, InputManagerStates state) :
	m_inputManager(inputManager), m_state(state)
{
}

void ChangeInputManagerStateCommand::Execute() const
{
	if (m_state == InputManagerStates::changeShapeColor)
	{
		m_inputManager.TransitionTo(new ChangeShapeColorState());
	}
	else if (m_state == InputManagerStates::dragAndDrop)
	{
		m_inputManager.TransitionTo(new DragAndDropState());
	}
}

SetSelectedColor::SetSelectedColor(InputManager& inputManager, sf::Color color) :
	m_inputManager(inputManager), m_color(color)
{
}

void SetSelectedColor::Execute() const
{
	if (m_color == sf::Color::Red)
	{
		m_inputManager.selectedColor = sf::Color(255, 169, 169);
	}
	else if (m_color == sf::Color::Green)
	{
		m_inputManager.selectedColor = sf::Color(169, 255, 169);
	}
	else if (m_color == sf::Color::Blue)
	{
		m_inputManager.selectedColor = sf::Color(169, 169, 255);
	}
}

ChangeOtlineThicknessCommand::ChangeOtlineThicknessCommand(InputManager& inputManager, float thisckness) :
	m_inputManager(inputManager), m_thisckness(thisckness)
{
}

void ChangeOtlineThicknessCommand::Execute() const
{
	for (Shape *shape : m_inputManager.m_shapesManager.m_selectedShapes)
	{
		shape->SetOutlineThickness(m_thisckness);
	}
}

ChangeOutlineColorCommand::ChangeOutlineColorCommand(InputManager& inputManager) :
	m_inputManager(inputManager)
{
}

void ChangeOutlineColorCommand::Execute() const
{
	for (Shape* shape : m_inputManager.m_shapesManager.m_selectedShapes)
	{
		shape->SetOutlineColor(m_inputManager.selectedColor);
	}
}