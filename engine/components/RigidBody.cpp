#include <math.h>

#include "RigidBody.hpp"
#include "Transform.hpp"
#include "../GameObject.hpp"
#include "../Game.hpp"
#include "BoxCollider.hpp"

using namespace gme;

RigidBody::RigidBody() : Component::Component(){
    gravity = true;
    weight = 1;
    friction = 0.05;
    speed = 0;
    angularSpeed = 0;
}

void RigidBody::setup(){
}

void RigidBody::update(){
    float deltaTime = Game::deltaTime.asSeconds();
    
    if(gravity){
        speed.x += weight*gravityDirection.normalized().x*gravityForce*deltaTime*5;
        speed.y += weight*gravityDirection.normalized().y*gravityForce*deltaTime*5;
    }  
    
    if(friction != 0){   
        frictionV.x = speed.x*friction;
        frictionV.y = speed.y*friction;
        frictionA = angularSpeed*friction;       
    }
   
    //p->x += speed.x;
    //p->y += speed.y;
}

void RigidBody::updatep() {
    if(isKinematic) return;
    float deltaTime = Game::deltaTime.asSeconds();
    if(gameObject()!= NULL){
        gameObject()->getTransform()->position.x += speed.x*deltaTime*10;
        gameObject()->getTransform()->position.y += speed.y*deltaTime*10;
        if(!fixedRotation) gameObject()->getTransform()->rotation += angularSpeed*deltaTime*10;
    }
    speed.x += acceleration.x*deltaTime-frictionV.x;
    speed.y += acceleration.y*deltaTime-frictionV.y;
    angularSpeed += angularAcceleration*deltaTime-frictionA;
}

void RigidBody::push(Vector2 vector){
    float deltaTime = Game::deltaTime.asSeconds();
    speed.x += vector.x;
    speed.y += vector.y;
}

void RigidBody::push(Vector2 direction, float force){
    float deltaTime = Game::deltaTime.asSeconds();
    Vector2 vector = direction.normalized();
    vector.x *= force;
    vector.y *= force;
    push(vector);
}

void RigidBody::setGravity(bool g){
    gravity = g;
}

bool RigidBody::hasGravity(){
    return gravity;
}

void RigidBody::onCollision(Collider* c) {
    if(isKinematic || c->gameObject()->getRigidBody() == NULL || c->gameObject()->getRigidBody()->isKinematic)
        return;
    float r1, r2;
    if(dynamic_cast<BoxCollider*>(c)){
        r1 = ((BoxCollider*)c)->innerRadius;
        r2 = ((BoxCollider*)gameObject()->getCollider())->innerRadius;
    }
    float p1 = c->gameObject()->getTransform()->position.y;
    float p2 = gameObject()->getTransform()->position.y;
    float diff = (r1+r2)-abs(p2-p1);
    gameObject()->getTransform()->translate(Vector2(0, -(diff)));
    float pdiff = gameObject()->getTransform()->position.y-gameObject()->getTransform()->o_position.y;
    if(abs(pdiff) < 1) gameObject()->getTransform()->position = gameObject()->getTransform()->o_position;
    acceleration = Vector2(0,0);
    speed = Vector2(0,0);
}


float RigidBody::gravityForce = 9.81;

Vector2 RigidBody::gravityDirection(0,1);

