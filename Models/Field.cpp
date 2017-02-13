//
// Created by terde on 27.01.2017.
//

#include "FieldModel.h"
namespace Match2048 {

    FieldModel::FieldModel(int width, int height) : width(width), heigth(height) {
        tiles = new TileModel *[height];

        for (int i = 0; i < height; i++)
            tiles[i] = new TileModel[width];
    }
}
