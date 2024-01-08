//
// Created by Julio Anzaldo on 1/8/24.
//

#include "HelperFunctions.h"

sf::Vector2f HelperFunctions::add(const sf::Vector2f &b) {
    x += b.x;
    y += b.y;
}

sf::Vector2f HelperFunctions::sub(sf::Vector2f a, sf::Vector2f b) {
    return {a.x - b.x, a.y - b.y};
}

sf::Vector2f HelperFunctions::mult(sf::Vector2f v, float scalar) {
    return {v.x * scalar, v.y * scalar};
}

int HelperFunctions::magnitude(sf::Vector2f &v) {
    return std::sqrt(magnitudeSquared(v));
}

int HelperFunctions::magnitudeSquared(sf::Vector2f &v) {
    return v.x * v.x + v.y * v.y;
}

int HelperFunctions::normailize(sf::Vector2f &v) {
    float magnitude = magnitude(v);
    if (magnitude != 0) {
        mult(1 / magnitude);
    }
}

float HelperFunctions::dotProduct(sf::Vector2f &a, sf::Vector2f &b) {
    return a.x * b.x + a.y * b.y;
}

float HelperFunctions::dist(sf::Vector2f &a, sf::Vector2f &b) {
    return std::sqrt(distSquared(a, b));
}

float HelperFunctions::distSquared(sf::Vector2f &a, sf::Vector2f &b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

//From https://www.geeksforgeeks.org/fast-inverse-square-root/
float HelperFunctions::invSquared(float x) {
    const float threehalfs = 1.5F;

    float x2 = x * 0.5F;
    float y = x;

    // evil floating point bit level hacking
    long i = * ( long * ) &y;

    // value is pre-assumed
    i = 0x5f3759df - ( i >> 1 );
    y = * ( float * ) &i;

    // 1st iteration
    y = y * ( threehalfs - ( x2 * y * y ) );

    return y;
}
