#include <Game/States/GameState.hpp>
#include <Engine/ResourceManager.hpp>
#include <Engine/StateManager.hpp>

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

GameState::GameState(StateManager &stateManager, State::Context context)
        : State(stateManager, context),
          m_level(*context.textureManager, *context.fontManager, 1)
{
}

void GameState::handleEvent(const sf::Event &event)
{
    if (event.type == sf::Event::KeyPressed)
    {
        switch (event.key.code)
        {
            case sf::Keyboard::W:
            case sf::Keyboard::Up:
                // ...
                break;
            case sf::Keyboard::S:
            case sf::Keyboard::Down:
                // ...
                break;
            case sf::Keyboard::A:
            case sf::Keyboard::Left:
                // ...
                break;
            case sf::Keyboard::D:
            case sf::Keyboard::Right:
                // ...
                break;
            default:
                break;
        }
    }
}

void GameState::update(float deltaTime)
{
    // ...
}

void GameState::render()
{
    sf::RenderWindow &window = *m_context.window;
    window.draw(m_level.m_player);
    window.draw(m_level.m_scoreText);
}
