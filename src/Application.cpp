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
    const std::chrono::nanoseconds dt(16666667);
    using clock = std::chrono::high_resolution_clock;
    auto last = clock::now();
    std::chrono::nanoseconds accumulator(0);

    while (m_window->isOpen())
    {
        auto elapsed = clock::now();
        if (elapsed - last > std::chrono::milliseconds(1))
        {
            auto deltaTime = elapsed - last;
            last = elapsed;
            accumulator += deltaTime;
        }

        handleEvents();
        while (accumulator >= dt)
        {
            accumulator -= dt;
            auto seconds = static_cast<float>(std::chrono::duration_cast<std::chrono::milliseconds>(dt).count()) / 1000;
            update(seconds);
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
