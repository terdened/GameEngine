//
// Created by terde on 19.02.2017.
//

#include "ResourceManager.h"

void ResourceManager::EmptyList() {
    list.clear();
    stack<unsigned int> empty;
    std::swap(handles, empty);
}

Resource* ResourceManager::GetElement(const unsigned int handle){
    auto element = find_if(list.begin(),list.end(),[&handle](Resource* resource) {return resource->Handle() == handle;});
    return *element;
}

Resource* ResourceManager::GetElement(const string& filename, const string& path){
    auto element = find_if(list.begin(),list.end(),[&filename, &path](Resource* resource) {return resource->Filename() == filename && resource->Path() == path;});
    return *element;
}

Resource* ResourceManager::GetElement(const string& name){
    auto element = find_if(list.begin(),list.end(),[&name](Resource* resource) {return resource->Name() == name;});
    return *element;
}

void ResourceManager::Remove(const unsigned int handle){
    remove_if(list.begin(),list.end(),[&handle](Resource* resource) {return resource->Handle() == handle;});
}