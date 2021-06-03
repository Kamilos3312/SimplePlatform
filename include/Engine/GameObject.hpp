#pragma once

#include "Component.hpp"
#include <vector>
#include <memory>
#include <SFML/Graphics/RenderWindow.hpp>

class GameObject
{
public:
    void init();

    void update(float deltaTime);
    void draw(sf::RenderWindow &window);

    template<typename T>
    std::shared_ptr<T> addComponent();
    template<typename T>
    std::shared_ptr<T> getComponent();

private:
    std::vector<std::shared_ptr<Component>> m_components;
};

#include "GameObject.inl"