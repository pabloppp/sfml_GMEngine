#ifndef BOXCOLLIDER_HPP
#define	BOXCOLLIDER_HPP

#include "Collider.hpp"

namespace gme{

class BoxCollider : public Collider{
public:
    BoxCollider();
    BoxCollider(const BoxCollider& orig);
    virtual ~BoxCollider();
private:

};

}

#endif	/* BOXCOLLIDER_HPP */

