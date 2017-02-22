//
// Created by terde on 22.02.2017.
//

#include <SFML/Window/Mouse.hpp>
#include "RectangularSilhouette.h"

bool RectangularSilhouette::IsMouseOn() {
    float mouseX = sf::Mouse::getPosition().x;
    float mouseY = sf::Mouse::getPosition().y;

    return mouseX >= mouseX && mouseX <= mouseX + width
           && mouseY >= mouseY && mouseY <= mouseY + height;
}