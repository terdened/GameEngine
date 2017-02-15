//
// Created by terde on 15.02.2017.
//

#ifndef GAME_MAINSCENE_H
#define GAME_MAINSCENE_H

#include "../Core/Scene.h"

using  namespace GameEngine;

class MainScene : public Scene {

public:
    MainScene(sf::RenderWindow& app): Scene(app)
            { }
    void Update();
    virtual void Init();
};


#endif //GAME_MAINSCENE_H