#include "Asteroid.hpp"
#include "asteroidController.hpp"

void Asteroid::setup() {
    
    getRenderer()->setTexture("space");
    if(rand()%2 == 1) getRenderer()->setFrame("meteor1");
    else getRenderer()->setFrame("meteor2");
    
    //getRenderer()->setPivot(gme::Vector2(1, 0.5));
    //getRenderer()->setCenter(gme::Vector2(1, 0.5));
    float size = 0.5 + rand()%30 / 100.f;
    
    getTransform()->setScale(gme::Vector2(size, size));
    getTransform()->setRotation(rand()%360);
    
    gme::RigidBody *rg = new gme::RigidBody;
    rg->setGravity(false);
    rg->isDynamic();
    //rg->isStatic();
    
    gme::BoxCollider *bc = new gme::BoxCollider;
    //bc->inheritRotation(true);
    bc->setSize(88*size, 69*size);
    
    addComponent(rg);
    addComponent(bc);
    
    addComponent(new asteroidController());
    
}


