//
// Created by terde on 27.01.2017.
//

#include "TileModel.h"
#include <stdlib.h>

namespace Match2048 {
    TileModel::TileModel() {
        int randomValue = rand() % 100;
        if(randomValue < 50) {
            value = 2;
        } else if(randomValue < 75) {
            value = 4;
        } else if(randomValue < 87) {
            value = 8;
        } else {
            value = 16;
        }
    }

    TileModel::TileModel(int value) {
        this->value = value;
    }

    void TileModel::MergeTileIntoThis(TileModel* outerTile) {
        if(outerTile->value != this->value)
            return;

        this->value *=2;
        outerTile->value;
    }

    bool TileModel::IsActive() {

    }
}