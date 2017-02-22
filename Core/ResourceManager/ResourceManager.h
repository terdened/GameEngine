//
// Created by terde on 19.02.2017.
//

#ifndef GAME_RESOURCEMANAGER_H
#define GAME_RESOURCEMANAGER_H
#include <stack>
#include <vector>
#include <string>
#include <algorithm>
#include "Resource.h"
#include "FontResource.h"

using namespace std;

class ResourceManager {
private:
    void (*createResource)(Resource**, const unsigned int, const string &, const string &);
    stack<unsigned int> handles;
    vector<Resource*> list;
public:
    ResourceManager(void (*createResource)(Resource**, const unsigned int, const string &, const string &)): createResource(createResource)
        {}
    ~ResourceManager();

    template <class TResource>
    unsigned int Add(const string& filename, const string& path = "./", const string& name = NULL) {
        unsigned int handle = 1;
        if(handles.size() > 0)
            handle = handles.top() + 1;

        TResource* newResource = new TResource(handle, filename, path, name);
        list.push_back(newResource);
        handles.push(handle);
    }

    vector<Resource*> List(){
        return list;
    };

    Resource* GetElement(const unsigned int handle);

    Resource* GetElement(const string& filename, const string& path);

    Resource* GetElement(const string& name);

    void Remove(const unsigned int handle);

    void EmptyList();
};


#endif //GAME_RESOURCEMANAGER_H
