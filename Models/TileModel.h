//
// Created by terde on 27.01.2017.
//

#ifndef GAME_TILE_H
#define GAME_TILE_H

#include "BaseModel.h"

namespace Match2048 {
    class TileModel : BaseModel{
    private:
    public :
        TileModel();
        TileModel(int value);
        void MergeTileIntoThis(TileModel* outerTile);
        int value;
        bool IsActive();
    };
}

#endif //GAME_TILE_H
