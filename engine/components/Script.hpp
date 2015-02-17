#ifndef SCRIPT_HPP
#define	SCRIPT_HPP

#include "../Component.hpp"
#include "Transform.hpp"
#include "Renderer.hpp"
#include "Collider.hpp"
#include "RigidBody.hpp"

namespace gme{
    
class Script : public Component{
public:
    virtual void onGui(){};
    virtual void onMessage(std::string m, float v){};
    Transform *getTransform();
    Renderer *getRenderer();
    Collider *getCollider();
    RigidBody *getRigidBody();
private:

};

}

#endif	/* SCRIPT_HPP */

