//
// Created by Julio Anzaldo on 1/7/24.
//

#include "Collisions.h"

void Collisions::collide(Particle &a, Particle &b, std::vector<Particle>& particles, float dist) {
    if (dist > 2 * r) return;

    Vector dPos = sub(a.pos, b.pos);
    dPos.normalize();

    //Push-pull them apart
    float invHeatA = 1 / (a.getHeat() + 1);
    float invHeatB = 1 / (b.getHeat() + 1);
    Vector mtd = mult(dPos, (2 * r - dist) * invHeatA / (invHeatA + invHeatB));
    a.getNextPos().add(mtd);

    float impactSpeed = dot(sub(a.getVel(), b.getVel()), dPos);
    a.getHeat() += abs(impactSpeed) * 0.1;

    // If already moving away from each other, return
    if (impactSpeed > 0) {
        return;
    }

    sf::Vector2f force = mult(dPos, impactSpeed * (1 + restitution) * 0.5);
    a.getNextVel().sub(force);
}

void Collisions::collide(Particle &p, std::vector<Particle>& particles, QuadTree &tn) {
    // Collide with a particle
    if (tn.leaf) {
        if (tn.particle == NULL || p == tn.particle) return;

        float dist = dist(p.getPos(), tn.particle.getPos());
        collide(p, tn.particle, dist);
        return;
    }

    // Find which quadrant to collide with
    for (QuadTree child : tn.children) {
        bool outside = p.getPos().x + 2 * r < child.x || p.getPos().x - 2 * r > child.x + child.w
                          || p.pos.y + 2 * r < child.y || p.pos.y - 2 * r > child.y + child.w;
        if (!outside) {
            collide(p, child);
        }
    }
}

void Collisions::collide(std::vector<Particle> &particles, QuadTree &root) {
    for (Particle p : particles) {
        p.setNextPos(p.getPos());
        p.setNextVel(p.getVel());
    }
    for (Particle p : particles) {
        collide(p, root);
    }

    for (Particle p : particles) {
        p.setPos(p.getNextPos());
        p.setVel(p.getNextVel());
    }
}

void Collisions::updateParticles(std::vector<Particle> &particles) {

}
