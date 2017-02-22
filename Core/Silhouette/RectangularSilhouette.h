//
// Created by terde on 22.02.2017.
//

#ifndef GAME_RECTANGULARSILHOUETTE_H
#define GAME_RECTANGULARSILHOUETTE_H


#include "Silhouette.h"

class RectangularSilhouette: public Silhouette {
protected:
    float width;
    float height;
public:
    RectangularSilhouette(float* x, float* y, float width, float height): Silhouette(x,y), width(width), height(height)
        {}

    bool IsMouseOn() override;
};


#endif //GAME_RECTANGULARSILHOUETTE_H
