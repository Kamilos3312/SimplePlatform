#include <Game/States/MenuState.hpp>
#include <Game/States/GameState.hpp>
#include <Engine/ResourceManager.hpp>
#include <Engine/StateManager.hpp>

#include <SFML/Graphics/RenderWindow.hpp>

MenuState::MenuState(StateManager &stateManager, State::Context context)
        : State(stateManager, context)
{
    auto windowSize = sf::Vector2f(m_context.window->getSize());
    float marginY = 0.f;
    sf::FloatRect bounds;

    m_title.setFont(m_context.fontManager->get("default"));
    m_title.setCharacterSize(48u);
    m_title.setString("SimplePlatform v2");
    m_title.setPosition(windowSize.x / 2.f, windowSize.y / 4.f);
    bounds = m_title.getLocalBounds();
    m_title.setOrigin(bounds.width / 2.f, bounds.height / 2.f);

    marginY = m_title.getPosition().y + m_title.getLocalBounds().height * 2;
    m_startBtn.setPosition(windowSize.x / 2.f, marginY);
    m_startBtn.setFont(m_context.fontManager->get("default"));
    m_startBtn.setText("START");
    m_startBtn.setTextColor(sf::Color(255, 255, 255));
    m_startBtn.setSize(m_startBtn.getSize());
    m_startBtn.setCallback([&]
                           { m_stateManager->swapState<GameState>(); });

    marginY = m_startBtn.getPosition().y + m_startBtn.getSize().y * 2;
    m_exitBtn.setPosition(windowSize.x / 2.f, marginY);
    m_exitBtn.setFont(m_context.fontManager->get("default"));
    m_exitBtn.setText("EXIT");
    m_exitBtn.setTextColor(sf::Color(255, 255, 255));
    m_exitBtn.setSize(m_exitBtn.getSize());
    m_exitBtn.setCallback([&]
                          { m_context.window->close(); });
}

void MenuState::handleEvent(const sf::Event &event)
{
    m_startBtn.handleEvents(event, *m_context.window);
    m_exitBtn.handleEvents(event, *m_context.window);
}

void MenuState::update(float deltaTime)
{
    m_startBtn.update();
    m_exitBtn.update();
}

void MenuState::render()
{
    sf::RenderWindow &window = *m_context.window;
    window.draw(m_title);
    window.draw(m_startBtn);
    window.draw(m_exitBtn);
}
