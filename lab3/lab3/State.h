#pragma once
class State
{
public:
    virtual ~State() {
    }
    virtual void Execute() = 0;
};

class DragAndDropState : public State
{
    void Execute()
    {

    }
};

class ChangeColorState : public State
{
    void Execute()
    {

    }
};