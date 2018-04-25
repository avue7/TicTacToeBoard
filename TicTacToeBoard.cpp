#include "TicTacToeBoard.h"
/**
 * Class for representing a 3x3 Tic-Tac-Toe game board, using the Piece enum
 * to represent the spaces on the board.
**/

//Constructor sets an empty board and specifies it is X's turn first
TicTacToeBoard::TicTacToeBoard()
{
  turn = X;
  for(int i=0; i<BOARDSIZE; i++)
    for(int j=0; j<BOARDSIZE; j++)
      board[i][j] = Blank;
}

/**
 * Switches turn member variable to represent whether it's X's or O's turn
 * and returns whose turn it is
**/
Piece TicTacToeBoard::toggleTurn()
{
  if (turn == X){
    turn = O;
    return turn;
  }
  else{
    turn = X;
    return turn;
  }
}

/**
 * Places the piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. placePiece does 
 * NOT allow to place a piece in a location where there is already a piece.
 * In that case, placePiece just returns what is already at that location. 
 * Out of bounds coordinates return the Piece Invalid value. When the game
 * is over, no more pieces can be placed so attempting to place a piece
 * should neither change the board nor change whose turn it is.
**/ 
Piece TicTacToeBoard::placePiece(int row, int column)
{
  // If no winner yet...
  if (getWinner() == Invalid){
    // Out of bound high
    if (row >= BOARDSIZE || column >= BOARDSIZE){
      return Invalid;
    }
    // Out of bound low
    else if (row < 0 || column < 0){
      return Invalid;
    }
    // return what is already at that location
    else if (board[row][column] != Blank){
      return board[row][column];
    }
    else{
      // place piece on the board
      Piece curTurn;
      curTurn = turn;
      board[row][column] = curTurn;
      toggleTurn();
      return curTurn;
    }
  }
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece TicTacToeBoard::getPiece(int row, int column)
{
  // Out of bound high and low
  if (row >= BOARDSIZE || column >= BOARDSIZE || row < 0 || column < 0){
    return Invalid;
  }
  // Coordinates does not contain X or O
  //else if (board[row][column] != X && board[row][column] != O){
  if (board[row][column] == Blank){
    return Blank;
  }
  // Found something there
  else{
    return board[row][column];
  }
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won.
**/
Piece TicTacToeBoard::getWinner()
{
  // Flag for if won
  bool won = false;
  
	// Won in one of the rows?
	for(int i = 0; i < BOARDSIZE; i++){
		if(board[i][0] == board[i][1] && board[i][1] == board[i][2]){
			if(board[i][0] != Blank){
			  won = true;
				return getPiece(i,0);
			}
		}
	}
	
	// Cols
	for(int i = 0; i < BOARDSIZE; i++){
		if(board[0][i] == board[1][i] && board[1][i] == board[2][i]){
			if(board[0][i] != Blank){
			  won = true;
				return board[0][i];
			}
		}
	}
	
	// Diagonal left top bottom right
	if(board[0][0] == board[1][1] && board[1][1] == board[2][2]){
		if(board[0][0] != Blank){
		  won = true;
			return board[0][0];
		}
	}
	
	// Diagonal top right to bottom left
	if(board[2][0] == board[1][1] && board[1][1] == board[0][2]){
		if(board[2][0] != Blank){
		  won = true;
			return board[2][0];
		}
	}
	
	// If get here, no winner yet, check if have blank spots 
  for(int row=0; row<BOARDSIZE; row++){
    for(int col=0; col<BOARDSIZE; col++){
      if (board[row][col] == Blank){
        return Invalid;
      }
    }
  }
  
  // Now if get here then all filled and no winner
  return Blank;
}