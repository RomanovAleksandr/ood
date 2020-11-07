#include "InputManager.h"
#include "Composite.h"
#include <iostream>

InputManager::InputManager(ShapesManager& shapesManager, ButtonsManager& buttonsManager) :
    m_shapesManager(shapesManager), m_buttonsManager(buttonsManager)
{
    this->TransitionTo(new DragAndDropState());
}

void InputManager::Update(sf::Event& event)
{
    if (event.type == sf::Event::KeyPressed)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) && sf::Keyboard::isKeyPressed(sf::Keyboard::G))
        {
            m_shapesManager.ComposeShapes();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) && sf::Keyboard::isKeyPressed(sf::Keyboard::U))
        {
            m_shapesManager.DecomposeShapes();
        }
    }
    if (event.type == sf::Event::MouseButtonPressed)
    {
        sf::Vector2i clickPosition(event.mouseButton.x, event.mouseButton.y);
        if (event.mouseButton.button == sf::Mouse::Right && sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
        {
            m_shapesManager.SelectShapes(clickPosition);
        }
        else if (event.mouseButton.button == sf::Mouse::Left)
        {
            if (!m_buttonsManager.ButtonsClick(clickPosition))
            {
                if (!m_shapesManager.SelectShape(clickPosition))
                {
                    m_shapesManager.ClearSelectedShapes();
                }
            }
        }
    }
    if (event.type == sf::Event::MouseButtonReleased)
    {
        if (event.mouseButton.button == sf::Mouse::Left)
        {
            m_shapesManager.selectedShape = nullptr;
        }
    }
    if (m_shapesManager.selectedShape != nullptr)
    {
        m_state->Execute();
    }
    m_prevMousePosition = m_newMousePosition;
    m_newMousePosition = sf::Vector2i(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y);
    mouseOffset = sf::Vector2f(m_newMousePosition - m_prevMousePosition);
}

void InputManager::TransitionTo(InputManagerState* state)
{
    std::cout << "Context: Transition to " << typeid(*state).name() << ".\n";
    if (this->m_state != nullptr)
        delete this->m_state;
    this->m_state = state;
    this->m_state->SetContext(this);
}