#include <stdio.h>
#define UNASSIGNED 0




bool findNotAssigned(int board[9][9], int &row, int &col){
	for(row =0; row < 9; row++){
		for(col =0; col <9; col++){
			if(board[row][col] == UNASSIGNED){
				return true;
			}
		}
	}
	return false;
}

bool UsedInRow(int board[9][9], int row, int num){
	for(int col =0; col < 9; col++){
		if(board[row][col] == num){
			return true;
		}
	}
	return false;
}

bool UsedInCol(int board[9][9], int col, int num){
	for(int row =0; row < 9; row++){
		if(board[row][col] == num){
			return true;
		}
	}
	return false;
}

bool UsedInBoard(int board[9][9], int boxStartRow, int boxStartCol, int num){
	for(int row =0; row <3; row++){
		for(int col = 0; col<3; col++){	
			if(board[row+boxStartRow][col+boxStartCol] == num){
				return true;
			}
		}
	}
	return false;
}

bool safe(int board[9][9], int row, int col, int val){
	return !UsedInRow(board, row, val) && !UsedInCol(board, col, val) &&
	       !UsedInBoard(board, row - row%3, col - col%3, val);

}

bool sudoku(int board[9][9]){
        int row, col;

        if (!findNotAssigned(board, row, col)){
                return true;
        }
        for (int num = 1; num <= 9; num++){
		if(safe(board, row, col, num)){
                	board[row][col] = num;
			//board is solved
                	if(sudoku(board)){
                        	return true;
                	}
			//failed placement, backtrack
                	board[row][col] = UNASSIGNED;
        	}
	}
        return false;
}

//function to print out the finished board
void printBoard(int board[9][9]){
	for(int row = 0; row < 9; row++){
		for(int col = 0; col < 9; col++){
			printf("%2d", board[row][col]);
		}
		printf("\n");
	}
}
