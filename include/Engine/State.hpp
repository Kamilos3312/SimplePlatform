#pragma once

#include <memory>
#include <string>

class StateManager;
template<typename T, typename U>
class ResourceManager;

namespace sf
{
    class Event;
    class RenderWindow;
    class Texture;
    class Font;
}

class State
{
public:
    struct Context
    {
        Context(sf::RenderWindow &window, ResourceManager<std::string, sf::Texture> &textures,
                ResourceManager<std::string, sf::Font> &fonts);

        sf::RenderWindow *window;
        ResourceManager<std::string, sf::Texture> *textureManager;
        ResourceManager<std::string, sf::Font> *fontManager;
    };

    State(StateManager &stateManager, Context context);
    virtual ~State() = default;

    virtual void handleEvent(const sf::Event &event) = 0;
    virtual void update(float deltaTime) = 0;
    virtual void render() = 0;

protected:
    StateManager *m_stateManager;
    Context m_context;
};