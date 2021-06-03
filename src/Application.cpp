#include <Game/Application.hpp>
#include <Engine/StateManager.hpp>
#include <Game/States/IntroState.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

#include <chrono>

Application::Application()
{
    m_window = std::make_shared<sf::RenderWindow>(sf::VideoMode(800, 600), "[SFML] Simple Platform Game",
                                                  sf::Style::Titlebar | sf::Style::Close);
    m_stateManager = std::make_shared<StateManager>(m_window);
    m_stateManager->pushState<IntroState>();
}

void Application::run()
{
    const std::chrono::nanoseconds FRAMETIME(16666667); // 16.66ms = 1000/60
    using clock = std::chrono::high_resolution_clock;

    auto appStartTime = clock::now();
    auto frameStartTime = clock::now();
    std::chrono::nanoseconds accumulator(0);

    while (m_window->isOpen())
    {
        auto now = clock::now();
        if (now - frameStartTime > std::chrono::milliseconds(1))
        {
            auto deltaTime = now - frameStartTime;
            frameStartTime = now;
            accumulator += deltaTime;
        }

        handleEvents();

        while (accumulator >= FRAMETIME)
        {
            accumulator -= FRAMETIME;
            update(std::chrono::duration_cast<std::chrono::seconds>(accumulator).count());
        }

        render();
    }
}

void Application::handleEvents()
{
    sf::Event event;
    while (m_window->pollEvent(event))
    {
        m_stateManager->handleEvent(event);

        if (event.type == sf::Event::Closed)
        {
            m_window->close();
        }
    }
}

void Application::update(float deltaTime)
{
    m_stateManager->update(deltaTime);
}

void Application::render()
{
    m_window->clear();
    m_stateManager->render();
    m_window->display();
}
