#ifndef WINDOW_HPP
#define	WINDOW_HPP

#include <SFML/Graphics.hpp>

#include "Vector2.hpp"

namespace gme{
    
class Window{
public:
    Window(int px, int py, std::string s);
    virtual ~Window();
    void draw(sf::Drawable &d);
    bool isOpen();
    void clear();
    void display();
    void close();
    void setVerticalSyncEnabled(bool b);
    bool pollEvent(sf::Event &e);
    gme::Vector2 getSize();
private:
    sf::RenderWindow *rwindow;
};

}

#endif	/* WINDOW_HPP */

