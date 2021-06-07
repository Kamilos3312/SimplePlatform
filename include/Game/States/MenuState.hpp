#pragma once

#include <Engine/State.hpp>
#include <UI/Button.hpp>

#include <SFML/Graphics/Text.hpp>

class MenuState : public State
{
public:
    MenuState(StateManager &stateManager, State::Context context);

    void handleEvent(const sf::Event &event) override;
    void update(float deltaTime) override;
    void render() override;

private:
    sf::Text m_title;
    ui::Button m_startBtn;
    ui::Button m_exitBtn;
};