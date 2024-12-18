#include "King.h"
bool King::Is_legal_move(char** board, int* src, int* dst, bool isWhiteTurn)
{
	return false;
}

bool King::Is_king_safe(char** board, int* src, int* dst, bool isWhite)
{
	char tmp = board[dst[0]][dst[1]];
	Move(Board::Move(src, dst));
	int  row = 0 , col = 0, changeByRow = 0, changeByCol = 0,row2 = 0, col2 = 0;
	for (row = src[0]-1; row < BORDERS;row++) {
		for (col = src[1] - 1; col < BORDERS; col++) {
			changeByRow = row - src[0];
			changeByCol = col - src[1];
			row2 = row, col2 = col;
			while (row2 < BORDERS && col2 < BORDERS && (changeByRow!=0 || changeByCol!=0)) {
				//
				if ((isupper(board[row2][col2])&&!isWhite) || (islower(board[row2][col2])&& isWhite)) {
					if (Global_is_leagal_move(board,row2,col2,src[0],dst[0])) {
						return true;
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
	Move(Board::Move(src, dst));
	board[dst[0]][dst[1]] = tmp;
	return false;;
}
