#include <iostream>
#include "Scene.hpp"
#include "Game.hpp"
#include "gameobjects/Camera.hpp"

#include <math.h>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>

using namespace gme;

Scene::Scene(std::string n){
    name = n;
    Game::addScene(this);
    Game::mainCamera = new Camera("mainCamera");
    updateClock.restart();
    gameObjects.reserve(99999);
    Vector2 wsize = Game::getWindow()->getSize();
    cGrid = CollisionGrid(-wsize.x/2.,-wsize.y/2.0,2*wsize.x,2*wsize.y, 4);
}

void Scene::setCollisionGrid(float px, float py, float sx, float sy, int div) {
    cGrid = CollisionGrid(px, py, sx, sy, div);
}


Scene::Scene(const Scene& orig) {
}

Scene::~Scene() {   
    while(!gameObjects.empty()) delete gameObjects.back(), gameObjects.pop_back();
    std::cout << "Destroying scene" << std::endl;
}

void Scene::addGameObject(GameObject *g) {
    gameObjects.push_back(g);
}

void Scene::destroyGameObject(GameObject* g){
    for(int i=0;i<gameObjects.size();i++){
        if(gameObjects.at(i) == g){
            gameObjects.at(i) = gameObjects.back();
            gameObjects.pop_back();
            delete g;
            return;
        }
    }
    
}

void Scene::instantiate(GameObject* g){
    g->setup();
    g->componentSetup();
}

std::vector<GameObject*> *Scene::getGameObjects(){
    return &gameObjects;
}

void Scene::update(){
    //UPDATE SCRIPTS
    Vector2 windowSize = Game::getWindow()->getSize();
    
    
    Vector2 mainCenter( ((Camera*)Game::mainCamera)->getPosition().x, ((Camera*)Game::mainCamera)->getPosition().y );
    Vector2 mainSize = ((Camera*)Game::mainCamera)->getSize();
    
    mainView.setCenter(mainCenter.x+windowSize.x/2, mainCenter.y+windowSize.y/2);
    mainView.setSize(640, 480);
    //std::cout << mainSize.x << " WOWOWOWOW" << std::endl;
    mainView.setSize(mainSize.x*windowSize.x, mainSize.y*windowSize.y);
        
    Game::getWindow()->setView(mainView);
     
            
    float updateTime = 1.0/30.0;
    float now = updateClock.currentTime().asSeconds();
    float frameTime = now - lastTime;
        
    while(frameTime > updateTime){   
        
        cGrid.clear();    
        Game::deltaTime = updateTime;
        //Fixed update
        for(int i = gameObjects.size()-1; i >= 0; i--){
            if(gameObjects.at(i)->isActive()){
                gameObjects.at(i)->fixedUpdate();
                cGrid.addObject( gameObjects.at(i) );
            }
        }
        //Collisions
        //int colCount = 0;
        for(int i = gameObjects.size()-1; i >= 0; i--){
            if(gameObjects.at(i)->getCollider() != NULL){
                Vector2 center = gameObjects.at(i)->getTransform()->position;
                std::vector<gme::GameObject*> objectsAtP = cGrid.getObjectsAt(center.x, center.y);    
                //std::cout << objectsAtP.size() << std::endl;
                for(int j=0;j<objectsAtP.size();j++){
                    if(objectsAtP.at(j) != gameObjects.at(i) && 
                       objectsAtP.at(j) != NULL && 
                       objectsAtP.at(j)->getCollider() != NULL){
                        gameObjects.at(i)->getCollider()->checkCollision(objectsAtP.at(j)->getCollider());
                        //colCount++;
                        
                    }
                }
                
            }
        }
        
        //update
        for(int i = gameObjects.size()-1; i >= 0; i--){
            if(gameObjects.at(i)->isActive()) gameObjects.at(i)->update();
        }
        
        
        frameTime -= updateTime;
   
    }
    
    
    lastTime = now - frameTime;
        
    Game::ticPercent = fmin(1.f, updateClock.currentTime().asSeconds()/frameTime);     
    //RENDER 
    Game::getWindow()->clear();
    for(int i = gameObjects.size()-1; i >= 0; i--){
         if(gameObjects.at(i)->isActive()) gameObjects.at(i)->getRenderer()->update();
    }

    Game::getWindow()->setView(Game::getWindow()->getDefaultView());
    for(int i = gameObjects.size()-1; i >= 0; i--){     
        if(gameObjects.at(i)->isActive()) gameObjects.at(i)->drawGui();
    }
    if(Game::debugColliders) cGrid.display();
    Game::getWindow()->display();
    
    //std::cout << "fixed fps: " << 1.0/Game::deltaTime.asSeconds() << std::endl;
    //std::cout << "fps: " << 1.0/Game::unfixedDeltaTime.asSeconds() << std::endl;

}

void Scene::superSetup(){
    setup();
    for(int i = gameObjects.size()-1; i >= 0; i--) gameObjects.at(i)->setup();
    for(int i = gameObjects.size()-1; i >= 0; i--) gameObjects.at(i)->componentSetup();   
}

std::string Scene::getName(){
    return name;
}
