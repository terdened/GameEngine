//
// Created by terde on 03.02.2017.
//

#ifndef GAME_GAMEOBJECT_H
#define GAME_GAMEOBJECT_H

#include <SFML/Graphics.hpp>

namespace GameEngine {
    class GameObject {
    private:
        sf::RenderWindow& renderWindow;
        std::vector<sf::Shape> shapes;
    public:
        GameObject(sf::RenderWindow& app): renderWindow(app)
        { }
        void Draw();
        virtual void Update() = 0;
    };
}


#endif //GAME_GAMEOBJECT_H
