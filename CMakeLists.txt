cmake_minimum_required(VERSION 3.6)
project(Game)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Models/TileModel.cpp Models/TileModel.h Models/Field.cpp Models/FieldModel.h Models/BaseModel.cpp Models/BaseModel.h Views/BaseView.cpp Views/BaseView.h Views/FieldView.cpp Views/FieldView.h Views/TileView.cpp Views/TileView.h Core/GameObject.cpp Core/GameObject.h GameObjects/Cell.cpp GameObjects/Cell.h)
add_executable(Game ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(Game ${SFML_LIBRARIES})
endif()