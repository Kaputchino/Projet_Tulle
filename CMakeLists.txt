cmake_minimum_required(VERSION 3.25)
project(Projet_Tulle)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp Personne.cpp Chauffeur.cpp Admin.cpp Dispatcher.cpp Trajet.cpp Colis.cpp)
set(HEADER_FILES  Personne.h Chauffeur.h Admin.h Dispatcher.h Trajet.h Colis.h)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")

find_package(Qt5 COMPONENTS Core Widgets REQUIRED)
add_executable(Projet_Tulle ${SOURCE_FILES} ${HEADER_FILES})

target_link_libraries(Projet_Tulle Qt5::Core Qt5::Widgets)
MESSAGE(STATUS "DONT'T FORGET TO SET ~/Qt/[ver]/[compiler]/lib/cmake & ~/Qt/5.15.2/mingw81_64/bin to your PATH.")