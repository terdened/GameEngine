//
// Created by terde on 15.02.2017.
//

#include "MainScene.h"

#include "../GameObjects/Cell.h"

using namespace sf;

void MainScene::Update() {

}

void MainScene::Init() {
    Cell cell(renderWindow);
    AddChild(cell);
}