#ifndef SCENE_HPP
#define	SCENE_HPP

#include <vector>

#include "GameObject.hpp"

namespace gme{

class Game;
    
class Scene {
public:
    Scene(std::string n = "scene");
    Scene(const Scene& orig);
    virtual ~Scene();
    void addGameObject(GameObject *g);
    std::vector<GameObject*> *getGameObjects();
    virtual void setup() = 0;
    void superSetup();
    void update();
    std::string getName();
    
private:
    std::vector<GameObject*> gameObjects;
    std::string name;
};

}

#endif	/* SCENE_HPP */

