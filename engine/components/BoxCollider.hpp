#ifndef BOXCOLLIDER_HPP
#define	BOXCOLLIDER_HPP

#include "Collider.hpp"

namespace gme{

class BoxCollider : public Collider{
public:
    void setup();
    void update();
    void setSize(Vector2 s);
    void setSize(float x, float y);
    void checkCollision(Collider *col);
    void render();
    std::vector<Vector2> getRotatedPoints();
    Vector2 getSize();
    float outerRadius;
    float innerRadius;
    bool checkPointIn(Vector2 m, Vector2 a, Vector2 b, Vector2 d);
    int orientation(Vector2 p, Vector2 q, Vector2 r);
private:
    sf::ConvexShape rectangle;
    Vector2 size;
};

}

#endif	/* BOXCOLLIDER_HPP */

