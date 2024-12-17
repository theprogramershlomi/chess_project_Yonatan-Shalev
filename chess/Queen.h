#pragma once
#include "Piece.h"

class Queen : public Piece
{
	static short Is_legat_move(Board board, std::string src, std::string dst, bool isWhiteTurn);

};

