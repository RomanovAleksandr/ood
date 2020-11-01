#pragma once
class InputManager;

class InputState
{
protected:
    InputManager* m_context = nullptr;
public:
    virtual ~InputState() 
    {
    }
    void SetContext(InputManager* context)
    {
        m_context = context;
    }
    virtual void Execute() = 0;
};

class DragAndDropState : public InputState
{
public:
    void Execute()
    {
        m_context->selectedShape->move(m_context->mouseOffset);
    }
};

class ChangeColorState : public InputState
{
public:
    void Execute()
    {

    }
};