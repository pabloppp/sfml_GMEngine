#include "JetParticle.hpp"
#include "particleDecay.hpp"
#include "scriptDePrueba.hpp"

void JetParticle::setup(){
    addTag("particle");
    getRenderer()->setTexture("particle1");
    getRenderer()->setSize(gme::Vector2(8,8));
    getTransform()->scale = gme::Vector2(3,3);
    addComponent(new particleDecay());
    
    addComponent(new gme::RigidBody());
    gme::CircleCollider *boxCollider = new gme::CircleCollider();
    boxCollider->setRadius(10);
    boxCollider->center.y = -10;
    boxCollider->addFilterTag("particle");
    boxCollider->inheritRotation(true);
    addComponent(boxCollider);
    getRigidBody()->friction *= 4;
    
    addComponent(new scriptDePrueba());
}

