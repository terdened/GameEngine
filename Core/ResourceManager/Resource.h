//
// Created by terde on 19.02.2017.
//

#ifndef GAME_RESOURCE_H
#define GAME_RESOURCE_H
#include <string>

using namespace std;

class Resource {
private:
    string filename;
    unsigned int handle;
    string name;
    string path;
    unsigned long refCount;

public:
    Resource(const unsigned int handle, const string& filename, const string& path, const string& name):
            handle(handle), filename(filename), path(path), name(name)
        {}

    void DecRef();
    void IncRef();

    string Filename() {
        return filename;
    }

    unsigned int Handle() {
        return handle;
    }

    string Name() {
        return name;
    }

    string Path() {
        return path;
    }

    unsigned long RefCount() {
        return refCount;
    }

};


#endif //GAME_RESOURCE_H
