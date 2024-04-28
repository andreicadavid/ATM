cmake_minimum_required(VERSION 3.24)
project(SDsem2)

set(CMAKE_CXX_STANDARD 23)

add_executable(SDsem2 main.cpp colectie.cpp colectie.h atm.cpp atm.h tranzactie.cpp tranzactie.h inout.h inout.cpp vectordinamic.cpp vectordinamic.h List.h)
