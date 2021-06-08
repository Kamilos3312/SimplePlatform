#pragma once

#include <Engine/ResourceManager.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>

#include <string>

class Level
{
public:
    Level(ResourceManager<std::string, sf::Texture> &textures, ResourceManager<std::string, sf::Font> &fonts,
          unsigned int id);

public:
    unsigned int m_id = 0;
    unsigned int m_score = 0;

    sf::Text m_scoreText;
    sf::Sprite m_player;
};