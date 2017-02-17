//
// Created by terde on 03.02.2017.
//

#include "GameObject.h"
namespace GameEngine {

    void GameObject::Draw() {
        sf::Transform transform;
        transform.translate(x,y);
        transform.rotate(rotation);
        transform.scale(scaleX, scaleY);
        sf::RenderStates renderStates(transform);

        list<sf::Drawable*>::iterator shapeIter;
        for (shapeIter = shapes.begin(); shapeIter != shapes.end(); shapeIter++)
            renderWindow.draw(**shapeIter, renderStates);

        list<GameObject*>::iterator gameObjectIter;
        for (gameObjectIter = childs.begin(); gameObjectIter != childs.end(); gameObjectIter++)
            (**gameObjectIter).Draw();
    }

    void GameObject::Update() {
        list<GameObject*>::iterator iter;
        for (iter = childs.begin(); iter != childs.end(); iter++)
            (**iter).Update();
    }

    void GameObject::AddChild(GameObject* child) {
        childs.push_back(child);
    }

    void GameObject::AddShape(sf::Drawable* shape) {
        shapes.push_back(shape);
    }

    void GameObject::Move(sf::Vector2f delta) {
        x+=delta.x;
        y+=delta.y;
    }

    void GameObject::SwapDepth(GameObject *gameObject) {
        int tempDepth = gameObject->Depth();
        gameObject->Depth(depth);
        depth=tempDepth;
    }

    void GameObject::SetPosition(sf::Vector2f newPosition) {
        x = newPosition.x;
        y = newPosition.y;
    }

    void GameObject::Rotate(float value) {
        rotation+=value;
    }

    void GameObject::SetScale(sf::Vector2f scale) {
        scaleX = scale.x;
        scaleY = scale.y;
    }
}