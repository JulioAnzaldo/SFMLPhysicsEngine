//
// Created by Julio Anzaldo on 1/7/24.
//

#ifndef SFML_NEW_TEMPLATE_GRAVITY_H
#define SFML_NEW_TEMPLATE_GRAVITY_H
#include "QuadTree.h"

class Gravity {
public:
    std::vector<Particle> particles;
    QuadTree root;

    int N; // Number of particles
    float radius, mass, G, theta, restitution,
            initBounds, initVel, dt; // Radius, time step, initial velocity, mass, etc.

    sf::CircleShape circle;

    //Camera values
    float cam_x, cam_y, to_x, to_y;
    float zoom, tozoom, xOffset, yOffset;
    float dzoom = 0.5; // Change in zoom amount

    //Constructors
    Gravity();
    ~Gravity();
    Gravity(QuadTree root);
    Gravity(sf::RenderWindow &window, QuadTree root);

    void update();
    void gravitate(Particle& p, QuadTree& tn);

    float distSquared(sf::Vector2f a, sf::Vector2f b);

    //Helper functions
    sf::Vector2f gravityAcc(sf::Vector2f a, sf::Vector2f b, float m_b);
    sf::Vector2f sub(sf::Vector2f a, sf::Vector2f b);
    sf::Vector2f mult(sf::Vector2f v, float scalar);
};


#endif //SFML_NEW_TEMPLATE_GRAVITY_H
