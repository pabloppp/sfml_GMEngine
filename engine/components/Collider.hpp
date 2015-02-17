#ifndef COLLIDER_HPP
#define	COLLIDER_HPP

#include "../Component.hpp"

namespace gme{
    
class Collider : public Component{
public:
    Collider();
    Collider(const Collider& orig);
    virtual ~Collider();
private:

};

}

#endif	/* COLLIDER_H */

