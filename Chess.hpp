#include <stack>

enum TILE_STATE_FLAGS
{
	empty = 0,
	pawn = 1 << 0,
	knight = 1 << 1,
	bishop = 1 << 2,
	rook = 1 << 3,
	queen = 1 << 4,
	king = 1 << 5,
	black = 1 << 6 // set for black/unset for white
};

struct board_state
{
	unsigned char tiles[8][8] = { 0 };
	void reset()
	{
		// clear board
		for (int y = 0; y < 8; y++) {
			for (int x = 0; x < 8; x++) {
				tiles[x][y] = TILE_STATE_FLAGS::empty;
			}
		}

		for (int x = 0; x < 8; x++) {
			tiles[x][1] = TILE_STATE_FLAGS::pawn | TILE_STATE_FLAGS::black;
			tiles[x][6] = TILE_STATE_FLAGS::pawn;
		}

		tiles[0][0] = tiles[7][0] = TILE_STATE_FLAGS::rook | TILE_STATE_FLAGS::black;
		tiles[0][7] = tiles[7][7] = TILE_STATE_FLAGS::rook;

		tiles[1][0] = tiles[6][0] = TILE_STATE_FLAGS::knight | TILE_STATE_FLAGS::black;
		tiles[1][7] = tiles[6][7] = TILE_STATE_FLAGS::knight;

		tiles[2][0] = tiles[5][0] = TILE_STATE_FLAGS::bishop | TILE_STATE_FLAGS::black;
		tiles[2][7] = tiles[5][7] = TILE_STATE_FLAGS::bishop;

		tiles[3][0] = TILE_STATE_FLAGS::queen | TILE_STATE_FLAGS::black;
		tiles[3][7] = TILE_STATE_FLAGS::queen;

		tiles[4][0] = TILE_STATE_FLAGS::king | TILE_STATE_FLAGS::black;
		tiles[4][7] = TILE_STATE_FLAGS::king;
	}
};

class ChessEngine
{
public:
	ChessEngine();
	void init();
	void draw_current_state();
private:
	board_state current_board;
};