#ifndef CUSTOMSCRIPT_HPP
#define	CUSTOMSCRIPT_HPP

#include <iostream>
#include "../engine/GMEngine.hpp"

class CustomScript : public gme::Script{
public:
    void setup();
    void update();
    virtual ~CustomScript();
    void onGui();
    void onMessage(std::string s, float f);
    int contador;
    bool interruptor;
private:

};

#endif	/* CUSTOMSCRIPT_HPP */

