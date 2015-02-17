#ifndef RIGIDBODY_HPP
#define	RIGIDBODY_HPP

#include "../Component.hpp"

namespace gme{
    
class RigidBody : public Component{
public:
    RigidBody();
    RigidBody(const RigidBody& orig);
    virtual ~RigidBody();
private:

};

}

#endif	/* RIGIDBODY_HPP */

