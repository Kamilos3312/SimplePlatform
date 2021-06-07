#pragma once

#include <Engine/State.hpp>

#include <SFML/Graphics/Text.hpp>

class IntroState : public State
{
public:
    IntroState(StateManager &stateManager, State::Context context);

    void handleEvent(const sf::Event &event) override;
    void update(float deltaTime) override;
    void render() override;

private:
    float m_elapsed = 0.f;
    float m_duration = 5.f;

    sf::Text m_title;
};