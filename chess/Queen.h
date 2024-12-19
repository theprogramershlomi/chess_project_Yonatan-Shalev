#pragma once
#include "Board.h"

class Queen
{
public:
	static bool Is_Legal_Move(char** board, int* src, int* dst, bool isWhiteTurn);

};

