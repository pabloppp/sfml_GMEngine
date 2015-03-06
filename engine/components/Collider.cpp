#include <unordered_map>

#include "Collider.hpp"
#include "Transform.hpp"

#include "../GameObject.hpp"
#include "math.h"

using namespace gme;

void Collider::addFilterTag(const std::string& tag){
    tagmap.insert(std::pair<std::string, std::string>(tag, tag));
}

void Collider::removeFilterTag(const std::string& tag){
    tagmap.erase(tag);
}

void Collider::inheritRotation(bool b){
    canRotate = b;
}

Vector2 Collider::getGlobalCenter(){
    
    return gameObject()->getTransform()->position;
    
}

void Collider::noticeCollision(Collider* col){
    debugColor = sf::Color::Red;
    colliding = true;
    gameObject()->onCollision(col);
}

bool Collider::checkTags(Collider *col){
    if(gameObject() != NULL && col->gameObject() != NULL){
        for ( auto it = tagmap.begin(); it != tagmap.end(); ++it ){
            if(col->gameObject()->getTags()->find(it->second) != col->gameObject()->getTags()->end()) return true;
        }
    }
    return false;
}
