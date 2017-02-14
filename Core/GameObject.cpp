//
// Created by terde on 03.02.2017.
//

#include "GameObject.h"
namespace GameEngine {
    void GameObject::Draw() {
        for(int i = 0; i < shapes.size(); i++) {
            renderWindow.draw(shapes[i]);
        }
    }
}