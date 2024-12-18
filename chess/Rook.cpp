#include "Rook.h"
#include <cmath>

bool Rook::Is_legal_move(char** board, int* src, int* dst, bool isWhiteTurn)
{
	bool is_legal = false;
	short neg = 1;

	if (src[0] == dst[0])
	{
		if (src[1] > dst[1])
		{
			//neg -> negative
			neg = -1;
		}

		is_legal = true;
		for (int i = neg; src[1] + i != dst[1]; i += neg)
		{
			if (board [src[0]] [src[1] + i] != '#')
			{
				is_legal = false;
			}
		}
	}
	else if (src[1] == dst[1])
	{
		if (src[0] > dst[0])
		{
			//neg -> negative
			neg = -1;
		}

		is_legal = true;
		for (int i = neg; src[0] + i != dst[0]; i += neg)
		{
			if (board [src[0] + i] [src[1]] != '#')
			{
				is_legal = false;
			}
		}
	}

	return is_legal;
}
