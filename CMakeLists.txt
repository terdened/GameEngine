cmake_minimum_required(VERSION 3.6)
project(Game)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(SOURCE_FILES main.cpp Core/Structure/GameObject.cpp Core/Structure/GameObject.h GameObjects/Cell.cpp GameObjects/Cell.h Core/Structure/Scene.cpp Core/Structure/Scene.h Scenes/MainScene.cpp Scenes/MainScene.h GameObjects/Field.cpp GameObjects/Field.h Core/ResourceManager/Resource.cpp Core/ResourceManager/Resource.h Core/ResourceManager/ResourceManager.cpp Core/ResourceManager/ResourceManager.h Core/ResourceManager/FontResource.cpp Core/ResourceManager/FontResource.h Core/ResourceManager/TextureResource.cpp Core/ResourceManager/TextureResource.h GameObjects/Logo.cpp GameObjects/Logo.h Core/ResourceManager/ResourceLoader.cpp Core/ResourceManager/ResourceLoader.h ResourceLoaders/MainSceneResourceLoader.cpp ResourceLoaders/MainSceneResourceLoader.h Core/Silhouette/Silhouette.cpp Core/Silhouette/Silhouette.h Core/Silhouette/RectangularSilhouette.cpp Core/Silhouette/RectangularSilhouette.h Core/Structure/Sprite.cpp Core/Structure/Sprite.h Core/Structure/Tile.cpp Core/Structure/Tile.h)
add_executable(Game ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(Game ${SFML_LIBRARIES})
endif()