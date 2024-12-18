#include "Queen.h"
#include "Rook.h"
#include "Bishop.h"

bool Queen::Is_legal_move(char** board, int* src, int* dst, bool isWhiteTurn)
{
	return (Rook::Is_legal_move(board, src, dst, isWhiteTurn) || Bishop::Is_legal_move(board, src, dst, isWhiteTurn));
}
