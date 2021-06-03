#include <Game/Components/Position.hpp>

namespace Components
{
    Position::Position(GameObject *owner)
            : Component(owner)
    {
    }

    void Position::setPosition(sf::Vector2f position)
    {
        m_position = position;
    }

    void Position::setPosition(float x, float y)
    {
        m_position.x = x;
        m_position.y = y;
    }

    sf::Vector2f Position::getPosition()
    {
        return m_position;
    }
}