//
// Created by terde on 15.02.2017.
//

#include "MainScene.h"

#include "../GameObjects/Field.h"
#include "../Core/ResourceManager/ResourceManager.h"
#include "../GameObjects/Logo.h"
#include "../ResourceLoaders/MainSceneResourceLoader.h"

using namespace sf;

void MainScene::Update() {
    Scene::Update();
}

void MainScene::Init() {
    resourceManager = new ResourceManager(nullptr);
    resourceLoader = new MainSceneResourceLoader(resourceManager);
    resourceLoader->Load();

    Field *field = new Field(renderWindow);
    field->SetPosition(sf::Vector2f(350, 150));
    AddChild(field);

    auto logo = new Logo(renderWindow);
    logo->SetPosition(sf::Vector2f(15,15));
    logo->SetScale(sf::Vector2f(0.5f, 0.5f));
    logo->SetPivotPoint(sf::Vector2f(57.5f, 57.5f));
    AddChild(logo);
}