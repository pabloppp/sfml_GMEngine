#include "particleDecay.hpp"

void particleDecay::setup(){
  frames = 6;  
  fps = 10;  
}

void particleDecay::update(){   
    //std::cout << gme::GameObject::findWithTag("particle").size() << std::endl;
    float deltaTime = gme::Game::deltaTime.asSeconds();
    elapsedTime += deltaTime;
    if(elapsedTime >= 1.0/fps && frameCount < frames){        
        frameCount++;
        float scalefactor = 0.4+0.4*(frames-frameCount)/frames;
        float alfa = 255*(frames-frameCount)/frames;
        getRenderer()->setColor(255,255,255,alfa);
        getTransform()->scale = gme::Vector2(scalefactor,scalefactor);
        
        if(frameCount == 0) getRenderer()->setFrame("star3");
        else if(frameCount == 2) getRenderer()->setFrame("star2");
        else if(frameCount == 4) getRenderer()->setFrame("star1");
        elapsedTime = 0;
    }
    if(frameCount >= frames){
        //std::cout << "could not delete object" << std::endl;
        destroyGameObject(gameObject());
    }
    
}

