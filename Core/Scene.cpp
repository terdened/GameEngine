//
// Created by terde on 15.02.2017.
//

#include "Scene.h"
namespace GameEngine {
    void Scene::Draw() {
        list<GameObject*>::iterator gameObjectIter;
        for (gameObjectIter = childs.begin(); gameObjectIter != childs.end(); gameObjectIter++)
            (**gameObjectIter).Draw();
    }

    void Scene::Update() {
        list<GameObject*>::iterator gameObjectIter;
        for (gameObjectIter = childs.begin(); gameObjectIter != childs.end(); gameObjectIter++)
            (**gameObjectIter).Update();
    }

    void Scene::AddChild(GameObject* child) {
        childs.push_back(child);
    }
}