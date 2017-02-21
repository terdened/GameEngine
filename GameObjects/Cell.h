//
// Created by terde on 13.02.2017.
//

#ifndef GAME_CELL_H
#define GAME_CELL_H

#include "../Core/GameObject.h"
#include "../Core/ResourceManager/ResourceManager.h"

using namespace GameEngine;

class Cell : public GameObject {
private:
    int value;
    sf::Color GetColor(int value);
public:
    Cell(sf::RenderWindow& app): GameObject(app), value(512)
        { }
    void Update();
    void Init(ResourceManager* resourceManager);
};


#endif //GAME_CELL_H
