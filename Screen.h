//
// Created by Julio Anzaldo on 3/5/22.
//

#ifndef GUIPROJECT_SCREEN_H
#define GUIPROJECT_SCREEN_H
#include "States.h"
#include "Button.h"
#include "Images.h"

class Screen : public sf::Drawable, public States {
private:
    sf::Text text;
    sf::Sprite image;
    Button button;
public:
    Screen();
    Screen(ImageNames image, std::string title, std::string buttonText, sf::Font& font, sf::Vector2u winsize);

    void eventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
};


#endif //GUIPROJECT_SCREEN_H
