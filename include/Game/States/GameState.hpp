#pragma once

#include <Engine/State.hpp>

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>

class GameState : public State
{
public:
    GameState(StateManager
              &stateManager,
              State::Context context
    );

    void handleEvent(const sf::Event &event) override;
    void update(float deltaTime) override;
    void render() override;

private:
    // level
    sf::Sprite m_player;

    sf::Text m_text;
};