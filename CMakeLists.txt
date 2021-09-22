# Versao minima do cmake
cmake_minimum_required(VERSION 3.0)

# Nome do meu projeto
project(Capivara)

find_library(SDL2_LIBRARY NAME SDL2)
find_library(SDL2_IMAGE_LIBRARY NAME SDL2)

#
add_executable(Capivara src/main.cpp)

# Especificar onde estao os header files
include_directories(include)


# Bibliotecas locais (estaticas)
add_library(model src/model.cpp)
target_link_libraries(Capivara model)
add_library(view src/view.cpp)
target_link_libraries(Capivara view)
add_library(controller src/controller.cpp)
target_link_libraries(Capivara controller)

# Garantir que usaremos C++11 (ou superior, se preciso)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Bibliotecas linkadas externamente
include_directories(Capivara ${SDL2_INCLUDE_DIRS})
include_directories(Capivara ${SDL2_IMAGE_INCLUDE_DIRS})
target_link_libraries(Capivara ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})
