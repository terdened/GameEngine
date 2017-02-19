//
// Created by terde on 19.02.2017.
//

#include "Resource.h"

void Resource::IncRef() {
    refCount++;
}

void Resource::DecRef() {
    refCount--;
}