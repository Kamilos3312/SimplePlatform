#include <Game/States/MenuState.hpp>
#include <Engine/StateManager.hpp>

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/System/Vector2.hpp>

MenuState::MenuState(std::shared_ptr<StateManager> stateManager, std::shared_ptr<sf::RenderWindow> window)
        : State(stateManager, window),
          m_textureManager(),
          m_fontManager()
{
    m_fontManager.load("default", "assets/BigSpace-rPKx.ttf");

    auto windowSize = sf::Vector2f(m_window->getSize());

    m_title.setFont(m_fontManager.get("default"));
    m_title.setCharacterSize(48u);
    m_title.setString("SimplePlatform v2");
    m_title.setPosition(windowSize.x / 2.f, windowSize.y / 4.f);
    m_title.setOrigin(m_title.getLocalBounds().width / 2.f, m_title.getLocalBounds().height / 2.f);

    float marginY = m_title.getPosition().y + m_title.getLocalBounds().height * 2;
    m_startBtn.setPosition(windowSize.x / 2.f, marginY);
    m_startBtn.setFont(m_fontManager.get("default"));
    m_startBtn.setText("START");
    m_startBtn.setTextColor(sf::Color(255, 255, 255));
    m_startBtn.setBackgroundColor(sf::Color(11, 123, 234, 128));
    m_startBtn.setBorder(1, sf::Color(11, 123, 234));
    float padding = m_startBtn.getTextSize();
    m_startBtn.setSize(m_startBtn.getSize().x + padding, m_startBtn.getSize().y + padding / 2.f);
}

void MenuState::handleEvent(const sf::Event &event)
{
    m_startBtn.handleEvents(event, *m_window);
}

void MenuState::update(float deltaTime)
{
    m_startBtn.update();
}

void MenuState::render()
{
    m_window->draw(m_title);
    m_window->draw(m_startBtn);
}
