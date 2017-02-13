//
// Created by terde on 01.02.2017.
//

#include <string>
#include <sstream>
#include "TileView.h"

namespace Match2048 {
    template < typename T > std::string to_string( const T& n )
    {
        std::ostringstream stm;
        stm << n ;
        return stm.str() ;
    }

    Color TileView::GetColor(int value){
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

    void TileView::Draw(RenderWindow& app){
        RectangleShape rectangleShape;
        int cooridnatX = positionX * tileSize + offset + tileOffset;
        int cooridnatY = positionY * tileSize + tileOffset;
        rectangleShape.setPosition(cooridnatX + tileOffset, cooridnatY + tileOffset);
        Vector2f size(tileSize - tileOffset * 4,tileSize - tileOffset * 4);
        rectangleShape.setSize(size);
        rectangleShape.setFillColor(GetColor(model.value));
        app.draw(rectangleShape);

        Font font;
        if (!font.loadFromFile("arial.ttf"))
        {
            // error...
        }

        sf::Text text;
        text.setFont(font);

        String stringValue = to_string(model.value);
        text.setString(stringValue);
        text.setCharacterSize(32);
        int textLength = 30 * stringValue.getSize();
        int textLeftOffset = (tileSize - textLength)/2;
        int textTopOffset = (tileSize - 46)/2;

        text.setPosition(cooridnatX + tileOffset + textLeftOffset, cooridnatY + tileOffset + textTopOffset);
        app.draw(text);
    }
}