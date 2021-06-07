#include <Engine/State.hpp>
#include <Engine/StateManager.hpp>

State::State(StateManager &stateManager, Context context)
        : m_stateManager(&stateManager),
          m_context(context)
{
}

State::Context::Context(sf::RenderWindow &window, ResourceManager<std::string, sf::Texture> &textures,
                        ResourceManager<std::string, sf::Font> &fonts)
        : window(&window),
          textureManager(&textures),
          fontManager(&fonts)
{
}
