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
    sf::RenderWindow window(sf::VideoMode(2560, 1440), "Physics Engine Demo");
    sprite->setScale(5, 4.3);

    for(int i = 0; i < LASTSCREEN; i++)
    {
        screens[static_cast<ScreenStates>(i)] = (Screen(EQUATIONS,"Screen" + std::to_string(i + 1),
                                                        "OK", Fonts::getFont(AGENT), window.getSize()));
    }

    ScreenStates screenStates = SCREEN1;

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            //Iterator for the screens
            std::map<ScreenStates, Screen>::iterator iter = screens.begin();
        }

        //This clears the screen 60 times a second
        window.clear(sf::Color::Black);

        switch (screenStates) {
            case SCREEN1 : {
                sprite[0].setTexture(Images::getImage(EQUATIONS));

                button[0] = Button("Gravity Simulation", sf::Color(50, 50, 50, 20),
                                   sf::Color::White, {300, 200});

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