#include "King.h"
bool King::Is_Legal_Move(char** board, int* src, int* dst, bool isWhiteTurn)
{
	return (src[0] - dst[0] >= -1 && src[0] - dst[0] <= 1) && (src[1] - dst[1] >= -1 && src[1] - dst[1] <= 1);
}
bool King::Is_Opponent_Piece(char piece, bool isWhite) {
	return isalpha(piece) && ((isupper(piece) && !isWhite) || (islower(piece) && isWhite));
}



bool King::Is_king_safe(char** board, int* src, int* dst, bool isWhite)
{

	char tmp = board[dst[0]][dst[1]];
	Board::Move(board, src, dst);

	int kingPlace[] = { -1,-1 };
	for (int i = 0; i < BORDERS; i++) {
		for (int j = 0; j < BORDERS; j++) {

			if ((board[i][j] == 'k' && !isWhite) || (board[i][j] == 'K' && isWhite)) {

				kingPlace[0] = i;
				kingPlace[1] = j;
				break;
			}
		}
		if (kingPlace[0] != -1)
		{
			break;
		}
	}


	int place[2];

	bool flag = true;
	int  row = 0, col = 0, changeByRow = 0, changeByCol = 0, row2 = 0, col2 = 0;

	for (row2 = 0; row2 < BORDERS; row2++) {
		for (col2 = 0; col2 < BORDERS; col2++) {
			if (Is_Opponent_Piece(board[row2][col2], isWhite)  ) {
				place[0] = row2;
				place[1] = col2;
				if (Board::Global_Is_Legal_Move(board, place, kingPlace, !isWhite)) {
					flag = false;
					break;
				}
			}
		}
		if (flag == false)
		{
			break;
		}
	}

	Board::Move(board, dst, src);
	board[dst[0]][dst[1]] = tmp;



	return flag;
}
