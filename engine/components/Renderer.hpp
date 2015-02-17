#ifndef RENDERER_HPP
#define	RENDERER_HPP

#include "../Component.hpp"
#include "../facade/Texture.hpp"
#include "SFML/Graphics.hpp"

namespace gme{
    
//class Game;    
    
class Renderer : public Component{
public:    
    void setup();
    void update();
    void setTexture(Texture &t);
    void setTexture(const std::string &s);
    void setSize(sf::Vector2<float> f);
    void setFrame(sf::Vector2<float> f);
    void setCenter(sf::Vector2<float> f);
private:
    sf::Vector2<float> size;
    sf::Vector2<float> center;
    sf::Vector2<float> position;
    sf::Drawable *drawable;

};

}

#endif	/* RENDERER_HPP */

