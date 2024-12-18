#pragma once
#include "Board.h"

class Knight
{
public:
	static short Is_legal_move(char** board, std::string src, std::string dst, bool isWhiteTurn);

};

