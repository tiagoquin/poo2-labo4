cmake_minimum_required(VERSION 3.14)
project(poo2_labo4)

set(CMAKE_CXX_STANDARD 11)

add_executable(poo2_labo4 main.cpp Person/Person.cpp Person/Person.h Container/Container.cpp Container/Container.h Container/Boat.cpp Container/Boat.h Container/Bank.cpp Container/Bank.h Controller.cpp Controller.h)