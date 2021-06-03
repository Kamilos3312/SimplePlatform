#pragma once

#include <memory>

namespace sf
{
    class RenderWindow;
}

class StateManager;

class Application
{
public:
    Application();
    void run();

private:
    void handleEvents();
    void update(float deltaTime);
    void render();

private:
    std::shared_ptr<sf::RenderWindow> m_window;
    std::shared_ptr<StateManager> m_stateManager;
};
