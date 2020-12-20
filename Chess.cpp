#include "Chess.hpp"
#include <iostream>

ChessEngine::ChessEngine()
{
	init();
}

void ChessEngine::init()
{
	current_board.reset();
}

void ChessEngine::draw_current_state()
{

	for (int y = 7; y >=0 ; y--)
	{
		for (int x = 0; x < 8; x++) {
			unsigned char current_tile = current_board.tiles[x][y];
			// amusingly i'm using the black unicode square for white and vice versa
			// as it looks more correct
			if (current_tile == TILE_STATE_FLAGS::empty) {
				if (y % 2) {
					std::cout << ((x % 2) ? "\u25A1" : "\u25A0");
				}
				else {
					std::cout << ((x % 2) ? "\u25A0" : "\u25A1");
				}
			}
			else if (current_tile & TILE_STATE_FLAGS::pawn) {
				if (current_tile & TILE_STATE_FLAGS::black) {
					std::cout << "\u265F";
				}
				else {
					std::cout << "\u2659";
				}
			}
			else if (current_tile & TILE_STATE_FLAGS::rook) {
				if (current_tile & TILE_STATE_FLAGS::black) {
					std::cout << "\u265C";
				}
				else {
					std::cout << "\u2656";
				}
			}
			else if (current_tile & TILE_STATE_FLAGS::knight) {
				if (current_tile & TILE_STATE_FLAGS::black) {
					std::cout << "\u265E";
				}
				else {
					std::cout << "\u2658";
				}
			}
			else if (current_tile & TILE_STATE_FLAGS::bishop) {
				if (current_tile & TILE_STATE_FLAGS::black) {
					std::cout << "\u265D";
				}
				else {
					std::cout << "\u2657";
				}
			}
			else if (current_tile & TILE_STATE_FLAGS::queen) {
				if (current_tile & TILE_STATE_FLAGS::black) {
					std::cout << "\u265B";
				}
				else {
					std::cout << "\u2655";
				}
			}
			else if (current_tile & TILE_STATE_FLAGS::king) {
				if (current_tile & TILE_STATE_FLAGS::black) {
					std::cout << "\u265A";
				}
				else {
					std::cout << "\u2654";
				}
			}
			std::cout << " ";
		}
		std::cout << "|" << y + 1 << std::endl;
	}
	std::cout << "----------------\n";
	std::cout << "A B C D E F G H\n";
}