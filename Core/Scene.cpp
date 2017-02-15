//
// Created by terde on 15.02.2017.
//

#include "Scene.h"
namespace GameEngine {
    void Scene::Draw() {
        vector<GameObject>::iterator gameObjectIter;
        for (gameObjectIter = childs.begin(); gameObjectIter < childs.end(); gameObjectIter++)
            (*gameObjectIter).Draw();
    }

    virtual void Scene::Update() {
        vector<GameObject>::iterator iter;
        for (iter = childs.begin(); iter < childs.end(); iter++)
            (*iter).Update();
    }

    void Scene::AddChild(GameObject child) {
        childs.push_back(child);
    }
}