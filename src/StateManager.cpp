#include <Engine/StateManager.hpp>

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

StateManager::StateManager(State::Context context)
        : m_states(),
          m_context(context)
{
}

StateManager::~StateManager()
{
    while (!m_states.empty())
    {
        popState();
    }
}

void StateManager::popState()
{
    m_states.pop();
}

void StateManager::handleEvent(sf::Event &event)
{
    m_states.top()->handleEvent(event);
}

void StateManager::update(float deltaTime)
{
    m_states.top()->update(deltaTime);
}

void StateManager::render()
{
    m_states.top()->render();
}