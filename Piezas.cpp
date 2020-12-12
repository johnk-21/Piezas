#include "Piezas.h"
#include <vector>
/** CLASS Piezas
 * Class for representing a Piezas vertical board, which is roughly based
 * on the game "Connect Four" where pieces are placed in a column and 
 * fall to the bottom of the column, or on top of other pieces already in
 * that column. For an illustration of the board, see:
 *  https://en.wikipedia.org/wiki/Connect_Four
 *
 * Board coordinates [row,col] should match with:
 * [2,0][2,1][2,2][2,3]
 * [1,0][1,1][1,2][1,3]
 * [0,0][0,1][0,2][0,3]
 * So that a piece dropped in column 2 should take [0,2] and the next one
 * dropped in column 2 should take [1,2].
**/


/**
 * Constructor sets an empty board (default 3 rows, 4 columns) and 
 * specifies it is X's turn first
**/
Piezas::Piezas() 
{
	board = std::vector<std::vector<Piece>> (BOARD_ROWS, std::vector<Piece> (BOARD_COLS, Blank));
	turn = X;
}

/**
 * Resets each board location to the Blank Piece value, with a board of the
 * same size as previously specified
**/
void Piezas::reset()
{
	board = std::vector<std::vector<Piece>> (BOARD_ROWS, std::vector<Piece> (BOARD_COLS, Blank));
	turn = X;
}

/**
 * Places a piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. dropPiece does 
 * NOT allow to place a piece in a location where a column is full.
 * In that case, placePiece returns Piece Blank value 
 * Out of bounds coordinates return the Piece Invalid value
 * Trying to drop a piece where it cannot be placed loses the player's turn
**/ 
Piece Piezas::dropPiece(int column)
{
		//if we have a valid column
		if(column >= 0 && column < BOARD_COLS) {
				for(int i = 0; i < BOARD_ROWS; i++) {
					if(board[i][column] == Blank) {
							//place piece	
							board[i][column] = turn;
							//switch turns
							turn = (turn == O) ? X : O;
							//return the piece we placed
							return board[i][column];
					}
				}
		}
		//else we have an out of bounds coordinate
		else {
			//since we can't place a piece we must lose a turn	
			turn = (turn == O) ? X : O;
			return Invalid;
		}
		//since we can't place a piece we must lose a turn	
		turn = (turn == O) ? X : O;
    return Blank;
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece Piezas::pieceAt(int row, int column)
{
		//Invalid coordinates return invalid
		if(row < 0 || row > BOARD_ROWS || column < 0 || column > BOARD_COLS) {
			return Invalid;
		}
		//
		else if(board[row][column] == O || board[row][column] == X) {
			return board[row][column];
		}
    return Blank;
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won ("tie").
 * For a game to be over, all locations on the board must be filled with X's 
 * and O's (i.e. no remaining Blank spaces). The winner is which player has
 * the most adjacent pieces in a single line. Lines can go either vertically
 * or horizontally. If both X's and O's have the same max number of pieces in a
 * line, it is a tie.
**/
Piece Piezas::gameState()
{
		int longestX = 0;
		int longestO = 0;
		//loop through the array vertically 	
		for(int i = 0; i < BOARD_ROWS; i++) {
			//Use these temporary variables to keep track of the current longest adjecent piece for each row 
			int x = 0;
			int o = 0;
			for(int j = 0; j < BOARD_COLS; j++) {
				if(pieceAt(i, j) == O) {
					o++;
					longestO = (o > longestO) ? o : longestO;
					x = 0;
				}
				else if(pieceAt(i, j) == X) {
					x++;
					longestX = (x > longestX) ? x : longestX;
					o = 0;
				}
				else {
					return Invalid;
				}
			}
		}
		for(int i = 0; i < BOARD_COLS; i++) {
			//Use these temporary variables to keep track of the current longest adjecent piece for each column
			int x = 0;
			int o = 0;
			for(int j = 0; j < BOARD_ROWS; j++) {
				if(pieceAt(j, i) == O) {
					o++;
					longestO = (o > longestO) ? o : longestO;
					x = 0;
				}
				else if(pieceAt(j, i) == X) {
					x++;
					longestX = (x > longestX) ? x : longestX;
					o = 0;
				}
			}
		}

		if(longestO > longestX) {
			return O;
		}
		else if (longestX > longestO) {
			return X;
		}
		return Blank;
}
