//
// Created by Julio Anzaldo on 3/5/22.
//

#include "Button.h"

sf::Font Button::font;

Button::Button() : States()
{

}

Button::Button(std::string text) : Button(text, sf::Color::Black, sf::Color::White, {200, 100})
{

}

Button::Button(std::string text, sf::Color color, sf::Color textColor, sf::Vector2f size) : States()
{
    this->text.setFont(getFont(ARIAL));
    this->text.setFillColor(textColor);
    this->text.setString(text);

    background.setSize(size);
    background.setFillColor(color);

    sf::FloatRect tb = this->text.getGlobalBounds();
    sf::FloatRect bb = background.getGlobalBounds();

    this->text.setPosition(bb.left + bb.width / 2 - tb.width + 20, bb.top + bb.height/2 - tb.height);
    //music.loadFromFile("ButtonHoverSound.wav");
    disabledStates(PLAYED);
}

void Button::eventHandler(sf::RenderWindow &window, sf::Event event)
{
    sf::Vector2f mpos = (sf::Vector2f) sf::Mouse::getPosition(window);
    if(background.getGlobalBounds().contains(mpos))
    {
        enabledState(HOVERED);
    }
    else
        disabledStates(HOVERED);
}

void Button::update()
{
    sf::Sound sound;
    sound.setBuffer(music);
    sound.setVolume(50);

    if(isEnabled(HOVERED))
    {
        sound.play();
    }
    else
        sound.stop();
}

void Button::setPosition(float x, float y)
{
    background.setPosition(x, y);
}

sf::FloatRect Button::getGlobalBounds() const
{
    return background.getGlobalBounds();
}

void Button::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    states.transform = background.getTransform();
    window.draw(background);
    window.draw(text, states);
}
