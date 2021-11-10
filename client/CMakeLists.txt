# Versao minima do cmake
cmake_minimum_required(VERSION 3.0)

# Nome do meu projeto
project(EA872)

find_library(SDL2_LIBRARY NAME SDL2)
find_library(SDL2_IMAGE_LIBRARY NAME SDL2)

#
add_executable(EA872 src/main.cpp)

# Especificar onde estao os header files
include_directories(include)
include_directories(../shared/include)

# Bibliotecas locais (estaticas)
add_library(coord ../shared/src/models/coord.cpp)
target_link_libraries(EA872 coord)
add_library(map ../shared/src/models/map.cpp)
target_link_libraries(EA872 map)
add_library(char ../shared/src/models/char.cpp)
target_link_libraries(EA872 char)
add_library(bomb_control src/controllers/bomb_control.cpp)
target_link_libraries(EA872 bomb_control)
add_library(movement src/controllers/movement.cpp)
target_link_libraries(EA872 movement)
add_library(save src/controllers/save.cpp)
target_link_libraries(EA872 save)
add_library(view src/view.cpp)
target_link_libraries(EA872 view)
add_library(texture ../shared/src/models/texture.cpp)
target_link_libraries(EA872 texture)
add_library(brick ../shared/src/models/brick.cpp)
target_link_libraries(EA872 brick)
add_library(block ../shared/src/models/block.cpp)
target_link_libraries(EA872 block)
add_library(bomb ../shared/src/models/bomb.cpp)
target_link_libraries(EA872 bomb)

# Garantir que usaremos C++11 (ou superior, se preciso)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Bibliotecas linkadas externamente
include_directories(EA872 ${SDL2_INCLUDE_DIRS})
include_directories(EA872 ${SDL2_IMAGE_INCLUDE_DIRS})
target_link_libraries(EA872 ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})
target_link_libraries(EA872 SDL2)
target_link_libraries(EA872 SDL2_image)

target_link_libraries(EA872 pthread)

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
