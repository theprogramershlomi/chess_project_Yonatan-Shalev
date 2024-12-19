#pragma once
#include "Board.h"
#define BORDERS 8

class King
{
public:
	static bool Is_Opponent_Piece(char piece, bool isWhite);

	static bool Is_Legal_Move(char** board, int* src, int* dst, bool isWhiteTurn);
	static bool Is_king_safe(char** board, int* src, int* dst, bool isWhite);
};

