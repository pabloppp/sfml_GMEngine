#include "Script.hpp"

using namespace gme;

#include "../GameObject.hpp"

Transform *Script::getTransform(){
    return gameObject()->getTransform();
}

Renderer *Script::getRenderer(){
    return gameObject()->getRenderer();
}

Collider *Script::getCollider(){
    return gameObject()->getCollider();    
}

RigidBody *Script::getRigidBody(){
    return gameObject()->getRigidBody();
}

