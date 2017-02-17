//
// Created by terde on 13.02.2017.
//

#include "Cell.h"

using namespace sf;

void Cell::Update() {
    GameObject::Update();
}

void Cell::Init() {
    RectangleShape* tile = new RectangleShape();
    tile->setPosition(3, 3);
    Vector2f size(94, 94);
    tile->setSize(size);
    tile->setFillColor(Color(237, 194, 46));
    AddShape(tile);
    SetPivotPoint(Vector2f(50, 50));
}