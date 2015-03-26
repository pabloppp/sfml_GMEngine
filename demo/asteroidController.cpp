#include "asteroidController.hpp"

void asteroidController::setup() {

}

void asteroidController::update() {

    if(getTransform()->getPosition().x > 640 + 50 )
        getTransform()->setPosition(gme::Vector2(-50, getTransform()->getPosition().y));
    if(getTransform()->getPosition().x < -50)
        getTransform()->setPosition(gme::Vector2(640 + 50, getTransform()->getPosition().y));
    
    if(getTransform()->getPosition().y > 480 + 50)
        getTransform()->setPosition(gme::Vector2(getTransform()->getPosition().x, -50));
    if(getTransform()->getPosition().y < -50)
        getTransform()->setPosition(gme::Vector2(getTransform()->getPosition().x, 480+50));
    
}

asteroidController::~asteroidController() {

}

void asteroidController::onCollision(gme::Collider* c) {

}
