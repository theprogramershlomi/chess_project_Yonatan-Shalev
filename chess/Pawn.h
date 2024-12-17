#pragma once
#include "Piece.h"

class Pawn : public Piece
{
	static short Is_legat_move(Board board, std::string src, std::string dst, bool isWhiteTurn);

};

