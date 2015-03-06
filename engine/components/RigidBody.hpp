#ifndef RIGIDBODY_HPP
#define	RIGIDBODY_HPP

#include "../Component.hpp"
#include "../facade/Vector2.hpp"
#include "Collider.hpp"

namespace gme{
    
class RigidBody : public Component{
public:
    RigidBody();
    void update();
    void updatep();
    void setup();
    static float gravityForce;
    static Vector2 gravityDirection;
    float elasticity;
    float weight;
    Vector2 acceleration;
    float angularAcceleration;
    Vector2 speed;
    float angularSpeed;
    float friction;
    void push(Vector2 vector);
    void push(Vector2 direction, float force);
    void setGravity(bool g);
    bool hasGravity();
    void onCollision(Collider *c);
    bool isKinematic;
private:
    bool gravity;
    bool fixedRotation;
    bool fixedTranslationX;
    bool fixedTranslationY;
    Vector2 frictionV;
    float frictionA;
};

}

#endif	/* RIGIDBODY_HPP */

