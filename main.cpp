#include <iostream>
#include "Chess.hpp"

int main()
{
	// set cmd to utf-8
	system("chcp 65001");
	ChessEngine chess;
	while (true) {
		chess.draw_current_state();
		std::getchar();
	}
	return 0;
}