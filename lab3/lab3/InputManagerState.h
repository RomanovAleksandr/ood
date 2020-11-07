#pragma once
class InputManager;

class InputManagerState
{
public:
    virtual ~InputManagerState()
    {
    }
    virtual void Execute() = 0;
    void SetContext(InputManager* context) 
    {
        this->context_ = context;
    }
protected:
    InputManager* context_ = nullptr;
};

class DragAndDropState : public InputManagerState
{
public:
    void Execute();
};

class ChangeShapeColorState : public InputManagerState
{
public:
    void Execute();
};