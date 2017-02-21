//
// Created by terde on 03.02.2017.
//

#ifndef GAME_GAMEOBJECT_H
#define GAME_GAMEOBJECT_H

#include <SFML/Graphics.hpp>
#include <list>
#include "ResourceManager/ResourceManager.h"

using namespace std;

namespace GameEngine {
    class GameObject {
    private:
        list<sf::Drawable*> shapes;
        list<GameObject*> childs;
        float x;
        float y;
        float rotation;
        float scaleX;
        float scaleY;
        int depth;
        string name;
        float pivotX;
        float pivotY;
    protected:
        sf::RenderWindow& renderWindow;
        ResourceManager* resourceManager;
    public:
        //creation functions
        GameObject(sf::RenderWindow& app): renderWindow(app), x(0), y(0), depth(0), name("untitled"), rotation(0),
                                           scaleX(1), scaleY(1), pivotX(0), pivotY(0)
            {    }
        virtual void Init(ResourceManager* resourceManager) = 0;

        //time erase functions
        void Draw(sf::Transform parentTransform);
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
        float Rotation() {
            return rotation;
        }
        void Rotation(float value) {
            rotation = value;
        }
        float ScaleX() {
            return scaleX;
        }
        void ScaleX(float value) {
            scaleX = value;
        }
        float ScaleY() {
            return scaleY;
        }
        void ScaleY(float value) {
            scaleY = value;
        }

        float PivotX() {
            return pivotX;
        }
        void PivotX(float value) {
            pivotX = value;
        }

        float PivotY() {
            return pivotY;
        }
        void PivotY(float value) {
            pivotY = value;
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
        void Rotate(float value);
        void SetScale(sf::Vector2f scale);
        void SetPivotPoint(sf::Vector2f pivotPoint);
    };

}


#endif //GAME_GAMEOBJECT_H
