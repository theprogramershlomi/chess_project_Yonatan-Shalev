#pragma once
#include "Piece.h"

class King : public Piece
{
	static short Is_legat_move(Board board, std::string src, std::string dst, bool isWhiteTurn);
	static bool Is_king_safe(Board board, int* src, int* dst, bool isWhite);
};

