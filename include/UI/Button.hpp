#pragma once

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

#include <string>
#include <functional>

namespace ui
{
    enum class State
    {
        Default,
        Hovered,
        Pressed,
        Released,
        Disabled
    };

    class Button : public sf::Drawable
    {
    public:
        Button();
        Button(const sf::Font &font, sf::Vector2f position);

        void setCallback(std::function<void(void)> callback);
        void setPosition(sf::Vector2f position);
        void setPosition(float x, float y);
        sf::Vector2f getPosition();

        void setBackgroundColor(sf::Color color);
        void setBackgroundTexture(const sf::Texture &texture);
        void setBorder(unsigned int width, sf::Color color);
        void setBorderWidth(unsigned int width);
        void setBorderColor(sf::Color color);
        void setSize(sf::Vector2f size);
        void setSize(float width, float height);
        sf::Vector2f getSize();

        void setFont(const sf::Font &font);
        void setText(std::string text);
        std::string getText();
        void setTextSize(unsigned int size);
        unsigned int getTextSize();
        void setTextColor(sf::Color color);
        void setTextStyle(unsigned int style);

        void handleEvents(const sf::Event &event, sf::RenderWindow &window);
        void update();

    private:
        void updateTextOrigin();
        void updateBodyOrigin();

        sf::FloatRect getGlobalBounds();
        sf::Vector2f getSizeFromBounds(sf::FloatRect floatRect);

        bool isHovered(sf::Vector2f mousePos);
        void draw(sf::RenderTarget &target, sf::RenderStates states) const;

    private:
        sf::RectangleShape m_body;
        sf::Text m_text;

        sf::Color m_defaultColor;
        sf::Color m_hoverColor;
        sf::Color m_pressedColor;
        sf::Color m_disabledColor;

        std::function<void(void)> m_callback;
        ui::State m_state;
    };
}