#include <iostream>
#include "Scene.hpp"
#include "Game.hpp"

using namespace gme;

Scene::Scene(std::string n){
    name = n;
    Game::addScene(this);
}

Scene::Scene(const Scene& orig) {
}

Scene::~Scene() {   
    while(!gameObjects.empty()) delete gameObjects.back(), gameObjects.pop_back();
    std::cout << "Destroying scene" << std::endl;
}

void Scene::addGameObject(GameObject *g) {
    /*
    if(gameObjects.empty()) gameObjects.push_back(g);
    else{
        for(int i=0;i<gameObjects.size();i++){
            if(gameObjects.at(i)->getTransform()->getZIndex() > g->getTransform()->getZIndex()){
                gameObjects.insert(gameObjects.begin()+i, g);
                return;
            }
        }
        gameObjects.push_back(g);
    }
    */
    gameObjects.push_back(g);
    //gameObjects.back()->setup();
}

std::vector<GameObject*> *Scene::getGameObjects(){
    return &gameObjects;
}

void Scene::update(){
    //UPDATE SCRIPTS    
    for(int i = gameObjects.size()-1; i >= 0; i--){
        if(gameObjects.at(i)->isActive()) gameObjects.at(i)->update();
    }
    
    
    
    //RENDER    
    for(int i = gameObjects.size()-1; i >= 0; i--){
         if(gameObjects.at(i)->isActive()) gameObjects.at(i)->getRenderer()->update();
    }
}

void Scene::superSetup(){
    setup();
    for(int i = gameObjects.size()-1; i >= 0; i--) gameObjects.at(i)->setup();
    for(int i = gameObjects.size()-1; i >= 0; i--) gameObjects.at(i)->componentSetup();   
}

std::string Scene::getName(){
    return name;
}
