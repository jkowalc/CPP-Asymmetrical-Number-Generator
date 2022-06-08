cmake_minimum_required(VERSION 3.0.0)
project(CPP-Asymmetrical-Number-Generator VERSION 0.1.0)

set(PROJECT_SOURCES Generator/Generator.h)

add_executable(CPP-Asymmetrical-Number-Generator main.cpp ${PROJECT_SOURCES})
