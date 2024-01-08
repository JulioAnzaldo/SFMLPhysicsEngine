//
// Created by Julio Anzaldo on 1/7/24.
//

#ifndef SFML_NEW_TEMPLATE_QUADTREE_CPP
#define SFML_NEW_TEMPLATE_QUADTREE_CPP

#include "QuadTree.h"

QuadTree::~QuadTree() {

}

int QuadTree::which(sf::Vector2f v) {
    float halfWidth = w * 0.5;
    if (v.y < y + halfWidth) {
        return v.x < x + halfWidth ? 0 : 1;
    }
    return v.x < x + halfWidth ? 2 : 3;
}

void QuadTree::split() {
    float newWidth = w * 0.5;
    children[0] = QuadTree(x, y, newWidth);
    children[1] = QuadTree(x + newWidth, y, newWidth);
    children[2] = QuadTree(x, y + newWidth, newWidth);
    children[3] = QuadTree(x + newWidth, y + newWidth, newWidth);
    leaf = false;
}

void QuadTree::insert(Particle newParticle) {
    if (leaf) {
        // Case: Leaf already contains another particle
        if (particle.getPos() != sf::Vector2f(0, 0)) {
            Particle a = particle;
            Particle b = newParticle;

            totalCenter += b.getPos();
            totalMass += mass;
            count++;

            QuadTree cur = *this;
            int qA = cur.which(a.getPos());
            int qB = cur.which(b.getPos());
            while (qA == qB) {
                cur.split();
                cur = cur.children[qA];
                qA = cur.which(a.getPos());
                qB = cur.which(b.getPos());

                // Update total center and mass
                cur.totalCenter += a.getPos();
                cur.totalCenter += b.getPos();
                cur.totalMass += mass * 2;
                cur.count += 2;
            }

            cur.split();
            cur.children[qA].particle = a;
            cur.children[qB].particle = b;

            // Update center of mass and total for the lowest-level child
            cur.children[qA].totalCenter += a.getPos();
            cur.children[qB].totalCenter += b.getPos();
            cur.children[qA].totalMass += mass;
            cur.children[qB].totalMass += mass;
            cur.children[qA].count++;
            cur.children[qB].count++;

            particle.pos = sf::Vector2f(0, 0);
            return;
        }

        particle = newParticle;
        totalCenter += newParticle.getPos();
        totalMass += mass;
        count++;
        return;
    }

    // Not a leaf
    totalCenter += newParticle.getPos();
    totalMass += mass;
    count++;
    children[which(newParticle.getPos())].insert(newParticle);
}

void QuadTree::draw(sf::RenderTarget &target) const {
    if (w < 100) {
        if (leaf) return;

        if (!leaf && count == 0) {
            // Adjust as needed
            sf::CircleShape circle(10);
            circle.setPosition(x, y);
            circle.setFillColor(sf::Color(0, 0, 90, 100));
            target.draw(circle);
        }
        else {
            // Adjust as needed
            sf::RectangleShape rect(sf::Vector2f(w, w));
            rect.setPosition(x, y);
            rect.setOutlineColor(sf::Color::White);
            rect.setOutlineThickness(1);
            target.draw(rect);
        }

        // Adjust as needed
        sf::Font font;
        font.loadFromFile("Arial.ttf");  // Load a suitable font


        sf::Text text(std::to_string(count), font);
        text.setCharacterSize(12);
        text.setPosition(x + w / 2, y + w / 2);
        text.setFillColor(sf::Color::White);
        target.draw(text);

        center = totalCenter / static_cast<float>(count);
        if (center != sf::Vector2f(0, 0)) {
            // Adjust as needed
            sf::CircleShape point(5);
            point.setPosition(center.x, center.y);
            point.setFillColor(sf::Color(255, 0, 0));
            target.draw(point);
        }
    }

    if (!leaf) {
        for (QuadTree tn : children) {
            tn.draw(target);
        }
    }
}

QuadTree::QuadTree() {}

#endif