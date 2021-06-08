#pragma once

#include <Engine/State.hpp>
#include <Game/Level.hpp>

class GameState : public State
{
public:
    GameState(StateManager &stateManager, State::Context context);

    void handleEvent(const sf::Event &event) override;
    void update(float deltaTime) override;
    void render() override;

private:
    Level m_level;
};