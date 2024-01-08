//
// Created by Julio Anzaldo on 12/31/23.
//
#ifndef SFML_NEW_TEMPLATE_PHYSICSENGINE_CPP
#define SFML_NEW_TEMPLATE_PHYSICSENGINE_CPP
#include "PhysicsEngine.h"

PhysicsEngine::PhysicsEngine() {

}

PhysicsEngine::~PhysicsEngine() {

}

void PhysicsEngine::run()
{
    //This creates our project window
    sf::RenderWindow window(sf::VideoMode(2560, 1440), "Physics Engine Demo");
    window.setFramerateLimit(240);

    //Set the scale of our sprites to match the resolution of our screen
    sprite->setScale(5, 4.3);

    for(int i = 0; i < LASTSCREEN; i++)
    {
        screens[static_cast<ScreenStates>(i)] = (Screen(EQUATIONS,"Screen" + std::to_string(i + 1),
                                                        "OK", Fonts::getFont(ARIAL), window.getSize()));
    }

    //Initialize our screen system and set it to the first one
    ScreenStates screenStates = SCREEN1;

    //Set fonts for our all text objects
    for(auto & i : text)
        i.setFont(Fonts::getFont(ARIAL));

    //Our programs big while loop that handles all systems
    while (window.isOpen())
    {
        sf::Event event;

        button->eventHandler(window, event);

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            //Iterator for the screens
            std::map<ScreenStates, Screen>::iterator iter = screens.begin();

            //Event handlers for our sceens
            switch (screenStates) {
                case SCREEN1 : {

                }
                case SCREEN2 : {

                }
                case SCREEN3 : {

                }
                case LASTSCREEN : break;
            }
        }

        //This clears the screen
        window.clear(sf::Color::Black);

        //Handles operations based on current screen
        switch (screenStates) {
            case SCREEN1 : {
                sprite[0].setTexture(Images::getImage(EQUATIONS));

                button[0] = Button("Gravity Simulation", sf::Color(50, 50, 50, 100),
                                   sf::Color::White, {200, 100});

                for(const auto & i : sprite)
                    window.draw(i);

                for(const auto & i : button)
                    window.draw(i);
            }
            case SCREEN2 : {
                //sprite[0].setColor({0, 0, 128});
            }
            case SCREEN3 : {

            }
            case LASTSCREEN : break;
        }
        window.display();
    }
}

#endif