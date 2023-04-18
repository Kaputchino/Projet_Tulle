cmake_minimum_required(VERSION 3.25)
project(Projet_Tulle)
project(TESTS)

set(SHARED common.h)
set(CORE_SRC core/source/Personne.cpp core/source/Chauffeur.cpp core/source/Admin.cpp core/source/Dispatcher.cpp core/source/Trajet.cpp core/source/Colis.cpp)
set(CORE_HEADER core/header/Personne.h core/header/Chauffeur.h core/header/Admin.h core/header/Dispatcher.h core/header/Trajet.h core/header/Colis.h)

# CREATING DIFFERENT EXECUTABLES
add_executable(Projet_Tulle main.cpp)
add_executable(TESTS ${CORE_SRC} ${CORE_HEADER} ${SHARED} tests_main.cpp)

# SETTING UP QT
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")
find_package(Qt5 COMPONENTS Core Widgets REQUIRED)
target_link_libraries(Projet_Tulle Qt5::Core Qt5::Widgets)
MESSAGE(STATUS "DONT'T FORGET TO SET ~/Qt/[ver]/[compiler]/lib/cmake & ~/Qt/5.15.2/mingw81_64/bin to your PATH.")
