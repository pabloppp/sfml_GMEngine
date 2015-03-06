#include "Asteroid.hpp"

void Asteroid::setup() {
    gme::BoxCollider *bc = new gme::BoxCollider;
    //bc->inheritRotation(true);
    bc->setSize(640, 20);
    getTransform()->rotation = 0;
    addComponent(bc);
    gme::RigidBody *rg = new gme::RigidBody;
    rg->setGravity(false);
    addComponent(rg);
}


