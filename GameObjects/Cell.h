//
// Created by terde on 13.02.2017.
//

#ifndef GAME_CELL_H
#define GAME_CELL_H

#include "../Core/GameObject.h"

using namespace GameEngine;

class Cell : public GameObject {
private:
public:
    Cell(sf::RenderWindow& app): GameObject(app)
        { }
    void Update();
    void Init();
};


#endif //GAME_CELL_H
