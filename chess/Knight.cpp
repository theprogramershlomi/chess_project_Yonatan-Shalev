#include "Knight.h"
#define BORDERS 8

bool Knight::Is_Legal_Move(char** board, int* src, int* dst, bool isWhiteTurn)
{
    int directionsArr[][2] = { {1,-2} ,{2,-1} ,{1,2}, {-2,-1},
                              {-1,-2 } ,{2,1} ,{-1,2}, {-2,1} };
	int i = 0, row = 0, col = 0;
	for (int i = 0; i < directions; i++) {
		row = directionsArr[i][0] + src[0], col = directionsArr[i][1] + src[1];
		if ((row < BORDERS && row >= 0) && (col < BORDERS && col >= 0)) {
			if (row == dst[0] && col == dst[1])
				return true;
		}

	}
    return false;
}
