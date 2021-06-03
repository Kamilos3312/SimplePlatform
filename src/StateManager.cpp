#include <Engine/StateManager.hpp>
#include <Engine/State.hpp>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

StateManager::StateManager(std::shared_ptr<sf::RenderWindow> window)
        : m_states(),
          m_window(window)
{
}

StateManager::~StateManager()
{
    while (!m_states.empty())
    {
        popState();
    }
}

std::shared_ptr<StateManager> StateManager::get_shared_ptr()
{
    return shared_from_this();
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