#include <Game/Components/Sprite.hpp>

namespace Components
{
    Sprite::Sprite(GameObject *owner)
            : Component(owner)
    {
    }

    void Sprite::setTexture(const sf::Texture &texture)
    {
        m_sprite.setTexture(texture);
    }

    void Sprite::draw(sf::RenderWindow &window)
    {
        window.draw(m_sprite);
    }
}