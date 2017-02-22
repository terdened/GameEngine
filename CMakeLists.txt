cmake_minimum_required(VERSION 3.6)
project(Game)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(SOURCE_FILES main.cpp Core/GameObject.cpp Core/GameObject.h GameObjects/Cell.cpp GameObjects/Cell.h Core/Scene.cpp Core/Scene.h Scenes/MainScene.cpp Scenes/MainScene.h GameObjects/Field.cpp GameObjects/Field.h Core/ResourceManager/Resource.cpp Core/ResourceManager/Resource.h Core/ResourceManager/ResourceManager.cpp Core/ResourceManager/ResourceManager.h Core/ResourceManager/FontResource.cpp Core/ResourceManager/FontResource.h)
add_executable(Game ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(Game ${SFML_LIBRARIES})
endif()