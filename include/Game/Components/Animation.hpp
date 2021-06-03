#pragma once

#include <Engine/Component.hpp>

#include <SFML/Graphics/Sprite.hpp>

#include <vector>
#include <memory>

class GameObject;

class Animation : public Component
{
public:
    Animation(GameObject *owner);

    void setTexture(const sf::Texture &texture);
    const sf::Texture *getTexture();

    void setPosition(sf::Vector2f position);
    sf::Vector2f getPosition() const;

    void setOrigin(sf::Vector2f origin);
    sf::Vector2f getOrigin() const;

    void setFrameSize(sf::Vector2i frameSize);
    sf::Vector2i getFrameSize() const;

    void setFrameCount(unsigned int numFrames);
    unsigned int getFrameCount();

    void setDuration(float duration);
    float getDuration();

    void setRepeating(bool flag);
    bool isRepeating();

    void restart();
    bool isFinished() const;

    sf::FloatRect getLocalBounds() const;
    sf::FloatRect getGlobalBounds() const;

    void update(float deltaTime) override;
    void draw(sf::RenderWindow &window) override;

private:
    sf::Transform getTransform() const;

private:
    sf::Sprite m_sprite;
    sf::Vector2i m_frameSize;
    unsigned int m_frameCount;
    unsigned int m_currentFrame;
    float m_duration;
    float m_elapsed;
    bool m_repeat;
};