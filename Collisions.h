//
// Created by Julio Anzaldo on 1/7/24.
//

#ifndef SFML_NEW_TEMPLATE_COLLISIONS_H
#define SFML_NEW_TEMPLATE_COLLISIONS_H
#include "Gravity.h"

class Collisions : public HelperFunctions {
public:

    void collide(Particle& a, Particle& b, std::vector<Particle>& particles, float dist);
    void collide(Particle& p, std::vector<Particle>& particles, QuadTree& tn);
    void collide(std::vector<Particle>& particles, QuadTree& root);


    void updateParticles(std::vector<Particle>& particles);
};


#endif //SFML_NEW_TEMPLATE_COLLISIONS_H
