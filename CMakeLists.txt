cmake_minimum_required(VERSION 3.1)
project(toy-chess)

set(source_files
	Chess.hpp
	Chess.cpp)

add_executable(${PROJECT_NAME} main.cpp ${source_files})