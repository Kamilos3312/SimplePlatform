#pragma once

#include <memory>

class StateManager;

namespace sf
{
    class Event;
    class RenderWindow;
}

class State
{
public:
    State(std::shared_ptr<StateManager> stateManager, std::shared_ptr<sf::RenderWindow> window);
    virtual ~State() = default;

    virtual void handleEvent(const sf::Event &event) = 0;
    virtual void update(float deltaTime) = 0;
    virtual void render() = 0;

protected:
    std::shared_ptr<StateManager> m_stateManager;
    std::shared_ptr<sf::RenderWindow> m_window;
};