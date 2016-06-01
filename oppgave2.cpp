#include"oppgave2.h"

bool isFull(Board board, int col){
	return board[0][col] != EMPTY;
}

ostream& operator<<(ostream& o, Tile t){
	if(t == EMPTY){
		o << "*";
	}
	else if(t == YELLOW){
		o << "Y";
	}
	else{
		o << "R";
	}
	return o; 
}

ostream& operator<<(ostream& os, Board b){
	for( int i = 0; i < ROWS; i ++ ){
		for(int j = 0; j < COLS; j ++){
			os << b[i][j];
		}
		os << endl;
	}
	return os;
}

int findeLowestPlace(Board board, int column){
	for(int i = 0; i < ROWS; i ++){
		if(board[i][column] == EMPTY){
			continue;
		}
		else{
			int a = i - 1;
			return i-1;
		}
	}
	return 5;
}

int put(Board board, int column, Tile tile){
	int rowPlacement = findeLowestPlace(board,column);
	if(isOutOfBounds(rowPlacement,column)){
		return - 1;
	}
	board[rowPlacement][column] = tile;
	return rowPlacement;
}

bool isOutOfBounds(int row, int column){
	if(row >= ROWS || column >= COLS){
		return true;
	}
	else{
		return false;
	}
}

int countTiles(Board board, int row, int column, int dr, int dc){
	if(isOutOfBounds(row,column) || (board[row][column] == EMPTY)){
		cout << "i am in the countTIles if statement" << endl;
		return 0;
	}
	else if(board[row][column] == board[row+dr][column +dc]){
		return 1+ countTiles(board, row + dr, column+dc, dr, dc);
	}
	return 1;
}

bool fourInARow(Board board, int row, int column){
		int horizontalInARow = countTiles(board,row,column,0,1)+countTiles(board,row,column,0,-1) -1;
		int verticalInARow = countTiles(board,row,column,-1,0) + countTiles(board,row,column,1,0)-1;
		int dioagnalLToRInARow = countTiles(board,row,column,-1,-1) + countTiles(board,row,column,1,1)-1;
		int dioagnalRToLInARow = countTiles(board,row,column,1,-1) + countTiles(board,row,column,-1,1)-1;
		cout << "horiz: " << horizontalInARow << "vertical: " << verticalInARow << "DigLToR: " << dioagnalLToRInARow << "digRToL: " << dioagnalRToLInARow << endl;
		if(horizontalInARow >= 4 || verticalInARow >= 4 || dioagnalLToRInARow >= 4 || dioagnalRToLInARow >= 4){
			return true;
		}
		return false;
}

bool playerTurn(Board board, Tile t){
	int columInput = -1;
	cout << board << endl;
	while(columInput ==-1 ){
		cout << "What colum do you want to place the peac in? " << endl;
		cin >> columInput;
		columInput--;
		if(put(board,columInput,t) == -1){
			columInput = -1;
		}
	}	
	//cout << board << endl;
	cout << "Row cordinat: "<< findeLowestPlace(board,columInput)+1 << " columInput: " << columInput << endl;
	return fourInARow(board,findeLowestPlace(board,columInput)+1,columInput);
}

bool machineTurn(Board board, Tile t){
	int columInput = -1;
	while(columInput == -1){
		columInput = randomWithLimits(0,6);
		if(put(board,columInput,t) == -1){
			columInput = -1;
		}
	}
	//cout << board << endl;
	return fourInARow(board,findeLowestPlace(board,columInput)+1,columInput);
}

int randomWithLimits(int lowLimit, int highLimit){
	double randomNr = rand();
	int range = highLimit - lowLimit;
	int nrInnRange = (int)round(range*(randomNr / RAND_MAX));
	return lowLimit + nrInnRange;
}

bool cleverMacineTurn(Board board, Tile t){
	Tile opponent = EMPTY;
	if(t == RED){
		opponent = YELLOW;
	}
	else{
		opponent = RED;
	}
	for(int i = 0; i < COLS; i++){
		if(canSombadyWinn(board,i,t)){
			put(board,i,t);
			return fourInARow(board,findeLowestPlace(board,i)+1,i);
		}
		if(canSombadyWinn(board,i,opponent)){
			put(board,i,t);
			return fourInARow(board,findeLowestPlace(board,i)+1,i);
		}	
	}
	return machineTurn(board,t);
}

bool canSombadyWinn(Board board, int column, Tile t){
	int row = findeLowestPlace(board,column);
	put(board,column,t);
	if (fourInARow(board,row,column)){
		board[row][column] = EMPTY;
		return true;
	}
	board[row][column] = EMPTY;
	return false;
	
}











