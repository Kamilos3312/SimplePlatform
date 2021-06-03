cmake_minimum_required(VERSION 3.20)
project(SimplePlatform)

set(CMAKE_CXX_STANDARD 17)

## SFML
## If you want to link SFML statically
set(SFML_STATIC_LIBRARIES TRUE)

## In most cases better set in the CMake cache
set(SFML_DIR "lib/sfml/lib/cmake/SFML")

find_package(SFML 2.5.1 COMPONENTS system window graphics audio REQUIRED)

include_directories(include)
file(GLOB SOURCES
        "include/*.hpp"
        "src/*.cpp"
        )

add_executable(SimplePlatform src/main.cpp ${SOURCES})

## SFML
target_link_libraries(SimplePlatform sfml-system sfml-window sfml-graphics sfml-audio)