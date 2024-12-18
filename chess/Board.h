#pragma once
#include <iostream>

class Board
{
private:
	char** _board;
	bool _isWhiteTurn;

public:
	Board(char** board, bool isWhiteTurn);
	Board(char* board, bool isWhiteTurn);
	Board(std::string board, bool isWhiteTurn);
	void Initialize_board();

	void Move(std::string src, std::string dst);
	short Is_Legal(std::string src, std::string dst);
	int* Convert_To_Index(std::string pos);
};

