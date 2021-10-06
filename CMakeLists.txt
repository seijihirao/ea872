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

# Bibliotecas locais (estaticas)
add_library(coord src/models/coord.cpp)
target_link_libraries(EA872 coord)
add_library(map src/models/map.cpp)
target_link_libraries(EA872 map)
add_library(char src/models/char.cpp)
target_link_libraries(EA872 char)
add_library(movement src/controllers/movement.cpp)
target_link_libraries(EA872 movement)
add_library(view src/view.cpp)
target_link_libraries(EA872 view)
add_library(texture src/models/texture.cpp)
target_link_libraries(EA872 texture)
add_library(brick src/models/brick.cpp)
target_link_libraries(EA872 brick)

# Garantir que usaremos C++11 (ou superior, se preciso)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Bibliotecas linkadas externamente
include_directories(EA872 ${SDL2_INCLUDE_DIRS})
include_directories(EA872 ${SDL2_IMAGE_INCLUDE_DIRS})
target_link_libraries(EA872 ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})
target_link_libraries(EA872 SDL2)
target_link_libraries(EA872 SDL2_image)

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
