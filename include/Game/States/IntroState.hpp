#pragma once

#include <Engine/State.hpp>
#include <Engine/ResourceManager.hpp>

#include <SFML/Graphics/Text.hpp>

#include <string>

class StateManager;

namespace sf
{
    class Font;
    class RenderWindow;
}

class IntroState : public State
{
public:
    IntroState(std::shared_ptr<StateManager> stateManager, std::shared_ptr<sf::RenderWindow> window);

    virtual void handleEvent(const sf::Event &event) override;
    virtual void update(float deltaTime) override;
    virtual void render() override;

private:
    ResourceManager<std::string, sf::Font> m_fontManager;

    sf::Text m_title;
    float m_elapsed = 0.f;
    float m_duration = 5.f;
};