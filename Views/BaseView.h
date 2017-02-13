//
// Created by terde on 01.02.2017.
//

#ifndef GAME_BASEVIEW_H
#define GAME_BASEVIEW_H


#include <SFML/Graphics.hpp>
#include "../Models/BaseModel.h"
using namespace sf;

namespace Match2048 {
    class BaseView {
    protected:
    public :
        virtual void Draw(RenderWindow& app) = 0;
    };
}


#endif //GAME_BASEVIEW_H
