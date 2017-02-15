//
// Created by terde on 03.02.2017.
//

#ifndef GAME_GAMEOBJECT_H
#define GAME_GAMEOBJECT_H

#include <SFML/Graphics.hpp>
using namespace std;

namespace GameEngine {
    class GameObject {
    private:
        sf::RenderWindow& renderWindow;
        vector<sf::Shape> shapes;
        vector<GameObject> childs;
    public:
        GameObject(sf::RenderWindow& app): renderWindow(app)
        { }
        void Draw();
        virtual void Update();
        virtual void Init() = 0;
        void AddChild(GameObject child);
        void AddShape(sf::Shape shape);
    };

}


#endif //GAME_GAMEOBJECT_H
