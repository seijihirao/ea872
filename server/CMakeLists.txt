# Versao minima do cmake
cmake_minimum_required(VERSION 3.0)

# Nome do meu projeto
project(ea872_server)

find_library(SDL2_LIBRARY NAME SDL2)
find_library(SDL2_IMAGE_LIBRARY NAME SDL2)

#
add_executable(ea872_server src/main.cpp)

# Especificar onde estao os header files
include_directories(../shared/include)
include_directories(include)

# Bibliotecas locais (estaticas)
add_library(sync src/controllers/sync.cpp)
target_link_libraries(ea872_server sync)
add_library(map ../shared/src/models/map.cpp)
target_link_libraries(ea872_server map)
add_library(coord ../shared/src/models/coord.cpp)
target_link_libraries(ea872_server coord)
add_library(char ../shared/src/models/char.cpp)
target_link_libraries(ea872_server char)
add_library(texture ../shared/src/models/texture.cpp)
target_link_libraries(ea872_server texture)
add_library(bomb ../shared/src/models/bomb.cpp)
target_link_libraries(ea872_server bomb)
add_library(block ../shared/src/models/block.cpp)
target_link_libraries(ea872_server brick)
add_library(brick ../shared/src/models/brick.cpp)
target_link_libraries(ea872_server block)

# Garantir que usaremos C++11 (ou superior, se preciso)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(ea872_server ${SDL2_INCLUDE_DIRS})
include_directories(ea872_server ${SDL2_IMAGE_INCLUDE_DIRS})
target_link_libraries(ea872_server ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})
target_link_libraries(ea872_server SDL2)
target_link_libraries(ea872_server SDL2_image)

target_link_libraries(ea872_server pthread)

# Automatizacao do Doxygen
find_package(Doxygen REQUIRED dot)

set(DOXYGEN_EXTRACT_ALL YES)
set(DOXYGEN_EXTRACT_PRIVATE YES)
set(DOXYGEN EXTRACT_STATIC YES)
set(DOXYGEN_TEMPLATE_RELATIONS YES)
set(DOXYGEN_COLLABORATION_GRAPH YES)
set(DOXYGEN_UML_LOOK YES)
set(DOXYGEN_CLASS_GRAPH YES)

doxygen_add_docs(doc)
