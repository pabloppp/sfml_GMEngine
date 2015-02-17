#ifndef CIRCLECOLLIDER_HPP
#define	CIRCLECOLLIDER_HPP

#include "Collider.hpp"

namespace gme{

class CircleCollider : public Collider{
public:
    CircleCollider();
    CircleCollider(const CircleCollider& orig);
    virtual ~CircleCollider();
private:

};

}

#endif	/* CIRCLECOLLIDER_HPP */

