//
// Created by terde on 22.02.2017.
//

#include "Logo.h"
#include "../Core/ResourceManager/TextureResource.h"

using namespace sf;

void Logo::Update() {
    GameObject::Update();
    GameObject::Rotate(1);
}