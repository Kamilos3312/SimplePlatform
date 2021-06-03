#pragma once

#include <Engine/Component.hpp>
#include <SFML/System/Vector2.hpp>

class GameObject;

namespace Components
{
    class Position : public Component
    {
    public:
        Position(GameObject *owner);

        void setPosition(sf::Vector2f position);
        void setPosition(float x, float y);
        sf::Vector2f getPosition();

    private:
        sf::Vector2f m_position;
    };
}