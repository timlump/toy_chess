#pragma once

#include <vector>
class Piece;

struct Coord
{
	Coord()
	{
		x = 0;
		y = 0;
	}

	Coord(int _x, int _y)
	{
		x = _x;
		y = _y;
	}
	int x, y;

	bool operator==(const Coord& other) {
		return x == other.x && y == other.y;
	}
};
/*
	Origin of the board is bottom left
*/
class Board
{
public:
	Board();
	~Board();
	std::vector<Piece*> pieces;

	Piece* get_piece_at(Coord pos);
};