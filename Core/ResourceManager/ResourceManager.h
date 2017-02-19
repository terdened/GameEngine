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

using namespace std;

template<class TResource>
class ResourceManager {
private:
    void (*createResource)(TResource**, const unsigned int, const string &, const string &);
    stack<unsigned int> handles;
    vector<TResource*> list;
public:
    ResourceManager(void (*createResource)(TResource**, const unsigned int, const string &, const string &)): createResource(createResource)
        {}
    ~Resource();

    unsigned int Add(const string& name, const string& path = "./") {
        unsigned int handle = 1;
        if(handles.size() > 0)
            handle = handles.top() + 1;


        TResource* newResource = new TResource(handle, name, path);
        list.push_back(newResource);
        handles.push(handle);
    }

    TResource* GetElement(const unsigned int handle){
        vector<TResource*>::iterator element = find_if(list.begin(),list.end(),ResourceComparison(handle));
        return *element;
    }



    TResource* GetElement(const string& name, const string& path){
        vector<TResource*>::iterator element = find_if(list.begin(),list.end(),ResourceNameComparison(name, path));
        return *element;
    }

    void Remove(const unsigned int handle){
        vector<TResource*>::iterator element = remove_if(list.begin(),list.end(),ResourceComparison(handle));
    }

    void EmptyList();

    vector<TResource*> List(){
        return list;
    };

    struct ResourceComparison
    {
        explicit ResourceComparison(const unsigned int handle): handle(handle)
        { }
        inline bool operator()(const TResource & resource) const {
            return resource.Handle == handle;
        }
    private:
        unsigned int handle;
    };

    struct ResourceNameComparison
    {
        explicit ResourceNameComparison(const string& name, const string& path): name(name), path(path)
        { }
        inline bool operator()(const TResource & resource) const {
            return resource.name == name && resource.path == path;
        }
    private:
        string name;
        string path;
    };
};


#endif //GAME_RESOURCEMANAGER_H
