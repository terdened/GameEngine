//
// Created by terde on 22.02.2017.
//

#ifndef GAME_LOGO_H
#define GAME_LOGO_H

#include "../Core/GameObject.h"
#include "../Core/ResourceManager/ResourceManager.h"

using namespace GameEngine;

class Logo : public GameObject{
public:
    Logo(sf::RenderWindow& app): GameObject(app)
    { }
    void Update();
    void Init(ResourceManager* resourceManager);
};


#endif //GAME_LOGO_H
