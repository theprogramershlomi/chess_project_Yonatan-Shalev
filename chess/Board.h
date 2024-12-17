#pragma once
class Board
{
private:
	char** _board;
	bool _isWhiteTurn;

public:
	void Move(std::string src, std::string dst);
	short Is_legal(std::string src, std::string dst);
	int* Convert_to_index(std::string pos);
};

