#include "Bishop.h"

bool Bishop::Is_legal_move(char** board, int* src, int* dst, bool isWhiteTurn)
{
	bool is_legal = false;
	int directionsArr[][2] = {{1,-1} ,{1,1} ,{-1,1}, {-1,-1}};
	int i = 0, row = 0, col = 0;
	for (int i = 0; i < directions; i++) {
		row = directionsArr[i][0]+src[0], col = directionsArr[i][1]+src[1];
		while ((row < BORDERS && row >= 0) && (col < BORDERS && col >= 0)) {

			if (board[row][col] == board[dst[0]][dst[1]])
			{
				is_legal = true;
				break;
			}
			else if (board[row][col] != '#')
			{
				break;
			}

			row += directionsArr[i][0];
			col += directionsArr[i][1];
		}
		if (is_legal == true)
		{
			break;
		}

	}
	return is_legal;
}
