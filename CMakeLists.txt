cmake_minimum_required(VERSION 3.24)
project(Projet_Tulle)

set(CMAKE_CXX_STANDARD 17)

add_executable(Projet_Tulle main.cpp Personne.cpp Personne.h Chauffeur.cpp Chauffeur.h Admin.cpp Admin.h Dispatcher.cpp Dispatcher.h Trajet.cpp Trajet.h Colis.cpp Colis.h)
