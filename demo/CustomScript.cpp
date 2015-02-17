#include "CustomScript.hpp"

//OBLIGATORIOS
void CustomScript::setup(){
    getRenderer()->setSize(sf::Vector2<float>(32,32));
}

void CustomScript::update(){
    
    float deltaTime = gme::Game::deltaTime.asSeconds();
    //Animacion del sprite
    gameObject()->getRenderer()->setFrame(sf::Vector2f(contador/2, 0));
    contador++;
    if(contador > 8) contador = 0;
    
    //Movimiento
    if(getTransform()->getPosition().y < 0){
    getTransform()->setPosition(
            gme::Vector2(getTransform()->getPositionRelative().x, 
            gme::Game::getWindow()->getSize().y)
            );    
    }
    
    getTransform()->translate(gme::Vector2(0, -200*deltaTime));
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) getTransform()->translate(gme::Vector2(80*deltaTime, 0));
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) getTransform()->translate(gme::Vector2(-80*deltaTime, 0)); 
    
    getTransform()->rotate(300*deltaTime);
}

//OPCIONALES
CustomScript::~CustomScript(){ //onDestroy
    //std::cout << "destruyendome" << std::endl;
}

void CustomScript::onGui(){
    
}

void CustomScript::onMessage(std::string s, float f){
    
}

