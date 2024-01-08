//
// Created by Julio Anzaldo on 3/5/22.
//

#include "Screen.h"

Screen::Screen() : States()
{

}

Screen::Screen(ImageNames image, std::string title, std::string buttonText, sf::Font &font, sf::Vector2u winsize) : States(), button(buttonText)
{
    enabledState(HIDDEN);
    this->image.setTexture(Images::getImage(image));
    text.setFont(font);
    text.setCharacterSize(40);
    text.setString(title);

    sf::FloatRect tb = text.getGlobalBounds();
    sf::FloatRect ib = this->image.getGlobalBounds();
    sf::FloatRect bb = button.getGlobalBounds();

    text.setPosition(winsize.x/2 - tb.width/2, winsize.y/2 - tb.height/2);
    this->image.setPosition(winsize.x/2 - ib.width/2, tb.top + tb.height + 10);
    ib = this->image.getGlobalBounds();

    button.setPosition(winsize.x/2 - bb.width/2, ib.top + ib.height + 10);
}

void Screen::eventHandler(sf::RenderWindow &window, sf::Event event)
{
    if(!isEnabled(HIDDEN))
    {
        button.eventHandler(window, event);
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            sf::Vector2f mpos = (sf::Vector2f) sf::Mouse::getPosition(window);
            if(button.getGlobalBounds().contains(mpos))
                enabledState(HIDDEN);
        }
    }
}

void Screen::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    if(!isEnabled(HIDDEN))
    {
        window.draw(text);
        window.draw(button);
        window.draw(image);
    }
}
