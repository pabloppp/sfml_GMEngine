#ifndef CUSTOMSCRIPT_HPP
#define	CUSTOMSCRIPT_HPP

#include <iostream>
#include "../engine/GMEngine.hpp"

class CustomScript : public gme::Script{
public:
    CustomScript() : gme::Script(){
        b = 10;
    };
    void setup();
    void update();
    virtual ~CustomScript();
    void onGui();
    virtual void onMessage(std::string m, float v);
    virtual void onCollision(gme::Collider* c);
    void showMessage(std::string m);
    int a, b;
    
private:
    float timeOut;
    float timeLapse;
    bool spaceDown;

};

#endif	/* CUSTOMSCRIPT_HPP */

