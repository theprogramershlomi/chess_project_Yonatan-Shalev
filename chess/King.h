#pragma once
#include "Board.h"

class King
{
public:
	static bool Is_legal_move(char** board, int* src, int* dst, bool isWhiteTurn);
	static bool Is_king_safe(char** board, int* src, int* dst, bool isWhite);
};

