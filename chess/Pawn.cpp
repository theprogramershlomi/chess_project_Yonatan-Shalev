#include "Pawn.h"
#include <cmath>

bool Pawn::Is_legal_move(char** board, int* src, int* dst, bool isWhiteTurn)
{
	bool isLegal = false;

	if (!isWhiteTurn)
	{
		if (dst[1] == src[1])
		{
			if (board[dst[0]][dst[1]] == '#')
			{
				if (src[0] - dst[0] == 1)
				{
					// pawn is walking 1 square
					isLegal = true;
				}
				else if (src[0] == 1 && src[0] - dst[0] == 2 && board[dst[0]][dst[1]] == '#')
				{
					// pawn is walking 2 squares
					isLegal = true;
				}
			}
		}
		else if (isalpha(board [dst[0]] [dst[1]] ) && abs(dst[1] - src[1]) == 1 && src[0] - dst[0] == 1)
		{
			//pawn is trying to eat someone :)
			isLegal = true;
		}
	}
	else
	{
		if (dst[1] == src[1])
		{
			if (board[dst[0]][dst[1]] == '#')
			{
				if (dst[0] - src[0] == 1)
				{
					// pawn is walking 1 square
					isLegal = true;
				}
				else if (src[0] == 1 && dst[0] - src[0] == 2 && board[dst[0]][dst[1]] == '#')
				{
					// pawn is walking 2 squares
					isLegal = true;
				}
			}
		}
		else if (isalpha(board [dst[0]] [dst[1]] ) && abs(dst[1] - src[1]) == 1 && dst[0] - src[0] == 1)
		{
			//pawn is trying to eat someone :)
			isLegal = true;
		}
	}

	return isLegal;
}
