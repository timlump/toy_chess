#include <stack>
#include "Board.hpp"

class ChessEngine
{
public:
	ChessEngine();
	void draw_current_state();

private:
	Board board;
	bool white_turn = true;
};