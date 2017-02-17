//
// Created by terde on 13.02.2017.
//

#include "Cell.h"

using namespace sf;

void Cell::Update() {
    GameObject::Update();
    Move(Vector2f(1,1));
}

void Cell::Init() {
    RectangleShape* tile = new RectangleShape();
    tile->setPosition(0, 0);
    Vector2f size(100, 100);
    tile->setSize(size);
    tile->setFillColor(Color(237, 194, 46));
    AddShape(tile);

    Font font;
    if (!font.loadFromFile("arial.ttf"))
    {
        //Error
    }

    Text* text = new Text();
    (*text).setFont(font);
    (*text).setString("2048");
    (*text).setCharacterSize(32);
    (*text).setPosition(15, 35);

    //AddShape(text);
}