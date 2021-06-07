#include <Game/States/GameState.hpp>
#include <Game/States/LoadingState.hpp>

#include <Engine/ResourceManager.hpp>
#include <Engine/StateManager.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

GameState::GameState(StateManager &stateManager, State::Context context)
        : State(stateManager, context)
{
    auto windowSize = sf::Vector2f(m_context.window->getSize());
//    m_stateManager->swapState<LoadingState>();

    m_player.setTexture(m_context.textureManager->get("player"));
    m_player.setPosition(windowSize.x / 2.f, windowSize.y / 2.f);
    auto bounds = m_player.getLocalBounds();
    m_player.setOrigin(bounds.width / 2.f, bounds.height / 2.f);

    m_context.fontManager->load("abc", "assets/font.ttf");
    m_text.setFont(m_context.fontManager->get("abc"));
    m_text.setString("Hello there");
    m_text.setCharacterSize(24u);
    m_text.setFillColor(sf::Color::White);
    m_text.setPosition(windowSize.x / 2.f, windowSize.y / 4.f);
    bounds = m_text.getLocalBounds();
    m_text.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
}

void GameState::handleEvent(const sf::Event &event)
{
}

void GameState::update(float deltaTime)
{
}

void GameState::render()
{
    m_context.window->draw(m_player);
    m_context.window->draw(m_text);
}
