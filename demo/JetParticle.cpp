#include "JetParticle.hpp"
#include "particleDecay.hpp"
#include "scriptDePrueba.hpp"

void JetParticle::setup(){
    
    addTag("particle");
    getRenderer()->setTexture("space");
    getRenderer()->setFrame("star3");
    getTransform()->scale = gme::Vector2(1,1);
    addComponent(new particleDecay());
    
    addComponent(new gme::RigidBody());
    getRigidBody()->setFriction(2);
    gme::BoxCollider *boxCollider = new gme::BoxCollider();
    boxCollider->setSize(20,20);
    //boxCollider->setRadius(10);
    boxCollider->addFilterTag("particle");
    //boxCollider->addFilterTag("player");
    //boxCollider->inheritRotation(true);
    //boxCollider->isTrigger(true);
    addComponent(boxCollider);
    
    addComponent(new scriptDePrueba());
    
    gme::GameObject::findWithTag("player").front()->sendMessageUpward("randomMessage", 15);
}

