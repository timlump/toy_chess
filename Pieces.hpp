#pragma once

enum class Colour { black, white};
enum class PieceType { pawn, knight, bishop, rook, queen, king};
enum class Action { simple_move, capture, castling};

#include <vector>
#include "Board.hpp"

struct Move
{
	Coord new_pos;
	Action action;
	// only used for capture or castling action
	Piece* other_piece = nullptr;
	// only used for setting other piece position during castling
	Coord other_pos;
};

class Piece
{
public:
	Piece(Coord pos, PieceType type, Colour colour) : piece_type(type), pos(pos), piece_colour(colour){}
	void move(Move move, Board* board);
	std::vector<Move> get_possible_moves(Board * board);

	PieceType piece_type;
	Coord pos;
	Colour piece_colour;
	bool captured = false;

private:
	std::vector<Move> get_pawn_moves(Board* board);
	std::vector<Move> get_knight_moves(Board* board);
	std::vector<Move> get_bishop_moves(Board* board);
	std::vector<Move> get_rook_moves(Board* board);
	std::vector<Move> get_queen_moves(Board* board);
	std::vector<Move> get_king_moves(Board* board);
};