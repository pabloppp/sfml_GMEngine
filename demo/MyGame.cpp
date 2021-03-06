#include "MyGame.hpp"
#include "mainScene.hpp"

void MyGame::setup(){
    
    //enable debug colliders;
    debugColliders = true;
    
    //Podemos crear las texturas
    gme::Game::newTexture("demo/resources/spaceassets.png", "space");
    
    gme::Game::newSound("demo/resources/in.wav", "sound1");
    
    //Create all the scenes
    gme::Scene *sceneOne = new mainScene("mainScene");
    
    //Set the current one
    gme::Game::setCurrentScene("mainScene");

}

