//
// Created by terde on 19.02.2017.
//

#ifndef GAME_FONTRESOURCE_H
#define GAME_FONTRESOURCE_H


#include <SFML/Graphics/Font.hpp>
#include "Resource.h"

class FontResource : public Resource {
private:
    sf::Font* font;
public:
    FontResource(const unsigned int handle, const string& filename, const string& path, const string& name = NULL):
            Resource(handle, filename, path, name) {
        font = new sf::Font();
        if (!font->loadFromFile(path+filename))
            throw new std::exception;
    }

    sf::Font* Font() {
        return font;
    }
};


#endif //GAME_FONTRESOURCE_H
