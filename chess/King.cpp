#include "King.h"
bool King::Is_legal_move(char** board, int* src, int* dst, bool isWhiteTurn)
{

	return (src[0] - dst[0] >= -1 && src[0] - dst[0] <= 1) && (src[1] - dst[1] >= -1 && src[1] - dst[1] <= 1);
}

bool King::Is_king_safe(char** board, int* src, int* dst, bool isWhite)
{
	int* place = new int[2];

	char tmp = board[dst[0]][dst[1]];
	Board::Move(board, src, dst);
	int  row = 0 , col = 0, changeByRow = 0, changeByCol = 0,row2 = 0, col2 = 0;
	for (row = src[0]-1; row < BORDERS;row++) {
		for (col = src[1] - 1; col < BORDERS; col++) {
			changeByRow = row - src[0];
			changeByCol = col - src[1];
			row2 = row, col2 = col;
			while (row2 < BORDERS && col2 < BORDERS && (changeByRow!=0 || changeByCol!=0)) {
				//
				if ((isupper(board[row2][col2])&&!isWhite) || (islower(board[row2][col2])&& isWhite)) {
					place[0] = row2;
					place[1] = col2;
					if (Board::Global_Is_Legal_Move(board,place, src, isWhite)) {
						return false;
					}
				}
				else if ((isupper(board[row2][col2]) && isWhite) || (islower(board[row2][col2]) && !isWhite))
					break;
				//
				row2 += changeByRow;
				col2 += changeByCol;
			}
		}
	}
	Board::Move(board, dst, src);
	board [dst[0]] [dst[1]] = tmp;

	delete[] place;
	return true;
}
