#pragma once
#ifndef KNIGHT
#define KNIGHT

using namespace std;

class Knight {
public:
	int rowMoves[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };		//array for board row movement for knight
	int colMoves[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };		//array for board movement for knight

	void print_board();										//Function to print out visual board
	void GetLegalMoves(int, int);							//Function which calculates legal knight moves
	void LegalMoves(int, int);								//Function that clears board, marks knight's postion and calls getlegalmoves

	int board[8][8] = { 0 };								//asked for 2D array that is our chess board

};

#endif 