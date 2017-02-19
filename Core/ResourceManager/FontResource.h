//
// Created by terde on 19.02.2017.
//

#ifndef GAME_FONTRESOURCE_H
#define GAME_FONTRESOURCE_H


#include <SFML/Graphics/Font.hpp>
#include "Resource.h"

class FontResource : Resource {
private:
    sf::Font font;
public:
    FontResource(const unsigned int handle, const string& name, const string& path): Resource(handle, name, path) {
        font = sf::Font();
        if (!font.loadFromFile(path+name))
            throw new std::exception;
    }

    sf::Font Font() {
        return font;
    }
};


#endif //GAME_FONTRESOURCE_H
