#ifndef COLLIDER_HPP
#define	COLLIDER_HPP

#include "../Component.hpp"
#include "../facade/Vector2.hpp"
#include <unordered_map>

namespace gme{
    
class Collider : public Component{
public:
    virtual void checkCollision(Collider *col) = 0;
    void inheritRotation(bool b);
    void addFilterTag(const std::string &tag);
    void removeFilterTag(const std::string &tag);
    virtual void render() = 0;
    Vector2 getGlobalCenter();
    void noticeCollision(Collider *col);
    bool checkTags(Collider *col);
    bool checked;
private:

protected:
    bool canRotate;
    bool colliding;
    sf::Color debugColor;
    std::unordered_map<std::string, std::string> tagmap;
    float ownerRot;
    Vector2 ownerRotDisp;

    
};

}

#endif	/* COLLIDER_H */

