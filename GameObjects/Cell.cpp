//
// Created by terde on 13.02.2017.
//

#include "Cell.h"
#include "../Core/Silhouette/RectangularSilhouette.h"
#include <sstream>

using namespace sf;

template < typename T > std::string to_string( const T& n )
{
    std::ostringstream stm;
    stm << n ;
    return stm.str();
}

void Cell::Update() {
    GameObject::Update();

    if(IsMouseOn())
        tile->setFillColor(Color(200,30,30));
    else
        tile->setFillColor(GetColor(value));
}

void Cell::Init(ResourceManager* resourceManager) {
    this->resourceManager = resourceManager;
    tile = std::make_shared<RectangleShape>();
    tile->setPosition(3, 3);
    Vector2f size(94, 94);
    tile->setSize(size);
    tile->setFillColor(GetColor(value));
    AddShape(tile);
    SetPivotPoint(Vector2f(50, 50));

    auto text = std::make_shared<Text>();
    sf::Font* font = this->resourceManager->GetElement<FontResource>("font")->Font();

    text->setFont(*font);

    String stringValue = to_string(value);
    text->setString(stringValue);
    text->setCharacterSize(32);

    int textLength = 18 * stringValue.getSize();
    int textLeftOffset = (100 - textLength)/2;
    int textTopOffset = (100 - 46)/2;

    auto silhouette = std::make_shared<RectangularSilhouette>(this, 100, 100);
    AddSilhouette(silhouette);

    text->setPosition(textLeftOffset, textTopOffset);

    AddShape(text);
}

Color Cell::GetColor(int value){
    switch (value){
        case 2:
            return Color(238, 228, 218);
        case 4:
            return Color(237, 224, 200);
        case 8:
            return Color(242, 177, 121);
        case 16:
            return Color(245, 149, 99);
        case 32:
            return Color(246, 124, 95);
        case 64:
            return Color(246, 94, 59);
        case 128:
            return Color(237, 207, 114);
        case 256:
            return Color(237, 204, 97);
        case 512:
            return Color(237, 200, 80);
        case 1024:
            return Color(237, 197, 63);
        case 2048:
            return Color(237, 194, 46);
        default:
            return Color(60, 58, 50);
    }

}