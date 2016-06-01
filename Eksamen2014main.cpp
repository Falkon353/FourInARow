#include <iostream>
#include <string>
#include"oppgave2.h"

using namespace std;

const int NRTASKS = 2;

void oppgave1a();
void oppgave1b();
void oppgave1c();
void oppgave1d();
void func(int i);
void oppgave1e();
void oppgave2();

int main(){
	int input = -1;
	while(input != 0){
		cout << "chose a task between 1 and " << NRTASKS << endl;
		cout << "prest the task nr to chose the task and 0 to quit" << endl;
		cin >> input;
		switch(input){
			case 1:
				oppgave1a();
				oppgave1b();
				oppgave1c();
				oppgave1d();
				oppgave1e();
				break;
			case 2:
				oppgave2();
				break;
			case -1:
				int test[2] = {};
				break;
		}
	}
	
}

void oppgave1a(){
	int x = 1;
	int y = 10 / x--;
	int z = 10 / --x;
	cout << x << endl;
	cout << y << endl;
	cout << z << endl;
}

void oppgave1b(){
	bool x = true;
	bool y = false;
	bool z = (x||y) && !(x&&y);
	cout << boolalpha << z << endl;
}

void oppgave1c(){
	int x = 10;
	int y = 4;
	double z = x/y;
	cout << z << endl;
}

void oppgave1d(){
	func(12345);
}

void func(int i){
	if(i > 10){
		cout << i %10;
		func(i/10);
	}
	else{
		cout << i << endl;
	}
}

void oppgave1e(){
	int x = 5;
	int y = 6;
	if( x !=y){
		cout << x << " is different from " << y << endl;
	}
	else{
		cout << x << " is not different from " << y << endl;
	}
}

void oppgave2(){
	Board  board{};
	
	int input = 0;
	Tile playerTile = EMPTY;
	Tile machineTile = EMPTY;
	bool gameOver = false;
	while(input == 0){
		cout << "Chose a coulor, 1 for RED and 2 for YELLOW " << endl;
		cin >> input;
	}
	if(input == 2){
		machineTile = RED;
		playerTile = YELLOW;
	}
	else{
		machineTile = YELLOW;
		playerTile = RED;
	}
	while(gameOver == false){
		if(playerTurn(board,playerTile)){
			cout << "You beat the computer gz" << endl;
			cout << board << endl;
			gameOver = true;
			break;
		}
		if(cleverMacineTurn(board,machineTile)){
			cout << "You lost the game, sory" << endl;
			cout << board << endl;
			gameOver = true;
			break;
		}
	}
	/*put(board,6,YELLOW);
	cout << board << endl;
	cout << "first countTiles opp: " << countTiles(board,5,6,-1,0) << endl;
	cout << "first countTiles ned: " << countTiles(board,5,6,1,0) << endl;
	put(board,6,YELLOW);
	cout << board << endl;
	cout << "second countTIles opp : " << countTiles(board,5,6,-1,0)<< endl;
	cout << "second countTIles ned : " << countTiles(board,5,6,1,0)<< endl;
	*/
	
	
}