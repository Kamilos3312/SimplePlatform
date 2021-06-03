#pragma once

#include <Engine/Component.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

namespace Components
{
    class Sprite : public Component
    {
    public:
        Sprite(GameObject *owner);

        void setTexture(const sf::Texture &texture);
        void draw(sf::RenderWindow &window) override;

    private:
        sf::Sprite m_sprite;
    };
}