#pragma once

#include <SFML/Graphics/RenderWindow.hpp>

class GameObject;

class Component
{
public:
    Component(GameObject *owner) : owner(owner)
    {}

    virtual ~Component() = default;

    virtual void init()
    {}

    virtual void update(float deltaTime)
    {}

    virtual void draw(sf::RenderWindow &window)
    {}

protected:
    GameObject *owner;
};