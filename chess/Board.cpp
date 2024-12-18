#define BOARD_ROW_SIZE 8
#define BOARD_COL_SIZE 8
#include "Board.h"
#include "Pawn.h"
#include "Knight.h"
#include "Bishop.h"
#include "Rook.h"
#include "Queen.h"
#include "King.h"

Board::Board(char** board, bool isWhiteTurn)
{
	Initialize_board();

	memcpy(_board, board, 64);
	_isWhiteTurn = isWhiteTurn;
}

Board::Board(char* board, bool isWhiteTurn)
{
	Initialize_board();

	memcpy(_board, board, 64);
	_isWhiteTurn = isWhiteTurn;
}

Board::Board(std::string board, bool isWhiteTurn)
{
	Initialize_board();

	for (int i = 0; i < 64; i++)
	{
		_board[i / 8][i % 8] = board[i];
	}
	_isWhiteTurn = isWhiteTurn;
}

/*
this function makes _board a [8][8] array
*/
void Board::Initialize_board()
{
	_board = new char* [BOARD_ROW_SIZE];

	for (int i = 0; i < BOARD_ROW_SIZE; ++i)
		_board[i] = new char[BOARD_COL_SIZE];
}


void Board::Move(std::string src, std::string dst)
{
	int* src_index = Convert_To_Index(src);
	int* dst_index = Convert_To_Index(dst);

	_board[dst_index[0]][dst_index[1]] = _board[src_index[0]][src_index[1]];

	delete[] src_index;
	delete[] dst_index;
}

short Board::Is_Legal(std::string src, std::string dst)
{
	// this can be an error or a succes
	// depending on the src and dst
	short return_code = 0;
	int* src_index = Convert_To_Index(src);
	int* dst_index = Convert_To_Index(dst);
	char src_ch = _board[src_index[0]][src_index[1]];
	char dst_ch = _board[dst_index[0]][dst_index[1]];


	if (src == dst)
	{
		// illegal move src = dst;
		return_code = 7;
		
	}

	//checks if dst has same colored piece
	if (!return_code && isalpha(dst_ch) && (islower(dst_ch) == !_isWhiteTurn))
	{
		return_code = 3;
	}

	//checks if dst has same colored piece
	if (!return_code && !(isalpha(src_ch) && (islower(src_ch) == !_isWhiteTurn)))
	{
		// src doesn't have same colored piece
		return_code = 3;
	}

	// !return_code mean that there are no errors.
	if (!return_code)
	{

		switch (tolower(src_ch))
		{
		case 'p':
			if (not Pawn::Is_legal_move(_board, src_index, dst_index, _isWhiteTurn))
			{
				return_code = 6;
			}
			break;
		case 'n':// n = knight because "king" took the 'k'
			if (not Knight::Is_legal_move(_board, src_index, dst_index, _isWhiteTurn))
			{
				return_code = 6;
			}
			break;
		case 'b':
			if (not Bishop::Is_legal_move(_board, src_index, dst_index, _isWhiteTurn))
			{
				return_code = 6;
			}
			break;
		case 'r':
			if (not Rook::Is_legal_move(_board, src_index, dst_index, _isWhiteTurn))
			{
				return_code = 6;
			}
			break;
		case 'q':
			if (not Queen::Is_legal_move(_board, src_index, dst_index, _isWhiteTurn))
			{
				return_code = 6;
			}
			break;
		case 'k':
			if (not King::Is_legal_move(_board, src_index, dst_index, _isWhiteTurn))
			{
				return_code = 6;
			}
			break;
		}
	}


	delete[] src_index;
	delete[] dst_index;
	return return_code;
}

int* Board::Convert_To_Index(std::string pos)
{
	int* index = new int[2];
	index[0] = (pos[0] - 97);
	index[1] = (pos[1] - 49);
	return index;
}
