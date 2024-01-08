//
// Created by Julio Anzaldo on 12/31/23.
//

#ifndef SFML_NEW_TEMPLATE_PHYSICSENGINE_H
#define SFML_NEW_TEMPLATE_PHYSICSENGINE_H
#include <SFML/Graphics.hpp>
#include "Screen.h"

class PhysicsEngine {
private:
    //The different screens for this program
    std::map<ScreenStates, Screen> screens;

    //Objects that will be used in the main function
    sf::RenderWindow window;
    sf::Text text[5];
    sf::Sprite sprite[3];
    Button button[5];
    //sf::RectangleShape box[5];
    sf::Image image;
public:
    PhysicsEngine();
    ~PhysicsEngine();

    void run();

};

#endif //SFML_NEW_TEMPLATE_PHYSICSENGINE_H
