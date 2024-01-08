//
// Created by Julio Anzaldo on 1/7/24.
//

#include "Particle.h"

Particle::Particle() {
    particle.setFillColor({0, 0, 90});
    particle.setRadius(radius);
    particle.setPosition(0, 0);
    particle.
}

Particle::~Particle() {

}

Particle::Particle(sf::Vector2f pos, sf::Vector2f vel) {
    this->nextPos = pos;
    this->nextVel = vel;
    this->heat = 1;
}

void Particle::updateParticle() {

}

const sf::Vector2f Particle::getPos() {
    return pos;
}

const sf::Vector2f Particle::getVel() {
    return vel;
}

const sf::Vector2f Particle::getNextPos() {
    return nextPos;
}

const sf::Vector2f Particle::getNextVel() {
    return nextVel;
}

const float Particle::getHeat() {
    return heat;
}

sf::Vector2f Particle::setPos(const sf::Vector2f &v) {
    return pos = v;
}

sf::Vector2f Particle::setVel(const sf::Vector2f &v) {
    return vel = v;
}

sf::Vector2f Particle::setNextPos(const sf::Vector2f &v) {
    nextPos = v;
}

sf::Vector2f Particle::setNextVel(const sf::Vector2f &v) {
    nextVel = v;
}

void Particle::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(particle);
}
