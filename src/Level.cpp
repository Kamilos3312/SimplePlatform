#include <Game/Level.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Font.hpp>

Level::Level(ResourceManager<std::string, sf::Texture> &textures, ResourceManager<std::string, sf::Font> &fonts,
             unsigned int id)
        : m_id(id)
{
    textures.load("player", "assets/gfx/player.png");
    m_player.setTexture(textures.get("player"));
    auto bounds = m_player.getLocalBounds();
    m_player.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
    m_player.setPosition(bounds.width * 2, bounds.height * 2);

    m_scoreText.setFont(fonts.get("default"));
    m_scoreText.setString("abcdefghijklmnopqrstuvwxyz");
    m_scoreText.setCharacterSize(32u);
}
