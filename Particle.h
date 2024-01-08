//
// Created by Julio Anzaldo on 1/7/24.
//

#ifndef SFML_NEW_TEMPLATE_PARTICLE_H
#define SFML_NEW_TEMPLATE_PARTICLE_H
#include <SFML/Graphics.hpp>
#include "States.h"
#include "Fonts.h"

class Particle : public sf::Drawable, public States {
private:
    //Vector points for tracking position and velocity
    sf::Vector2f pos, vel, nextPos, nextVel;
    float heat, radius = 20;

    //Drawable circle shape for our particles
    sf::CircleShape particle;
public:
    //Constructors & destructor
    Particle();
    ~Particle();

    Particle(sf::Vector2f pos, sf::Vector2f vel);

    //Particle heat and collisions update function
    void updateParticle();

    //Retrieve position and velocity
    sf::Vector2f getPos();
    const sf::Vector2f getVel();
    const sf::Vector2f getNextPos();
    const sf::Vector2f getNextVel();
    const float getHeat();

    //Set next velocity and position
    sf::Vector2f setPos(const sf::Vector2f& v);
    sf::Vector2f setVel(const sf::Vector2f& v);
    sf::Vector2f setNextPos(const sf::Vector2f& v);
    sf::Vector2f setNextVel(const sf::Vector2f &v);

    void operator +=(sf::Vector2f& p);

    //Draw function
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};


#endif //SFML_NEW_TEMPLATE_PARTICLE_H
