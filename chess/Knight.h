#pragma once
#include "Board.h"
#define directions 8





class Knight
{
public:
	static bool Is_Legal_Move(char** board, int* src, int* dst, bool isWhiteTurn);

};

