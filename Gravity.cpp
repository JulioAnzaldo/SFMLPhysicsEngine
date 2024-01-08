//
// Created by Julio Anzaldo on 1/7/24.
//

#include "Gravity.h"

Gravity::Gravity() {
    N = 0; //Num of particles
    radius = 10; //Default radius
    mass = 1; //Will set all particles to such mass
    G = 0.01; // Gravitational constant
    theta = 0.7; // Constant used for Barnes-Hut
    restitution = 0.2;
    initVel = 0.1;
    dt = 1;

    //Camera
    zoom = 1;
    tozoom = 1;
    xOffset = 0;
    yOffset = 0;

    //Clear prev particles
    particles.clear();
    particles.resize(N);

    // Initialize particles
    for (int i = 0; i < N; ++i) {
        particles[i].getPos() = sf::Vector2f(random(-initBounds, initBounds), random(-initBounds, initBounds));
        particles[i].getVel() = sf::Vector2f(random(-initVel, initVel), random(-initVel, initVel));
    }
}

Gravity::Gravity(QuadTree root) : root(root) {

}

Gravity::Gravity(sf::RenderWindow &window, QuadTree root) : root(root) {
    //Bounds of simulation
    initBounds = window.getSize().x / 2;

    //Camera
    to_x = window.getSize().x / 2;
    to_y = window.getSize().y / 2;
    cam_x = window.getSize().x / 2;
    cam_y = window.getSize().y / 2;

    // Graphics
    circle = sf::CircleShape(radius);
    circle.setOutlineThickness(2 * radius);
    circle.setOutlineColor(sf::Color::White);

    // Initialize root
    root = QuadTree(0, 0, window.getSize().x);
    for (const Particle& particle : particles) {
        root.insert(particle);
    }
}

Gravity::~Gravity() {

}

void Gravity::update() {
    for (Particle& particle : particles) {
        gravitate(particle, root);
    }
}

void Gravity::gravitate(Particle &p, QuadTree &tn) {
    if (tn.leaf) {
        if (tn.particle.getPos() == sf::Vector2f(0, 0) || &p == &tn.particle) return;
        p.getVel() += gravityAcc(tn.particle.getPos(), p.getVel(), mass);
        return;
    }

    if (tn.center == sf::Vector2f(0, 0)) {
        tn.center = mult(tn.totalCenter, 1.0f / tn.count);
    }
    if (tn.w / dist(p.getPos(), tn.center) < theta) {
        p.getVel() += gravityAcc(tn.center, p.getPos(), tn.totalMass);
        return;
    }

    for (QuadTree &child: tn.children) {
        gravitate(p, child);
    }
}

float Gravity::distSquared(sf::Vector2f a, sf::Vector2f b) {
    float dx = a.x - b.x;
    float dy = a.y - b.y;
    return dx * dx + dy * dy;
}

sf::Vector2f Gravity::gravityAcc(sf::Vector2f a, sf::Vector2f b, float m_b) {
    float dSq = distSquared(a, b);
    if (dSq <= 4 * radius * radius) {
        return {0, 0};
    }
    return mult(sub(a, b), dt * G * m_b / (dSq * sqrt(dSq)));
}
