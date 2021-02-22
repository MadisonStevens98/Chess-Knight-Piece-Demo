
#include <iostream>
#include <string>
#include <sstream>			//how i decided to handle input, used in recurse to make string input int
#include "Knight.h"

using namespace std;
void input1(int, Knight&);								//Function which finds given move input on board
void recurse(Knight&);									//recursive loop to handle main program
int board[8][8] = { 0 };								//asked for 2D array that is our chess board

void input1(int input, Knight& OurKnight) {				//takes our knight object and INT input
	for (int i = 0; i < 8; i++) {						
		for (int j = 0; j < 8; j++) {
			if (OurKnight.board[i][j] == input){		//loops through board to find user given move choice
				OurKnight.LegalMoves(i, j);				//legal moves wipes board to 0, and places knight at new position
				i = 8;
				break;
			}
		}
	}	
};

void recurse(Knight& OurKnight) {

	string input;										//You mentioned using char but I only know how to make it work with a string!
	
	cout << "Please hit E to exit, or your move number to calculate possible positions from that point: ";
	cin >> input;										//takes string input
	stringstream fixer(input);							//converts input to numbers
	int passedinput = 0;								//int to contain those numbers
	fixer >> passedinput;								//passing int values to int var

	if (input != "E" && passedinput != 0) {				//if input is not E and not null (so stringstream was successful in converting to numbers)
		input1(passedinput, OurKnight);					//Succcess! Take new position and calculate new options
		recurse(OurKnight);								//recurse!
	}
	else if (input != "E" && passedinput == 0 || passedinput > 9 || passedinput < 0) { //not E and passedinput is not a valid! 
		cout << "Try either E or a move number! ";
		recurse(OurKnight);
	}
	else {											//Was E! So exit!
		exit(0);
		return;
	}
};

int main() {
	int r, c;

	Knight OurKnight;				//Defaults values ROW COL and num of moves to 8
	cout << "Please enter Knight's current row(1-8): ";
	cin >> r;
	cout << "Please enter Knight's current col(1-8): ";
	cin >> c;
	OurKnight.LegalMoves(r - 1, c - 1);

	recurse(OurKnight);

	system("pause");
	return 0;
}