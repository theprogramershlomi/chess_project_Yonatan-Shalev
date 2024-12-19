#pragma once
#include "Board.h"
#define directions 8





class Knight
{
public:
	static bool Is_legal_move(char** board, int* src, int* dst, bool isWhiteTurn);

};

