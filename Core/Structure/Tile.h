//
// Created by terde on 10.03.2017.
//

#ifndef GAME_TILE_H
#define GAME_TILE_H

#include <bits/shared_ptr.h>

namespace GameEngine {
    template<class tile_t>
    class Tile {
    private:
        std::shared_ptr<tile_t> tileObject;
        int positionX;
        int positionY;
        float size;
    };
}



#endif //GAME_TILE_H
