//
// Created by Julio Anzaldo on 1/7/24.
//

#ifndef SFML_NEW_TEMPLATE_QUADTREE_H
#define SFML_NEW_TEMPLATE_QUADTREE_H
#include "Particle.h"

class QuadTree {
public:
    std::vector<QuadTree> children; // Children objects
    Particle particle; //Particle object

    float x, y, w, totalMass; //Coords and mass
    bool leaf; //Is leaf

    sf::Vector2f totalCenter, center; // Total center of mass

    int count; // Number of particles

    //Constructor & destructor
    ~QuadTree();
    QuadTree(float x, float y, float w) : x(x), y(y), w(w), leaf(true), particle(), totalMass(0), count(0){
        totalCenter = sf::Vector2f(0, 0);
        center = sf::Vector2f(0, 0);
        children.resize(4);
    }

    QuadTree();;

    // Return index of child that contains given vector
    int which(sf::Vector2f v);

    //Insert new particle
    void insert(Particle newParticle);
    void split();

    //Draw quad tree
    virtual void draw(sf::RenderTarget& target) const;
};

#endif //SFML_NEW_TEMPLATE_QUADTREE_H
