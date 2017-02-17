//
// Created by terde on 15.02.2017.
//

#include "MainScene.h"

#include "../GameObjects/Field.h"

using namespace sf;

void MainScene::Update() {
    Scene::Update();
}

void MainScene::Init() {
    Field *field = new Field(renderWindow);
    field->Init();
    field->SetPosition(sf::Vector2f(350, 150));
    AddChild(field);
}