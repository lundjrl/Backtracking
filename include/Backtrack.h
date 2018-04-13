#include <stdio.h>
#define UNASSIGNED 0


bool sudoku(int board[9][9]){
	int row, col;
	
	for (int num = 1; num <= 9; num++){
		board[row][col] = num;
		if(sudoku(board)){
			return true;
		}
		board[row][col] = UNASSIGNED;
	}
	return false;
}

bool FindUnassignedLocation(int board[9][9], int &row, int &col){
	for(row =0; row < 8; row++){
		for(col =0; col <8; col++){
			if(board[row][col] == UNASSIGNED){
				return true;
			}
		}
	}
	return false;
}

bool UsedInRow(int board[9][9], int row, int num){
	for(int col =0; col < 8; col++){
		if(board[row][col] == num){
			return true;
		}
	}
	return false;
}

bool UsedInCol(int board[9][9], int col, int num){
	for(int row =0; row < 8; row++){
		if(board[row][col] == num){
			return true;
		}
	}
	return false;
}

bool UsedInBox(int board[9][9], int boxStartRow, int boxStartCol, int num){
	for(int row =0; row <3; row++){
		for(int col = 0; col<3; col++){	
			if(board[row+boxStartRow][col+boxStartCol] == num){
				return true;
			}
		}
	}
	return false;
}


//function to print out the finished board
void printBoard(int board[9][9]){
	for(int row = 0; row < 8; row++){
		for(int col = 0; col < 8; col++){
			printf("%2d", board[row][col]);
		}
		printf("\n");
	}

