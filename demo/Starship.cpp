#include "Starship.hpp"
#include "MyGame.hpp"
#include "CustomScript.hpp"
#include "scriptDePrueba.hpp"

void Starship::setup(){
    
    //AÑADIMOS LOS SCRIPTS Y SE CUSTOMIZAN SI ES NECESARIO
    addTag("player");
    
    getRenderer()->setTexture("space");
    getRenderer()->setFrame("ship");
    //getRenderer()->setSize(gme::Vector2(32,32));
    CustomScript *script1 = new CustomScript();
    addComponent(script1);
    
    addComponent(new scriptDePrueba());
    
    addComponent(new gme::RigidBody());
    gme::BoxCollider *bc = new gme::BoxCollider();
    addComponent(bc);
    
    getCollider()->addFilterTag("particle");
    //getRigidBody()->setElasticity(1);
   
    gme::SoundPlayer *sp = new gme::SoundPlayer();
    
    sp->setSound("sound1");
    //sp->autoplay = true;
    sp->setVolume(0);
    sp->loop(true);
    addComponent(sp);
    
    getTransform()->scale = gme::Vector2(0.8,0.8);  
    
    
}


