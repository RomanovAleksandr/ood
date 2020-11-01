#include "InputManager.h"
#include "Composite.h"

void InputManager::Update(sf::Event& event)
{
    if (event.type == sf::Event::KeyPressed)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) && sf::Keyboard::isKeyPressed(sf::Keyboard::G))
        {
            if (m_selectedShapes.size() > 1)
            {
                Composite* composite = new Composite();
                for (Shape* shape : m_selectedShapes)
                {
                    m_shapes.remove(shape);
                    composite->Add(shape);
                }
                m_shapes.push_back(composite);
                for (Shape* shape : m_selectedShapes)
                {
                    shape->SetBorderColor(sf::Color::Transparent);
                }
                m_selectedShapes.clear();
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) && sf::Keyboard::isKeyPressed(sf::Keyboard::U))
        {
            for (Shape* shape : m_selectedShapes)
            {
                if (shape->IsComposite())
                {
                    std::list<Shape*> decomposed = dynamic_cast<Composite*>(shape)->GetChildren();
                    for (Shape* c : decomposed)
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
            m_selectedShapes.clear();
        }
    }
    if (event.type == sf::Event::MouseButtonPressed)
    {
        sf::Vector2i clickPosition(event.mouseButton.x, event.mouseButton.y);
        if (event.mouseButton.button == sf::Mouse::Right && sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
        {
            for (Shape* shape : m_shapes)
            {
                if (shape->ContainsPoint(clickPosition))
                {
                    Shape* root = shape->GetRoot();
                    if (std::find(m_selectedShapes.begin(), m_selectedShapes.end(), root) != m_selectedShapes.end())
                    {
                        root->SetBorderColor(sf::Color::Transparent);
                        m_selectedShapes.remove(root);
                    }
                    else
                    {
                        root->SetBorderColor(sf::Color::Red);
                        m_selectedShapes.push_back(root);
                    }
                }
            }
        }
        else if (event.mouseButton.button == sf::Mouse::Left)
        {
            for (Shape* shape : m_shapes)
            {
                if (shape->ContainsPoint(clickPosition))
                {
                    dragFigure = shape->GetRoot();
                }
            }
            for (Button* shape : m_buttons)
            {
                if (shape->ContainsPoint(clickPosition))
                {
                    shape->Execute();
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
        //state->Execute();
    }
    m_prevMousePosition = m_newMousePosition;
    m_newMousePosition = sf::Vector2i(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y);
    mouseOffset = sf::Vector2f(m_newMousePosition - m_prevMousePosition);
}

void InputManager::Execute()
{
    state->Execute();
}