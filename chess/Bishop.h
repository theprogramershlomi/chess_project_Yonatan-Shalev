#pragma once
#define directions 4
#define BORDERS 8

#include "Board.h"

class Bishop
{
public:
	static bool Is_Legal_Move(char** board, int* src, int* dst, bool isWhiteTurn);

};

