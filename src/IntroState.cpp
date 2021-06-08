#include <Game/States/IntroState.hpp>
#include <Game/States/MenuState.hpp>
#include <Engine/StateManager.hpp>
#include <Engine/ResourceManager.hpp>

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

IntroState::IntroState(StateManager &stateManager, State::Context context)
        : State(stateManager, context)
{
    auto windowSize = sf::Vector2f(m_context.window->getSize());
    sf::FloatRect bounds;

    m_title.setFont(m_context.fontManager->get("default"));
    m_title.setCharacterSize(48);
    m_title.setString("Intro");
    m_title.setPosition(windowSize.x / 2.f, windowSize.y / 4);
    bounds = m_title.getLocalBounds();
    m_title.setOrigin(bounds.width / 2, bounds.height / 2);
}

void IntroState::handleEvent(const sf::Event &event)
{
    if (event.type == sf::Event::KeyPressed)
    {
        switch (event.key.code)
        {
            case sf::Keyboard::Enter:
            case sf::Keyboard::Escape:
                m_stateManager->swapState<MenuState>();
                break;

            default:
                break;
        }
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
    sf::RenderWindow &window = *m_context.window;
    window.draw(m_title);
}
