//
// Created by Julio Anzaldo on 3/5/22.
//

#ifndef GUIPROJECT_BUTTON_H
#define GUIPROJECT_BUTTON_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "States.h"
#include "Fonts.h"

class Button : public sf::Drawable, public States, public Fonts {
private:
    sf::RectangleShape background;
    sf::Text text;

    static sf::Font font;

    sf::SoundBuffer music;
    sf::Sound sound;
public:
    Button();
    Button(std::string text);
    Button(std::string text, sf::Color color, sf::Color textColor, sf::Vector2f size);

    void eventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
    void setPosition(float x, float y);

    sf::FloatRect getGlobalBounds() const;

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
};


#endif //GUIPROJECT_BUTTON_H
