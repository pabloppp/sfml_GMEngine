#include "Window.hpp"
#include <iostream>

using namespace gme;

Window::Window(int px, int py, std::string s){
    rwindow = new sf::RenderWindow(sf::VideoMode(px, py), s);
}

Window::~Window(){
    delete rwindow; 
}

void Window::draw(sf::Drawable &d){
    rwindow->draw(d);
}

bool Window::isOpen(){
    return rwindow->isOpen();
}

void Window::clear(){
    rwindow->clear();
}

void Window::display(){
    rwindow->display();
}

void Window::close(){
    rwindow->close();
}

bool Window::pollEvent(sf::Event &e){
    return rwindow->pollEvent(e);
}

void Window::setVerticalSyncEnabled(bool b){
    rwindow->setVerticalSyncEnabled(b);
}

gme::Vector2 Window::getSize(){
    //return rwindow->getSize();
    return gme::Vector2(rwindow->getSize().x, rwindow->getSize().y);
}