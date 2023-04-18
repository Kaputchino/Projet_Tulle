cmake_minimum_required(VERSION 3.24)
set(CMAKE_CXX_STANDARD 17)
project(Projet_Tulle)

set(SHARED shared/common.h shared/Errors.cpp shared/Errors.h)
set(CORE_SRC core/sources/Personne.cpp core/sources/Chauffeur.cpp core/sources/Admin.cpp core/sources/Dispatcher.cpp core/sources/Trajet.cpp core/sources/Colis.cpp)
set(CORE_HEADER core/headers/Personne.h core/headers/Chauffeur.h core/headers/Admin.h core/headers/Dispatcher.h core/headers/Trajet.h core/headers/Colis.h)

# CREATING DIFFERENT EXECUTABLES
add_executable(Projet_Tulle applications/mainwindow.cpp)
add_executable(TESTS ${CORE_SRC} ${CORE_HEADER} ${SHARED} applications/tests_main.cpp)

# SETTING UP QT
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")
find_package(Qt5 COMPONENTS Core Widgets Quick Gui Sql REQUIRED)
MESSAGE(STATUS "DONT'T FORGET TO SET ~/Qt/[ver]/[compiler]/lib/cmake & ~/Qt/5.15.2/mingw81_64/bin to your PATH.")

target_link_libraries(Projet_Tulle Qt5::Core Qt5::Quick Qt5::Widgets Qt5::Gui Qt5::Sql)