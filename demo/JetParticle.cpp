#include "JetParticle.hpp"
#include "particleDecay.hpp"

void JetParticle::setup(){
    getRenderer()->setTexture("particle1");
    getRenderer()->setSize(gme::Vector2(8,8));
    getTransform()->scale = gme::Vector2(3,3);
    particleDecay *script = new particleDecay();
    addComponent(script);
    
    addComponent(new gme::RigidBody());
    getRigidBody()->friction *= 4;
}

