#pragma once

#include <memory>
#include <stack>

class State;

namespace sf
{
    class Event;
    class RenderWindow;
}

class StateManager : public std::enable_shared_from_this<StateManager>
{
public:
    StateManager(std::shared_ptr<sf::RenderWindow> window);
    ~StateManager();

    std::shared_ptr<StateManager> get_shared_ptr();

    template<typename StateType>
    void pushState();
    template<typename StateType>
    void swapState();
    void popState();

    void handleEvent(sf::Event &event);
    void update(float deltaTime);
    void render();

private:
    std::stack<std::unique_ptr<State>> m_states;
    std::shared_ptr<sf::RenderWindow> m_window;
};

#include "StateManager.inl"