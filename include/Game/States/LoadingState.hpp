#pragma once

#include <Engine/State.hpp>

#include <SFML/Graphics/Text.hpp>

class LoadingState : public State
{
public:
    LoadingState(StateManager &stateManager, State::Context context);

    void handleEvent(const sf::Event &event) override;
    void update(float deltaTime) override;
    void render() override;

private:
    sf::Text m_title;
};