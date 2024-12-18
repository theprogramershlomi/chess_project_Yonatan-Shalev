#pragma once
#include <iostream>

class Board
{
private:
	char** _board;
	bool _isWhiteTurn;

public:
	Board(std::string board, bool isWhiteTurn);
	void Initialize_board();

	void Move(std::string src, std::string dst);
	static void Move(char** board, int* src, int* dst);

	static int* Convert_To_Index(std::string pos);

	short Is_Legal(std::string src, std::string dst);
	static bool Global_Is_Legal_Move(char** board, int* src, int* dst, bool isWhiteTurn);
};

