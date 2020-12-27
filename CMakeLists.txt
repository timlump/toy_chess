cmake_minimum_required(VERSION 3.15)
project(toy-chess)

set(source_files
	Chess.hpp
	Chess.cpp
	Pieces.hpp
	Pieces.cpp
	Board.hpp
	Board.cpp)

add_executable(${PROJECT_NAME} main.cpp ${source_files})