//
// Created by terde on 01.02.2017.
//

#ifndef GAME_FIELDVIEW_H
#define GAME_FIELDVIEW_H

#include <SFML/Graphics.hpp>
#include "BaseView.h"
#include "TileView.h"
#include "../Models/FieldModel.h"
#include "../Models/BaseModel.h"
using namespace sf;

namespace Match2048{
    class FieldView : BaseView{
    private:
        FieldModel& model;
    public:
        FieldView(FieldModel& model): model(model)
        {};

        void Draw(RenderWindow& app)
        {
            int tileSize = app.getSize().y / model.heigth;
            int offset = (app.getSize().x - model.width * tileSize) / 2;

            for(int i = 0; i < model.heigth; i++){
                sf::Vertex line[] =
                        {
                                sf::Vertex(sf::Vector2f(offset, i * tileSize)),
                                sf::Vertex(sf::Vector2f(app.getSize().x - offset, i * tileSize))
                        };

                app.draw(line, 2, sf::Lines);
            }


            for(int i = 0; i < model.width + 1; i++){
                sf::Vertex line[] =
                        {
                                sf::Vertex(sf::Vector2f(i * tileSize + offset, 0)),
                                sf::Vertex(sf::Vector2f(i * tileSize + offset, app.getSize().y))
                        };

                app.draw(line, 2, sf::Lines);
            }

            for(int i = 0; i < model.heigth; i++){
                for(int j = 0; j < model.width; j++){
                    TileView tileView(model.tiles[i][j], j, i, tileSize, offset);
                    tileView.Draw(app);
                }
            }
        };
    };
}



#endif //GAME_FIELDVIEW_H
