//
// Created by terde on 03.02.2017.
//

#ifndef GAME_GAMEOBJECT_H
#define GAME_GAMEOBJECT_H

#include <SFML/Graphics.hpp>

class GameObject {
private:
    sf::RenderWindow& renderWindow;
    sf::Shape* shapes;
public:
    GameObject(sf::RenderWindow& app): renderWindow(app)
    { }
    void Draw();
};


#endif //GAME_GAMEOBJECT_H
