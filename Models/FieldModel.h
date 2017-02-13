//
// Created by terde on 27.01.2017.
//

#ifndef GAME_FIELD_H
#define GAME_FIELD_H


#include "TileModel.h"
#include "BaseModel.h"

namespace Match2048 {
    class FieldModel : BaseModel{
        public:
            int heigth;
            int width;
            TileModel **tiles;
        public:
        FieldModel(int width, int height);
    };
};



#endif //GAME_FIELD_H
