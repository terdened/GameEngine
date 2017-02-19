//
// Created by terde on 19.02.2017.
//

#include "ResourceManager.h"

void ResourceManager::EmptyList() {
    list.clear();
    stack<unsigned int> empty;
    std::swap(handles, empty);
}