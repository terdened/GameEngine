//
// Created by terde on 22.02.2017.
//

#ifndef GAME_SILHOUETTE_H
#define GAME_SILHOUETTE_H


class Silhouette {
protected:
    float* x;
    float* y;
public:
    Silhouette(float* x, float* y): x(x), y(y)
        {}

    virtual bool IsMouseOn() = 0;
};


#endif //GAME_SILHOUETTE_H
