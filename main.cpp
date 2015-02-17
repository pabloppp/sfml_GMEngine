#include <stdio.h>
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

#include "engine/GMEngine.hpp"
#include "demo/MyGame.hpp"

/*
 * 
 */

int main() {
    
    //Creamos el juego con las dimensiones de ventana que queramos
    gme::Game *game = new MyGame(sf::Vector2f(640, 480), "my Game");  
    
    game->run();
    
    delete game;
    
    return 0;
}

