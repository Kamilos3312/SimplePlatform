#pragma once

#include <Engine/State.hpp>
#include <Engine/ResourceManager.hpp>
#include <UI/Button.hpp>
#include <Engine/GameObject.hpp>

#include <SFML/Graphics/Text.hpp>

#include <string>
#include <memory>

namespace sf
{
    class Texture;
    class Font;
}

class MenuState : public State
{
public:
    MenuState(std::shared_ptr<StateManager> stateManager, std::shared_ptr<sf::RenderWindow> window);

    virtual void handleEvent(const sf::Event &event) override;
    virtual void update(float deltaTime) override;
    virtual void render() override;

private:
    ResourceManager<std::string, sf::Texture> m_textureManager;
    ResourceManager<std::string, sf::Font> m_fontManager;

    sf::Text m_title;
    ui::Button m_startBtn;
    std::shared_ptr<GameObject> m_player;
};