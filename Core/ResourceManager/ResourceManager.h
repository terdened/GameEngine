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

namespace GameEngine {
    class ResourceManager {
    private:
        void (*createResource)(Resource **, const unsigned int, const string &, const string &);

        stack<unsigned int> handles;
        vector<Resource *> list;
    public:
        ResourceManager(void (*createResource)(Resource **, const unsigned int, const string &, const string &))
                : createResource(createResource) {}

        ~ResourceManager();

        template<class TResource>
        unsigned int Add(const string &filename, const string &path = "./", const string &name = NULL) {
            unsigned int handle = 1;
            if (handles.size() > 0)
                handle = handles.top() + 1;

            TResource *newResource = new TResource(handle, filename, path, name);
            list.push_back(newResource);
            handles.push(handle);
        }

        template<class TResource>
        TResource *GetElement(const unsigned int handle) {
            auto element = find_if(list.begin(), list.end(),
                                   [&handle](Resource *resource) { return resource->Handle() == handle; });
            return (TResource *) *element;
        }

        template<class TResource>
        TResource *GetElement(const string &filename, const string &path) {
            auto element = find_if(list.begin(), list.end(), [&filename, &path](Resource *resource) {
                return resource->Filename() == filename && resource->Path() == path;
            });
            return (TResource *) *element;
        }

        template<class TResource>
        TResource *GetElement(const string &name) {
            auto element = find_if(list.begin(), list.end(),
                                   [&name](Resource *resource) { return resource->Name() == name; });
            return (TResource *) *element;
        }

        vector<Resource *> List() {
            return list;
        };

        void Remove(const unsigned int handle);

        void EmptyList();
    };
}


#endif //GAME_RESOURCEMANAGER_H
