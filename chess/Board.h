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
<<<<<<< HEAD

=======
>>>>>>> b8ff03c4a4def9c9d5a50e6e3b09fa4b9816ef91

	void Move(std::string src, std::string dst);
	short Is_Legal(std::string src, std::string dst);
	int* Convert_To_Index(std::string pos);
};

