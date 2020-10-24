#include "InputManager.h"
#include <iostream>
#include "Composite.h"
#include <list>

void InputManager::Update(sf::Event& event)
{
    if (event.type == sf::Event::KeyPressed)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) && sf::Keyboard::isKeyPressed(sf::Keyboard::G))
        {
            if (m_tempShapes.size() > 1)
            {
                Composite* composite = new Composite();
                for (sf::Shape* shape : m_tempShapes)
                {
                    m_shapes.remove(shape);
                    composite->Add(shape);
                }
                m_shapes.push_back(composite);
                for (sf::Shape* shape : m_tempShapes)
                {
                    shape->SetBorderColor(sf::Color::Transparent);
                }
                m_tempShapes.clear();
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) && sf::Keyboard::isKeyPressed(sf::Keyboard::U))
        {
            for (sf::Shape* shape : m_tempShapes)
            {
                if (dynamic_cast<Composite*>(shape))
                {
                    std::list<sf::Shape*> decomposed = dynamic_cast<Composite*>(shape)->GetChildren();
                    for (sf::Shape* c : decomposed)
                    {
                        c->SetParent(nullptr);
                        m_shapes.push_back(c);
                        c->SetBorderColor(sf::Color::Transparent);
                    }
                    m_shapes.remove(shape);
                    delete(shape);
                }
                else
                {
                    shape->SetBorderColor(sf::Color::Transparent);
                }
            }
            m_tempShapes.clear();
        }
    }
    if (event.type == sf::Event::MouseButtonPressed)
    {
        sf::Vector2i clickPosition(event.mouseButton.x, event.mouseButton.y);
        if (event.mouseButton.button == sf::Mouse::Right && sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
        {
            for (sf::Shape* shape : m_shapes)
            {
                if (shape->ContainsPoint(clickPosition))
                {
                    sf::Shape* root = shape->GetRoot();
                    if (std::find(m_tempShapes.begin(), m_tempShapes.end(), root) != m_tempShapes.end())
                    {  
                        root->SetBorderColor(sf::Color::Transparent);
                        m_tempShapes.remove(root);
                    }
                    else
                    {                        
                        root->SetBorderColor(sf::Color:: Red);
                        m_tempShapes.push_back(root);
                    }
                }
            }
        }
        else if (event.mouseButton.button == sf::Mouse::Left)
        {
            for (sf::Shape* shape : m_shapes)
            {
                if (shape->ContainsPoint(clickPosition))
                {
                    dragFigure = shape->GetRoot();
                }
            }
        }
    }
    if (event.type == sf::Event::MouseButtonReleased)
    {
        if (event.mouseButton.button == sf::Mouse::Left)
        {
            dragFigure = nullptr;
        }
    }
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        if (dragFigure != nullptr)
        {
            dragFigure->move(sf::Vector2f(m_newMousePosition - m_prevMousePosition));
        }
    }
    m_prevMousePosition = m_newMousePosition;
    m_newMousePosition = sf::Vector2i(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y);
}