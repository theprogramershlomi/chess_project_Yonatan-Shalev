#pragma once
#include "Board.h"

class Pawn
{
public:
	static bool Is_legal_move(char** board, int* src, int* dst, bool isWhiteTurn);

};

