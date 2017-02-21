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

    Resource* GetElement(const unsigned int handle){
        vector<Resource*>::iterator element = find_if(list.begin(),list.end(),ResourceComparison(handle));
        return *element;
    }



    Resource* GetElement(const string& filename, const string& path){
        vector<Resource*>::iterator element = find_if(list.begin(),list.end(),ResourceFilenameComparison(filename, path));
        return *element;
    }

    Resource* GetElement(const string& name){
        vector<Resource*>::iterator element = find_if(list.begin(),list.end(),ResourceNameComparison(name));
        return *element;
    }

    void Remove(const unsigned int handle){
        vector<Resource*>::iterator element = remove_if(list.begin(),list.end(),ResourceComparison(handle));
    }

    void EmptyList();

    vector<Resource*> List(){
        return list;
    };

    struct ResourceComparison
    {
        explicit ResourceComparison(const unsigned int handle): handle(handle)
        { }
        inline bool operator()(Resource* resource) const {
            return resource->Handle() == handle;
        }
    private:
        unsigned int handle;
    };

    struct ResourceFilenameComparison
    {
        explicit ResourceFilenameComparison(const string& filename, const string& path): filename(filename), path(path)
        { }
        inline bool operator()(Resource* resource) const {
            return resource->Filename() == filename && resource->Path() == path;
        }
    private:
        string filename;
        string path;
    };

    struct ResourceNameComparison
    {
        explicit ResourceNameComparison(const string& name): name(name)
        { }
        inline bool operator()(Resource* resource) const {
            return resource->Name() == name;
        }
    private:
        string name;
    };
};


#endif //GAME_RESOURCEMANAGER_H
