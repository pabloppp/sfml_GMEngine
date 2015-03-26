#include "CustomScript.hpp"
#include "JetParticle.hpp"

//OBLIGATORIOS
void CustomScript::setup(){
    if(getRigidBody() != NULL) getRigidBody()->setGravity(false);
    timeLapse = 0.1;
}

void CustomScript::update(){
    float deltaTime = gme::Game::deltaTime.asSeconds();
    
    //std::cout << gme::Mouse::getPosition().x << ": mouseX" << std::endl;
    
    gme::SoundPlayer *sp = (gme::SoundPlayer*)(gameObject()->getComponent<gme::SoundPlayer*>());
    
    if(sp != NULL && !spaceDown){
        if(gme::Keyboard::isKeyPressed(gme::Keyboard::Space)) {
            if(sp->isPlaying()) sp->stop();
            else sp->play();
        }
    }
    
    if(getRigidBody() != NULL){
        
        if(gme::Keyboard::isKeyPressed(gme::Keyboard::Space) && !spaceDown){
            if(getRigidBody()->hasGravity()) getRigidBody()->setGravity(false);
            else getRigidBody()->setGravity(true);
            spaceDown = true;
        }else if(!gme::Keyboard::isKeyPressed(gme::Keyboard::Space) && spaceDown){
            spaceDown = false;
        }
        
        if(gme::Keyboard::isKeyPressed(gme::Keyboard::Up)){
            getRigidBody()->pushImmediate(getTransform()->forward(), 200*deltaTime);
        }
        if(gme::Keyboard::isKeyPressed(gme::Keyboard::Down))
            getRigidBody()->pushImmediate(getTransform()->forward(), -100*deltaTime);
        
        if(gme::Keyboard::isKeyPressed(gme::Keyboard::Right))
            getRigidBody()->rotateImmediate(40*deltaTime);
        
        if(gme::Keyboard::isKeyPressed(gme::Keyboard::Left))
            getRigidBody()->rotateImmediate(-40*deltaTime);
        
        if(gme::Keyboard::isKeyPressed(gme::Keyboard::Up)){
            timeOut+=deltaTime;
            if(timeOut > timeLapse){
                timeOut = 0;
                
                gme::GameObject *particle = new JetParticle("particle");
                instantiate(particle);
                particle->getTransform()->setPosition(gme::Vector2(
                    getTransform()->position.x-getTransform()->forward().x*20,
                    getTransform()->position.y-getTransform()->forward().y*20
                ));
                particle->getTransform()->setRotation(getTransform()->rotation);
                
            }
        }

    }
    
    if(getTransform()->position.y > 480+23){
        getTransform()->position.y = 0-23;
    }
    else if(getTransform()->position.y < 0-23){
        getTransform()->position.y = 480+23;
    }
    
    if(getTransform()->position.x > 640+23) getTransform()->position.x = 0-23;
    else if(getTransform()->position.x < 0-23) getTransform()->position.x = 640+23;
   
    //std::cout << "GameObjects: " << gme::Game::getCurrentScene()->getGameObjects()->size() << std::endl;
}

//OPCIONALES
CustomScript::~CustomScript(){ //onDestroy
    //std::cout << "destruyendome" << std::endl;
}

void CustomScript::onGui(){
    //gme::GUI::backgroundColor = gme::GUI::red;
    /*gme::GUI::fontSize = 24;
    gme::GUI::outlineThickness = 1;
    gme::GUI::box(gme::Vector2(10,10), gme::Vector2(200,50), "MOCOSO" ,gme::GUI::Origin::TopLeft);
    gme::GUI::fontSize = 12;
    gme::GUI::label(gme::Vector2(320,0), "Level 1", gme::GUI::Origin::TopCenter);*/
    //gme::GUI::drawTexture(gme::Vector2(0,0), gme::Vector2(25,50), gme::GUI::TextureName("starship"), gme::GUI::Origin::TopLeft, gme::GUI::ScaleMode::ScaleAndCrop);
    //gme::GUI::drawTexture(gme::Vector2(0,0), gme::GUI::TextureName("starship"));
}

void CustomScript::onMessage(std::string m, float f){
    std::cout << "Recibido mensaje: " << m << " con valor: " << f << std::endl;
}

void CustomScript::onCollision(gme::Collider* c) {
    if(getRigidBody() != NULL){
        //((gme::BoxCollider*)getCollider())->setSize(30,30);
        //((gme::BoxCollider*)getCollider())->setCenter(0,-60);
        if(c->gameObject()->getName().compare("asteroid") == 0){           
            
            gme::Vector2 relativepos = getCollider()->getRelativePosition(c);
            
            if(relativepos.y == -1){
                //std::cout << getTransform()->rotation << std::endl;
                if(getTransform()->rotation > 45 || getTransform()->rotation < -45){
                    if(getTransform()->rotation > 45) getRigidBody()->rotateImmediate(-5);
                    else if(getTransform()->rotation < -45) getRigidBody()->rotateImmediate(5);
                }
            }
        }
        //((gme::BoxCollider*)(getCollider()))->isTrigger(true);
    }
}




