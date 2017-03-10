//
// Created by terde on 22.02.2017.
//

#ifndef GAME_LOGO_H
#define GAME_LOGO_H

#include "../Core/ResourceManager/ResourceManager.h"
#include "../Core/Structure/Sprite.h"

using namespace GameEngine;

class Logo : public SpriteGameObject{
public:
    Logo(sf::RenderWindow& app, string resourceName): SpriteGameObject(app, resourceName)
        {   }
    void Update();
};


#endif //GAME_LOGO_H
