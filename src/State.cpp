#include <Engine/State.hpp>
#include <Engine/StateManager.hpp>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

State::State(std::shared_ptr<StateManager> stateManager, std::shared_ptr<sf::RenderWindow> window)
        : m_stateManager(stateManager),
          m_window(window)
{
}