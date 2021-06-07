#pragma once

#include <Engine/State.hpp>
#include <SFML/System/NonCopyable.hpp>

#include <memory>
#include <stack>

namespace sf
{
    class Event;
}

class StateManager : private sf::NonCopyable
{
public:
    StateManager(State::Context context);
    ~StateManager();

    template<typename StateType>
    void pushState();
    template<typename StateType>
    void swapState();
    template<typename StateType, typename T>
    void pushState(T data);
    template<typename StateType, typename T>
    void swapState(T data);
    void popState();

    void handleEvent(sf::Event &event);
    void update(float deltaTime);
    void render();

private:
    std::stack<std::unique_ptr<State>> m_states;
    State::Context m_context;
};

#include "StateManager.inl"