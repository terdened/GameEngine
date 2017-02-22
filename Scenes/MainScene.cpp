//
// Created by terde on 15.02.2017.
//

#include "MainScene.h"

#include "../GameObjects/Field.h"
#include "../Core/ResourceManager/ResourceManager.h"

using namespace sf;

void MainScene::Update() {
    Scene::Update();
}

void MainScene::Init(ResourceManager* resourceManager) {
    this->resourceManager = resourceManager;
    Field *field = new Field(renderWindow);
    field->SetPosition(sf::Vector2f(350, 150));
    AddChild(field);
}