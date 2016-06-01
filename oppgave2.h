#include<iostream>
#include<random>
#include<math.h>

using namespace std;

enum Tile {EMPTY = 0, RED = 2, YELLOW = 3};
const int ROWS = 6;
const int COLS = 7;

using Board = Tile[ROWS][COLS];

ostream& operator<<(ostream& o, Tile t);
ostream& operator<<(ostream& os, Board b);
int findeLowestPlace(Board board, int column);
int put(Board board, int column, Tile tile);
bool isOutOfBounds(int row, int column);
int countTiles(Board board, int row, int column, int dr, int dc);
bool fourInARow(Board board, int row, int column);
bool playerTurn(Board board, Tile t);
bool machineTurn(Board board, Tile t);
int randomWithLimits(int lowLimit, int highLimit);
bool cleverMacineTurn(Board board, Tile t);
bool canSombadyWinn(Board board, int column, Tile t);

// unsigne int betyr at du ikke kan ha negative tall.
// det ville vært en fordel siden du ikke vill ha negative tall 
//det fører til at du ikke kan ende opp i den feiltilstanden  
