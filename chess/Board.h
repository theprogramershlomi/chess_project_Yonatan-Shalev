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
	static void Move(char** board, std::string src, std::string dst);

	static int* Convert_To_Index(std::string pos);

	short Is_Legal(std::string src, std::string dst);
	bool Global_Is_Legal_Move(char** board, int* src, int* dst, bool isWhiteTurn);
};

