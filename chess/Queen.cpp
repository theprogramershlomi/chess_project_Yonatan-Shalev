#include "Queen.h"
#include "Rook.h"
#include "Bishop.h"

bool Queen::Is_Legal_Move(char** board, int* src, int* dst, bool isWhiteTurn)
{
	return (Rook::Is_Legal_Move(board, src, dst, isWhiteTurn) || Bishop::Is_Legal_Move(board, src, dst, isWhiteTurn));
}
