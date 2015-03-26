#ifndef ASTEROIDCONTROLLER_HPP
#define	ASTEROIDCONTROLLER_HPP

#include "../engine/GMEngine.hpp"


class asteroidController : public gme::Script{
public:

    virtual void setup();

    virtual void update();

    virtual ~asteroidController();
    

    virtual void onCollision(gme::Collider* c);



private:

};

#endif	/* ASTEROIDCONTROLLER_HPP */

