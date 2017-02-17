//
// Created by terde on 03.02.2017.
//

#ifndef GAME_GAMEOBJECT_H
#define GAME_GAMEOBJECT_H

#include <SFML/Graphics.hpp>
#include <list>

using namespace std;

namespace GameEngine {
    class GameObject {
    private:
        sf::RenderWindow& renderWindow;
        list<sf::Drawable*> shapes;
        list<GameObject*> childs;
        float x;
        float y;
        int depth;
        string name;
    public:
        //creation functions
        GameObject(sf::RenderWindow& app): renderWindow(app), x(0), y(0), depth(0), name("untitled")
            {    }
        virtual void Init() = 0;

        //time erase functions
        void Draw();
        virtual void Update();

        //structure functions
        void AddChild(GameObject* child);
        void AddShape(sf::Drawable* shape);

        //field accessors
        float X() {
            return x;
        }
        void X(float value) {
            x = value;
        }
        float Y() {
            return y;
        }
        void Y(float value) {
            y = value;
        }
        int Depth() {
            return depth;
        }
        void Depth(int value) {
            depth = value;
        }
        string Name() {
            return name;
        }
        void Name(string value) {
            name = value;
        }

        //Modificators
        void Move(sf::Vector2f delta);
        void SwapDepth(GameObject* gameObject);
        void SetPosition(sf::Vector2f newPosition);

    };

}


#endif //GAME_GAMEOBJECT_H
