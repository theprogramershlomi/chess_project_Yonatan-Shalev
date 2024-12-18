#pragma once
#include <iostream>

class Board
{
private:
	char** _board;
	bool _isWhiteTurn;

public:
	void Move(std::string src, std::string dst);
	short Is_Legal(std::string src, std::string dst);
	int* Convert_To_Index(std::string pos);
};

