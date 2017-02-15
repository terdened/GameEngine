//
// Created by terde on 15.02.2017.
//

#ifndef GAME_SCENE_H
#define GAME_SCENE_H

#include <SFML/Graphics.hpp>
#include "GameObject.h"

using namespace std;

namespace GameEngine {
    class Scene {
    private:
        vector<GameObject> childs;
    protected:
        sf::RenderWindow& renderWindow;
    public:
        Scene(sf::RenderWindow& app): renderWindow(app)
                { }
        void Draw();
        virtual void Update();
        virtual void Init() = 0;
        void AddChild(GameObject child);
    };
}


#endif //GAME_SCENE_H
