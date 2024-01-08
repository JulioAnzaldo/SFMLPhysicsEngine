//
// Created by Julio Anzaldo on 1/8/24.
//

#ifndef SFML_NEW_TEMPLATE_HELPERFUNCTIONS_H
#define SFML_NEW_TEMPLATE_HELPERFUNCTIONS_H
#include "SFML/Graphics.hpp"
#include <cmath>

class HelperFunctions {
public:
    sf::Vector2f add(const sf::Vector2f& b);
    sf::Vector2f sub(sf::Vector2f a, sf::Vector2f b);
    sf::Vector2f mult(sf::Vector2f v, float scalar);

    int magnitude(sf::Vector2f& v);
    int magnitudeSquared(sf::Vector2f& v);
    int normailize(sf::Vector2f& v);

    float dotProduct(sf::Vector2f& a, sf::Vector2f& b);
    float dist(sf::Vector2f& a, sf::Vector2f& b);
    float distSquared(sf::Vector2f& a, sf::Vector2f& b);
    float invSquared(float x);
};


#endif //SFML_NEW_TEMPLATE_HELPERFUNCTIONS_H
