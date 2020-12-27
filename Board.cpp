#include "Board.hpp"
#include "Pieces.hpp"

Board::Board()
{
	// setup pawns
	for (int x = 0; x < 8; x++) {
		Coord pos;
		pos.x = x;
		pos.y = 1;
		pieces.push_back(new Piece(pos, PieceType::pawn, Colour::white));
		pos.y = 6;
		pieces.push_back(new Piece(pos, PieceType::pawn, Colour::black));
	}

	// setup minor pieces
	pieces.push_back(new Piece(Coord(1, 0), PieceType::knight, Colour::white));
	pieces.push_back(new Piece(Coord(6, 0), PieceType::knight, Colour::white));
	pieces.push_back(new Piece(Coord(1, 7), PieceType::knight, Colour::black));
	pieces.push_back(new Piece(Coord(6, 7), PieceType::knight, Colour::black));

	pieces.push_back(new Piece(Coord(2, 0), PieceType::bishop, Colour::white));
	pieces.push_back(new Piece(Coord(5, 0), PieceType::bishop, Colour::white));
	pieces.push_back(new Piece(Coord(2, 7), PieceType::bishop, Colour::black));
	pieces.push_back(new Piece(Coord(5, 7), PieceType::bishop, Colour::black));

	// setup major pieces
	pieces.push_back(new Piece(Coord(0, 0), PieceType::rook, Colour::white));
	pieces.push_back(new Piece(Coord(7, 0), PieceType::rook, Colour::white));
	pieces.push_back(new Piece(Coord(0, 7), PieceType::rook, Colour::black));
	pieces.push_back(new Piece(Coord(7, 7), PieceType::rook, Colour::black));

	pieces.push_back(new Piece(Coord(3, 0), PieceType::queen, Colour::white));
	pieces.push_back(new Piece(Coord(3, 7), PieceType::queen, Colour::black));

	// king
	pieces.push_back(new Piece(Coord(4, 0), PieceType::king, Colour::white));
	pieces.push_back(new Piece(Coord(4, 7), PieceType::king, Colour::black));
}

Board::~Board()
{
	for (auto iter : pieces) {
		delete iter;
	}
}

Piece* Board::get_piece_at(Coord pos)
{
	for (auto piece : pieces) {
		if (piece->pos == pos) {
			return piece;
		}
	}
	return nullptr;
}