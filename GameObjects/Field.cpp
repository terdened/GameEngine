//
// Created by terde on 17.02.2017.
//

#include "Field.h"
#include "Cell.h"
#include "../Core/ResourceManager/ResourceManager.h"


using namespace sf;

void Field::Update() {
    GameObject::Update();
    //Rotate(1);
}

void Field::Init(ResourceManager* resourceManager) {
    this->resourceManager = resourceManager;
    RectangleShape* tile = new RectangleShape();
    Vector2f size(500, 500);
    tile->setSize(size);
    tile->setFillColor(Color(128, 128, 128));
    AddShape(tile);

    SetPivotPoint(Vector2f(250, 250));

    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            Cell* cell = new Cell(renderWindow);
            cell->SetPosition(sf::Vector2f(j*100, i*100));
            AddChild(cell);
        }
    }
}