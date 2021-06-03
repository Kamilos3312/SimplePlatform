#include <Game/Components/Animation.hpp>

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Texture.hpp>

Animation::Animation(GameObject *owner)
        : Component(owner),
          m_sprite(),
          m_frameSize()
{
    m_frameCount = 0u;
    m_currentFrame = 0u;
    m_duration = 0.f;
    m_elapsed = 0.f;
    m_repeat = false;
}

void Animation::setTexture(const sf::Texture &texture)
{
    m_sprite.setTexture(texture);
}

const sf::Texture *Animation::getTexture()
{
    return m_sprite.getTexture();
}

void Animation::setPosition(sf::Vector2f position)
{
    m_sprite.setPosition(position);
}

sf::Vector2f Animation::getPosition() const
{
    return m_sprite.getPosition();
}

void Animation::setOrigin(sf::Vector2f origin)
{
    m_sprite.setOrigin(origin);
}

sf::Vector2f Animation::getOrigin() const
{
    return m_sprite.getOrigin();
}

void Animation::setFrameSize(sf::Vector2i frameSize)
{
    m_frameSize = frameSize;
}

sf::Vector2i Animation::getFrameSize() const
{
    return m_frameSize;
}

void Animation::setFrameCount(unsigned int numFrames)
{
    m_frameCount = numFrames;
}

unsigned int Animation::getFrameCount()
{
    return m_frameCount;
}

void Animation::setDuration(float duration)
{
    m_duration = duration;
}

float Animation::getDuration()
{
    return m_duration;
}

void Animation::setRepeating(bool flag)
{
    m_repeat = flag;
}

bool Animation::isRepeating()
{
    return m_repeat;
}

void Animation::restart()
{
    m_currentFrame = 0;
}

bool Animation::isFinished() const
{
    return m_currentFrame >= m_frameCount;
}

sf::FloatRect Animation::getLocalBounds() const
{
    return sf::FloatRect(getOrigin(), static_cast<sf::Vector2f>(getFrameSize()));
}

sf::FloatRect Animation::getGlobalBounds() const
{
    return getTransform().transformRect(getLocalBounds());
}

void Animation::update(float deltaTime)
{
    float timePerFrame = m_duration / m_frameCount;
    m_elapsed += deltaTime;

    sf::Vector2i textureBounds(m_sprite.getTexture()->getSize());
    sf::IntRect textureRect = m_sprite.getTextureRect();

    if (m_currentFrame == 0)
    {
        textureRect = sf::IntRect(0, 0, m_frameSize.x, m_frameSize.y);
    }

    while (m_elapsed >= timePerFrame && (m_currentFrame <= m_frameCount || m_repeat))
    {
        textureRect.left += textureRect.width;

        if (textureRect.left + textureRect.width > textureBounds.x)
        {
            textureRect.left = 0;
            textureRect.top += textureRect.height;
        }

        m_elapsed -= timePerFrame;
        if (m_repeat)
        {
            m_currentFrame = (m_currentFrame + 1) % m_frameCount;

            if (m_currentFrame == 0)
            {
                textureRect = sf::IntRect(0, 0, m_frameSize.x, m_frameSize.y);
            } else
            {
                m_currentFrame++;
            }
        }
    }

    m_sprite.setTextureRect(textureRect);
}

sf::Transform Animation::getTransform() const
{
    return m_sprite.getTransform();
}

void Animation::draw(sf::RenderWindow &window)
{
    window.draw(m_sprite);
}
