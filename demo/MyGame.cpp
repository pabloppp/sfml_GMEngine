#include "MyGame.hpp"
#include "mainScene.hpp"

void MyGame::setup(){
    
    //enable debug colliders;
    //debugColliders = true;
    
    //Create all the scenes
    gme::Scene *sceneOne = new mainScene("mainScene");
    
    //Set the current one
    gme::Game::setCurrentScene("mainScene");

}

