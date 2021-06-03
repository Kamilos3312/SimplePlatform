#include <UI/Button.hpp>
#include <Engine/Utils/Color.hpp>

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>

namespace ui
{
    Button::Button()
        : m_text(), m_body()
    {
        m_state = State::Default;
        setSize(0, 0);
    }

    Button::Button(const sf::Font &font, sf::Vector2f position)
        : Button()
    {
        setFont(font);
        setPosition(position);
    }

    void Button::setCallback(std::function<void(void)> callback)
    {
        m_callback = std::move(callback);
    }

    void Button::setPosition(sf::Vector2f position)
    {
        m_text.setPosition(position);
        m_body.setPosition(position);
    }

    void Button::setPosition(float x, float y)
    {
        m_text.setPosition(x, y);
        m_body.setPosition(x, y);
    }

    sf::Vector2f Button::getPosition()
    {
        return m_text.getPosition();
    }

    void Button::setBackgroundColor(sf::Color color)
    {
        m_body.setFillColor(color);
    }

    void Button::setBackgroundTexture(const sf::Texture &texture)
    {
        m_body.setTexture(&texture);
    }

    void Button::setBorder(unsigned int width, sf::Color color)
    {
        setBorderWidth(width);
        setBorderColor(color);
    }

    void Button::setBorderWidth(unsigned int width)
    {
        m_body.setOutlineThickness(width);
        updateBodyOrigin();
    }

    void Button::setBorderColor(sf::Color color)
    {
        m_body.setOutlineColor(color);
    }

    void Button::setSize(sf::Vector2f size)
    {
        m_body.setSize(size);
        updateBodyOrigin();
    }

    void Button::setSize(float width, float height)
    {
        m_body.setSize(sf::Vector2f(width, height));
        updateBodyOrigin();
    }

    sf::Vector2f Button::getSize()
    {
        sf::Vector2f size;
        sf::Vector2f textSize = getSizeFromBounds(m_text.getLocalBounds());
        sf::Vector2f bodySize = getSizeFromBounds(m_body.getLocalBounds());

        size.x = textSize.x > bodySize.x ? textSize.x : bodySize.x;
        size.y = textSize.y > bodySize.y ? textSize.y : bodySize.y;
        return size;
    }

    void Button::setFont(const sf::Font &font)
    {
        m_text.setFont(font);
    }

    void Button::setText(std::string text)
    {
        m_text.setString(text);
        updateTextOrigin();
    }

    std::string Button::getText()
    {
        return m_text.getString();
    }

    void Button::setTextSize(unsigned int size)
    {
        m_text.setCharacterSize(size);
        updateTextOrigin();
    }

    unsigned int Button::getTextSize()
    {
        return m_text.getCharacterSize();
    }

    void Button::setTextColor(sf::Color color)
    {
        m_defaultColor = color;

        float *hsv = Util::Color::rgb2hsv(color.r, color.g, color.b);
        hsv[0] += 180;

        float *rgb = Util::Color::hsv2rgb(hsv[0] + 30, hsv[1], hsv[2]);
        sf::Color splitComp1 = sf::Color(rgb[0], rgb[1], rgb[2]);
        m_hoverColor = splitComp1;

        rgb = Util::Color::hsv2rgb(hsv[0] - 30, hsv[1], hsv[2]);
        splitComp1 = sf::Color(rgb[0], rgb[1], rgb[2]);
        m_pressedColor = splitComp1;

        double grayscale = Util::Color::rgb2grayscale(color.r, color.g, color.b);
        m_disabledColor = sf::Color(grayscale, grayscale, grayscale);

        m_hoverColor = sf::Color(0, 255, 0);
        m_pressedColor = sf::Color(255, 0, 0);
    }

    void Button::setTextStyle(unsigned int style)
    {
        m_text.setStyle(style);
        updateTextOrigin();
    }

    void Button::handleEvents(const sf::Event &event, sf::RenderWindow &window)
    {
        if (m_state == State::Disabled)
        {
            return;
        }

        sf::Vector2f mousePos = sf::Vector2f(sf::Mouse::getPosition(window));
        if (event.type == sf::Event::MouseMoved)
        {
            if (isHovered(mousePos))
            {
                if (m_state == State::Default)
                {
                    m_state = State::Hovered;
                }
            }
            else
            {
                m_state = State::Default;
            }
        }

        if (event.type == sf::Event::MouseButtonReleased)
        {
            if (m_state == State::Pressed && m_callback)
            {
                m_callback();
            }

            m_state = isHovered(mousePos) ? State::Hovered : State::Default;
        }
        else if (event.type == sf::Event::MouseButtonPressed)
        {
            auto temp2 = getGlobalBounds();
            auto temp = getGlobalBounds().contains(mousePos);
            if (m_state == State::Hovered && event.mouseButton.button == sf::Mouse::Left)
            {
                m_state = State::Pressed;
            }
        }
    }

    void Button::update()
    {
        switch (m_state)
        {
        case State::Hovered:
            m_text.setFillColor(m_hoverColor);
            break;
        case State::Pressed:
            m_text.setFillColor(m_pressedColor);
            break;
        case State::Disabled:
            m_text.setFillColor(m_disabledColor);
            break;
        default:
            m_text.setFillColor(m_defaultColor);
            break;
        }
    }

    void Button::updateTextOrigin()
    {
        sf::FloatRect bounds = m_text.getLocalBounds();
        m_text.setOrigin(bounds.left + bounds.width / 2.f, bounds.top + bounds.height / 2.f);
    }

    void Button::updateBodyOrigin()
    {
        sf::Vector2f size = m_body.getSize();
        m_body.setOrigin(size.x / 2.f, size.y / 2.f);
    }

    sf::FloatRect Button::getGlobalBounds()
    {
        return m_body.getGlobalBounds();
    }

    sf::Vector2f Button::getSizeFromBounds(sf::FloatRect floatRect)
    {
        return sf::Vector2f(floatRect.width, floatRect.height);
    }

    bool Button::isHovered(sf::Vector2f mousePos)
    {
        return getGlobalBounds().contains(mousePos);
    }

    void Button::draw(sf::RenderTarget &target, sf::RenderStates states) const
    {
        target.draw(m_body, states);
        target.draw(m_text, states);
    }
}