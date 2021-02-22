
#include <iostream>
#include <string>
#include "Knight.h"
using namespace std;

void Knight::print_board() {									//asked for ShowBoard Function prints out chessboard visual and possible move list
	cout << "9 is where your knight is, the numbers are where it can move " << endl;
	for (int i = 0; i < 8; i++) {						//Loop for printing whats in board array
		for (int j = 0; j < 8; j++) {
			cout << board[i][j] << "  ";
		}
		cout << endl;
	}
	cin.get();
}

void Knight::GetLegalMoves(int row, int col) {		//Asked for GetLegalMoves()
	for (int move = 0; move < 8; move++) {				//recursion loop goes for all 8 possible knight moves
		int newrow = row + rowMoves[move];			//row adjustment for move
		int newcol = col + colMoves[move];			//col adjustment for move

		if (newrow < 0 || newrow >= 8 || newcol < 0 || newcol >= 8)	//checks if out of board, if so just loops, if not it continues
			continue;

		board[newrow][newcol] = move + 1;	//putting 1 to indicate knight can move there
	}
	print_board();						//calling showboard function
	return;								//void return
}

void Knight::LegalMoves(int row, int col) {	//asked for function to push to other functions
	for (int i = 0; i < 8; i++) {						//Loop for printing whats in board array
		for (int j = 0; j < 8; j++) {
			board[i][j] = 0;
		}
	}
	board[row][col] = 9;				//takes in knight position and marks a 9
	GetLegalMoves(row, col);			//calls function to get all possible knight moves
}