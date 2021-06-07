#pragma once

#include <Engine/ResourceManager.hpp>
#include <Engine/StateManager.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Font.hpp>

#include <string>

class Application
{
public:
    Application();
    void run();

private:
    void handleEvents();
    void update(float deltaTime);
    void render();

private:
    sf::RenderWindow m_window;
    StateManager m_stateManager;

    ResourceManager<std::string, sf::Texture> m_textureManager;
    ResourceManager<std::string, sf::Font> m_fontManager;
};
