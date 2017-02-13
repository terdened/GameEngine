//
// Created by terde on 01.02.2017.
//

#ifndef GAME_TILEVIEW_H
#define GAME_TILEVIEW_H

#include <SFML/Graphics.hpp>
#include "BaseView.h"
#include "../Models/TileModel.h"
#include "../Models/BaseModel.h"
using namespace sf;

namespace Match2048{
    class TileView : BaseView{
    private:
        int positionX;
        int positionY;
        int tileSize;
        int offset;
        int tileOffset = 3;
        TileModel& model;
        Color GetColor(int value);
    public:
        TileView(TileModel& model, int x, int y, int tileSize, int offset): model(model),
                                                                            positionX(x),
                                                                            positionY(y),
                                                                            tileSize(tileSize),
                                                                            offset(offset)
        {};

        void Draw(RenderWindow& app);
    };
}


#endif //GAME_TILEVIEW_H
