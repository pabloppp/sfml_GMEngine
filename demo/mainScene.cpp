#include "mainScene.hpp"
#include "Starship.hpp"
#include "CustomScript.hpp"
#include "JetParticle.hpp"
#include "Asteroid.hpp"

#include <SFML/Graphics.hpp>


void mainScene::setup(){
    

    
    //Creamos los objetos de la escena
    //y edición de los mismos
    for(int i = 0; i < 0; i++){
        gme::GameObject *player = new Starship("starship");
        player->getTransform()->setPosition(gme::Vector2(rand()%640, rand()%480));    
        //player->getTransform()->setPosition(gme::Vector2(320+(i+1)*30, 240));    
    }
    
    gme::GameObject *player = new Starship("starship");
    player->getTransform()->setPosition(gme::Vector2(320, 240));
    
    gme::GameObject *ast = new Asteroid("asteroid");
    ast->getTransform()->setPosition(gme::Vector2(320, 470));

}


