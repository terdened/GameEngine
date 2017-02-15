//
// Created by terde on 13.02.2017.
//

#include "Cell.h"

using namespace sf;

void Cell::Update() {

}

void Cell::Init() {
    RectangleShape rectangleShape;
    rectangleShape.setPosition(5, 5);
    Vector2f size(100, 100);
    rectangleShape.setSize(size);
    AddShape(rectangleShape);
}