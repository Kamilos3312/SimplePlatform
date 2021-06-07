#include <Game/States/MenuState.hpp>
#include <Game/States/LoadingState.hpp>
#include <Engine/ResourceManager.hpp>
#include <Engine/StateManager.hpp>

#include <SFML/Graphics/RenderWindow.hpp>

LoadingState::LoadingState(StateManager &stateManager, State::Context context)
        : State(stateManager, context)
{
    auto windowSize = sf::Vector2f(m_context.window->getSize());
    float marginY = 0.f;
    sf::FloatRect bounds;

    m_title.setFont(m_context.fontManager->get("default"));
    m_title.setCharacterSize(48u);
    m_title.setString("Loading");
    m_title.setPosition(windowSize.x / 2.f, windowSize.y / 4.f);
    bounds = m_title.getLocalBounds();
    m_title.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
}

void LoadingState::handleEvent(const sf::Event &event)
{
}

void LoadingState::update(float deltaTime)
{
}

void LoadingState::render()
{
    sf::RenderWindow &window = *m_context.window;
    window.draw(m_title);
}
