#include <iostream>
#include <algorithm>

#include "GameObject.hpp"
#include "Scene.hpp"
#include "Game.hpp"

#include "components/Transform.hpp"
#include "components/Renderer.hpp"
#include "components/Collider.hpp"
#include "components/RigidBody.hpp"
#include "components/Script.hpp"

using namespace gme;

GameObject::GameObject(std::string n) {
    name = n;
    active = true;
    parent = NULL;
    transform = new Transform();
    transform->setGameObject(this);
    renderer = new Renderer();
    renderer->setGameObject(this);
    collider = NULL;
    rigidBody = NULL;
    Game::getCurrentScene()->addGameObject(this);
}

GameObject::GameObject(const GameObject& orig) {
    
}

std::string GameObject::getName(){
    return name;
}

GameObject::~GameObject() {
    while(!components.empty())delete components.back(), components.pop_back();
    //std::cout << "Destroying object " << name << std::endl;
}

void GameObject::update(){
    for(int i = components.size()-1; i >= 0; i--){
        if(components.at(i)->isActive()) components.at(i)->update();
    }
}

void GameObject::addTag(std::string t){
    tags.push_back(t);
}

std::vector<std::string> *GameObject::getTags(){
    return &tags;
}

std::vector<GameObject*> GameObject::findWithTag(std::string s){
    std::vector<GameObject*> *vect;
    std::vector<GameObject*> result;
    vect = Game::getCurrentScene()->getGameObjects();
    
    for(int i=0;i<vect->size();i++){
        std::vector<std::string> *tags = vect->at(i)->getTags();
        for(int j=0;j<tags->size();j++){
            if(tags->at(j).compare(s) == 0) result.push_back(vect->at(i));
        }
    }
    return result;
}

std::vector<GameObject*> GameObject::find(std::string s){
    std::vector<GameObject*> *vect;
    std::vector<GameObject*> result;
    vect = Game::getCurrentScene()->getGameObjects();
    
    for(int i=0;i<vect->size();i++){
        if(vect->at(i)->getName().compare(s) == 0) result.push_back(vect->at(i));
    }
    return result;
}

// TO DO
void GameObject::sendMessage(std::string s, float f){
    //...
}

void GameObject::broadcastMessage(std::string s, float f){
    //...
}
//~~~~

void GameObject::addComponent(Component* c){
    if(dynamic_cast<Script*>(c)){
        c->setGameObject(this);
        components.push_back(c);
    }
    else if(dynamic_cast<Transform*>(c)){
        std::cout << "GameObject already owns a transform" << std::endl;
    }
    else if(dynamic_cast<Renderer*>(c)){
        std::cout << "GameObject already owns a renderer" << std::endl;
    }
    else if(dynamic_cast<Collider*>(c)){
        c->setGameObject(this);
        collider = (Collider*)c;
    }
    else if(dynamic_cast<RigidBody*>(c)){
        c->setGameObject(this);
        rigidBody = (RigidBody*)c;
    }
    else{
        std::cout << "Unknown component type" << std::endl; 
    }
}

void GameObject::componentSetup(){
    transform->setup();
    renderer->setup();
    if(collider != NULL) collider->setup();
    if(rigidBody != NULL) rigidBody->setup();
    for(int i=0;i<components.size();i++) components.at(i)->setup();
}

/*
template <class T> Component *GameObject::getComponent(){
    for(int i=0;i<components.size();i++){
        if( dynamic_cast<T>(components.at(i)) ) return components.at(i);
    }
    return NULL;
}
*/
 
void GameObject::setActive(bool b){
    active = b;
}

bool GameObject::isActive(){
    return active;
}

void GameObject::setParent(GameObject *g){
    if(parent != NULL){
        parent->removeChild(this);
    }
    bool isChidren = false;
    for(int i=0;i<g->children.size();i++){
        if(g->children.at(i) == this){
            isChidren = true; 
            break;
        }
    }
    if(!isChidren) g->addChild(this);
    parent = g;   
}

GameObject *GameObject::getParent(){
    return parent;
}

void GameObject::addChild(GameObject *g){
    children.push_back(g);
    if(g->getParent() != this) g->setParent(this);    
}

std::vector<GameObject*> GameObject::getChildren(){
    return children;
}

void GameObject::removeChild(GameObject* g){
    for(int i=0;i<children.size();i++){
        if(children.at(i) == g){
            children.erase(children.begin()+i);
            return;
        }
    }
}

Transform *GameObject::getTransform(){
    return transform;
}

RigidBody *GameObject::getRigidBody(){
    return rigidBody;
}

Renderer *GameObject::getRenderer(){
    return renderer;
}

Collider *GameObject::getCollider(){
    return collider;
}