#include "mainScene.hpp"
#include "FirstGameObject.hpp"
#include "CustomScript.hpp"

#include <SFML/Graphics.hpp>


void mainScene::setup(){
    
    //Podemos crear las texturas
    gme::Game::newTexture("resources/balon.png", "ball");
    gme::Game::newTexture("resources/cesped.png", "grass");
    
    //Creamos los objetos de la escena
    //y edición de los mismos
    
    gme::GameObject *gameObject = new FirstGameObject("player");
    gameObject->getRenderer()->setTexture("ball");
    gameObject->getTransform()->setPosition(gme::Vector2(100, 480));
    
    gme::GameObject *gameObject2 = new FirstGameObject("enemy");
    gameObject2->getRenderer()->setTexture("grass");
    gameObject->addChild(gameObject2);
    gameObject2->getTransform()->setPosition(gme::Vector2(200, 480));
    
}


