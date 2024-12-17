#pragma once
#include "Board.h"
#include <iostream>

class Piece
{
public:
	static short Is_legat_move(Board board, std::string src, std::string dst, bool isWhiteTurn);
};

