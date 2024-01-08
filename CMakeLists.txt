cmake_minimum_required(VERSION 3.21)
project(SFML_NEW_TEMPLATE)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp PhysicsEngine.cpp PhysicsEngine.h Images.h Images.cpp Screen.h Screen.cpp
       Button.h Button.cpp EnumNames.h States.h States.cpp Fonts.h Fonts.cpp Particle.cpp Particle.h
        QuadTree.h Collisions.cpp Collisions.h QuadTree.cpp Gravity.cpp Gravity.h HelperFunctions.cpp HelperFunctions.h)

add_executable(SFML_NEW_TEMPLATE ${SOURCE_FILES})
include_directories(/usr/local/include)

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(SFML_NEW_TEMPLATE sfml-system sfml-window sfml-graphics sfml-audio sfml-network)