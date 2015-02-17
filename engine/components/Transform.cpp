#include "Transform.hpp"

#include "../GameObject.hpp"

using namespace gme;

gme::Vector2 Transform::getPosition(){
    gme::Vector2 v = position_v;
    if(gameObject()!= NULL && gameObject()->getParent() != NULL){
        v.x += gameObject()->getParent()->getTransform()->getPosition().x;
        v.y += gameObject()->getParent()->getTransform()->getPosition().y;
    }
    return v;
}

gme::Vector2 Transform::getPositionRelative(){
    return position_v;
}

float Transform::getRotation(){
    float f = rotation_v;
    if(gameObject()!= NULL && gameObject()->getParent() != NULL){
        f += gameObject()->getParent()->getTransform()->getRotation();
    }
    return rotation_v;
}

float Transform::getRotationRelative(){
    return rotation_v;
}

gme::Vector2 Transform::getScale(){
    gme::Vector2 v = scale_v;
    if(gameObject()!= NULL && gameObject()->getParent() != NULL){
        v.x *= gameObject()->getParent()->getTransform()->getScale().x;
        v.y *= gameObject()->getParent()->getTransform()->getScale().y;
    }
    return v;
}

gme::Vector2 Transform::getScaleRelative(){
    return scale_v;
}

float Transform::getZIndex(){
    return zIndex;
}

void Transform::setPosition(gme::Vector2 v){
  position_v = v;  
}

void Transform::setRotation(float f){
  rotation_v = f;  
}

void Transform::setScale(gme::Vector2 v){
  scale_v = v;  
}

void Transform::setZIndex(float f){
    zIndex = f;
}

void Transform::rotate(float i){
    rotation_v += i;
}

void Transform::scale(gme::Vector2 v){
    scale_v.x *= v.x;
    scale_v.y *= v.y;
}

void Transform::translate(gme::Vector2 v){
    position_v.x += v.x;
    position_v.y += v.y;
}

void Transform::lookAt(GameObject* g){
    //TO DO
}

void Transform::setup(){
    if(scale_v.x == 0 || scale_v.y == 0){
        scale_v = gme::Vector2(1,1);
    }
}

void Transform::update(){
    
}

