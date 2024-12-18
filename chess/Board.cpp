#define BOARD_ROW_SIZE 8
#define BOARD_COL_SIZE 8
#include "Board.h"
#include "Pawn.h"
#include "Knight.h"
#include "Bishop.h"
#include "Rook.h"
#include "Queen.h"
#include "King.h"

Board::Board(std::string board, bool isWhiteTurn)
{
	Initialize_board();

	for (int i = 0; i < 64; i++)
	{
		_board[7 - i / 8][i % 8] = board[i];
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
	_board[src_index[0]][src_index[1]] = '#';
	_isWhiteTurn = !_isWhiteTurn;

	delete[] src_index;
	delete[] dst_index;
}

void Board::Move(char** board, int* src, int* dst)
{
	board[dst[0]][dst[1]] = board[src[0]][src[1]];
	board[src[0]][src[1]] = '#';
}

short Board::Is_Legal(std::string src, std::string dst)
{
	// this can be an error or a succes
	// depending on the src and dst
	short return_code = 0;

	int* src_index = Convert_To_Index(src);
	int* dst_index = Convert_To_Index(dst);

	char src_ch = _board [src_index[0]] [src_index[1]];
	char dst_ch = _board [dst_index[0]] [dst_index[1]];




	if (src == dst)
	{
		// illegal move src = dst;
		return_code = 7;
		
	}

	//checks if dst has same colored piece
	if (!return_code && isalpha(dst_ch) && ((islower(dst_ch) && !_isWhiteTurn) || (!islower(dst_ch) && _isWhiteTurn)))
	{
		return_code = 3;
	}

	//checks if src has same colored piece
	if ((!return_code) && !(isalpha(src_ch) && ((islower(src_ch) && !_isWhiteTurn) || (!islower(src_ch) && _isWhiteTurn))))
	{
		std::cout << "isalpha = " << isalpha(src_ch) << std::endl;
		std::cout << "islower = " << islower(src_ch) << std::endl;
		std::cout << "isWhiteTurn = " << _isWhiteTurn << std::endl;
		std::cout << "(islower == !isWhiteTurn) = " << (islower(src_ch) == !_isWhiteTurn) << std::endl;
		// src doesn't have same colored piece
		return_code = 2;
	}

	if (!return_code)
	{
		if (!Global_Is_Legal_Move(_board, src_index, dst_index, _isWhiteTurn))
		{
			return_code = 6;
		}
	}
	/*
	// checks if the move will create check on the king
	if (!return_code && !King::Is_king_safe(_board, src_index, dst_index, _isWhiteTurn))
	{
		// move will create check no king.
		// illegal move.
		return_code = 4;
	}

	// checks if the move will create check on the other king
	if (!return_code && !King::Is_king_safe(_board, src_index, dst_index, !_isWhiteTurn))
	{
		// move will check the other king
		// ok move
		return_code = 1;
	}
	*/

	if (!return_code && (dst_ch == 'k' || dst_ch == 'K'))
	{
		// check mate!!!
		return_code = 8;
	}


	delete[] src_index;
	delete[] dst_index;
	return return_code;
}

int* Board::Convert_To_Index(std::string pos)
{
	int* index = new int[2];
	index[0] = (pos[1] - 49);
	index[1] = (pos[0] - 97);
	return index;
}

bool Board::Global_Is_Legal_Move(char** board, int* src_index, int* dst_index, bool isWhiteTurn)
{
	bool is_legal = true;

	// board [src_index[0]] [src_index[1]]
	// this is the char of the piece
	switch (tolower(board [src_index[0]] [ src_index[1]]))
	{
	case 'p':
		if (not Pawn::Is_legal_move(board, src_index, dst_index, isWhiteTurn))
		{
			is_legal = false;
		}
		break;
	case 'n':// n = knight because "king" took the 'k'
		if (not Knight::Is_legal_move(board, src_index, dst_index, isWhiteTurn))
		{
			is_legal = false;
		}
		break;
	case 'b':
		if (not Bishop::Is_legal_move(board, src_index, dst_index, isWhiteTurn))
		{
			is_legal = false;
		}
		break;
	case 'r':
		if (not Rook::Is_legal_move(board, src_index, dst_index, isWhiteTurn))
		{
			is_legal = false;
		}
		break;
	case 'q':
		if (not Queen::Is_legal_move(board, src_index, dst_index, isWhiteTurn))
		{
			is_legal = false;
		}
		break;
	case 'k':
		/*
		if (not King::Is_legal_move(board, src_index, dst_index, isWhiteTurn))
		{
			is_legal = false;
		}
		break;
		*/
		break;

	}

	return is_legal;
}
