//
// Created by terde on 22.02.2017.
//

#include "MainSceneResourceLoader.h"
#include "../Core/ResourceManager/TextureResource.h"

void MainSceneResourceLoader::Load() {
    resourceManager->Add<FontResource>("arial.ttf", "font", "./");
    resourceManager->Add<TextureResource>("logo.jpg", "logo", "./");
}