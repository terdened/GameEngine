//
// Created by terde on 22.02.2017.
//

#include <SFML/Window/Mouse.hpp>
#include "RectangularSilhouette.h"
#include "../Structure/GameObject.h"

namespace GameEngine {
    bool RectangularSilhouette::IsMouseOn(sf::RenderWindow& renderWindow) {
        float mouseX = sf::Mouse::getPosition(renderWindow).x;
        float mouseY = sf::Mouse::getPosition(renderWindow).y;

        return mouseX >= gameObject->GlobalX() && mouseX <= gameObject->GlobalX() + width
               && mouseY >= gameObject->GlobalY() && mouseY <= gameObject->GlobalY() + height;
    }
}
