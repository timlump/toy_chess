#include "Pieces.hpp"

void Piece::move(Move move, Board* board)
{

}

std::vector<Move> Piece::get_possible_moves(Board* board)
{
    switch (piece_type) {
        case PieceType::pawn:
            return get_pawn_moves(board);
        case PieceType::knight:
            return get_knight_moves(board);
        case PieceType::bishop:
            return get_bishop_moves(board);
        case PieceType::rook:
            return get_rook_moves(board);
        case PieceType::queen:
            return get_queen_moves(board);
        case PieceType::king:
            return get_king_moves(board);
    }

    return std::vector<Move>();
}

std::vector<Move> Piece::get_pawn_moves(Board* board)
{
    return std::vector<Move>();
}

std::vector<Move> Piece::get_knight_moves(Board* board)
{
    return std::vector<Move>();
}

std::vector<Move> Piece::get_bishop_moves(Board* board)
{
    return std::vector<Move>();
}

std::vector<Move> Piece::get_rook_moves(Board* board)
{
    return std::vector<Move>();
}

std::vector<Move> Piece::get_queen_moves(Board* board)
{
    return std::vector<Move>();
}

std::vector<Move> Piece::get_king_moves(Board* board)
{
    return std::vector<Move>();
}
