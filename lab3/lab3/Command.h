#pragma once
#include "Shape.h"
#include <list>
class InputManager;

class Command 
{
public:
    virtual ~Command() {
    }
    virtual void Execute() const = 0;
};

enum class Shapes
{
    Circle,
    Rectangle,
    Triangle
};

class AddShapeCommand : public Command
{
public:
    AddShapeCommand(std::list<Shape*>& shapes, Shapes shape);
    void Execute() const;
private:
    std::list<Shape*>& m_shapes;
    Shapes m_shape;
};

enum class InputManagerStates
{
    dragAndDrop,
    changeShapeColor
};

class ChangeInputManagerStateCommand : public Command
{
public:
    ChangeInputManagerStateCommand(InputManager& inputManager, InputManagerStates state);
    void Execute() const;
private:
    InputManager& m_inputManager;
    InputManagerStates m_state;
};

class SetSelectedColor : public Command
{
public:
    SetSelectedColor(InputManager& inputManager, sf::Color color);
    void Execute() const;
private:
    InputManager& m_inputManager;
    sf::Color m_color;
};

class ChangeOtlineThicknessCommand : public Command
{
public:
    ChangeOtlineThicknessCommand(InputManager& inputManager, float thisckness);
    void Execute() const;
private:
    InputManager& m_inputManager;
    float m_thisckness;
};

class ChangeOutlineColorCommand : public Command
{
public:
    ChangeOutlineColorCommand(InputManager& inputManager);
    void Execute() const;
private:
    InputManager& m_inputManager;
};