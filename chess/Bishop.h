#pragma once
#define directions 4
#define BORDERS 8

#include "Board.h"

class Bishop
{
public:
	static bool Is_legal_move(char** board, int* src, int* dst, bool isWhiteTurn);

};

