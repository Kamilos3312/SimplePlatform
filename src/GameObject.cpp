#include <Engine/GameObject.hpp>

void GameObject::init()
{
    for (int i = m_components.size() - 1; i >= 0; i--)
    {
        m_components[i]->init();
    }
}

void GameObject::update(float timeDelta)
{
    for (int i = m_components.size() - 1; i >= 0; i--)
    {
        m_components[i]->update(timeDelta);
    }
}

void GameObject::draw(sf::RenderWindow &window)
{
    for (int i = m_components.size() - 1; i >= 0; i--)
    {
        m_components[i]->draw(window);
    }
}