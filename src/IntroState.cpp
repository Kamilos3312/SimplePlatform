#include <Game/States/IntroState.hpp>
#include <Game/States/MenuState.hpp>
#include <Engine/StateManager.hpp>

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Font.hpp>

IntroState::IntroState(std::shared_ptr<StateManager> stateManager, std::shared_ptr<sf::RenderWindow> window)
        : State(stateManager, window),
          m_fontManager()
{
    m_fontManager.load("default", "assets/BigSpace-rPKx.ttf");
    m_title.setFont(m_fontManager.get("default"));
    m_title.setCharacterSize(48);
    m_title.setString("Intro");
    auto windowSize = sf::Vector2f(m_window->getSize());
    m_title.setPosition(windowSize.x / 2.f, windowSize.y / 4);
    m_title.setOrigin(m_title.getLocalBounds().width / 2, m_title.getLocalBounds().height / 2);
}

void IntroState::handleEvent(const sf::Event &event)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
    {
        m_stateManager->swapState<MenuState>();
    }
}

void IntroState::update(float deltaTime)
{
    m_elapsed += deltaTime;
    if (m_elapsed > m_duration)
    {
        m_stateManager->swapState<MenuState>();
        return;
    }
}

void IntroState::render()
{
    m_window->draw(m_title);
}
