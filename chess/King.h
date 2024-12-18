#pragma once
#include "Board.h"

class King
{
	static short Is_legat_move(char** board, std::string src, std::string dst, bool isWhiteTurn);
	static bool Is_king_safe(char** board, int* src, int* dst, bool isWhite);
};

