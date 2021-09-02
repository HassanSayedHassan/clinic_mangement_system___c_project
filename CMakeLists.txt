cmake_minimum_required(VERSION 3.19)
project(clinic_mangement_system C)

set(CMAKE_C_STANDARD 99)

add_executable(clinic_mangement_system main.c include/GLOBAL_VARIABLE.h include/FUNCTIONS_PROTOTYPES.h include/FUNCTIONS_BODY.h)