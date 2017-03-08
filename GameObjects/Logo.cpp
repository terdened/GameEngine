//
// Created by terde on 22.02.2017.
//

#include "Logo.h"
#include "../Core/ResourceManager/TextureResource.h"

using namespace sf;

void Logo::Update() {
    GameObject::Update();
    Rotate(1);
}

void Logo::Init(ResourceManager* resourceManager) {
    this->resourceManager = resourceManager;
    auto logo = std::make_shared<Sprite>();
    auto texture = this->resourceManager->GetElement<TextureResource>("logo")->Texture();
    logo->setTexture(*texture);
    AddShape(logo);
}