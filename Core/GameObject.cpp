//
// Created by terde on 03.02.2017.
//

#include "GameObject.h"
namespace GameEngine {
    void GameObject::Draw() {
        vector<sf::Shape>::iterator shapeIter;
        for (shapeIter = shapes.begin(); shapeIter < shapes.end(); shapeIter++)
            renderWindow.draw(*shapeIter);

        vector<GameObject>::iterator gameObjectIter;
        for (gameObjectIter = childs.begin(); gameObjectIter < childs.end(); gameObjectIter++)
            (*gameObjectIter).Draw();
    }

    virtual void GameObject::Update() {
        vector<GameObject>::iterator iter;
        for (iter = childs.begin(); iter < childs.end(); iter++)
            (*iter).Update();
    }

    void GameObject::AddChild(GameObject child) {
        childs.push_back(child);
    }

    void GameObject::AddShape(sf::Shape shape) {
        shape.push_back(shape);
    }
}