/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"
 
class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} //constructor runs before each test
		virtual ~TicTacToeBoardTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

/* EXAMPLE TEST FORMAT
TEST(TicTacToeBoardTest, sanityCheck)
{
	ASSERT_TRUE(true);
}
*/

TEST(TicTacToeBoardTest, sanityCheck)
{
	TicTacToeBoard board;
	ASSERT_TRUE(true);
}

TEST(TicTacToeBoardTest, toggleOsTurn){
	TicTacToeBoard board;
	ASSERT_EQ(O, board.toggleTurn());
}

TEST(TicTacToeBoardTest, toggleXsTurn){
	TicTacToeBoard board;
	ASSERT_EQ(O, board.toggleTurn());
	ASSERT_EQ(X, board.toggleTurn());
}

TEST(TicTacToeBoardTest, invalidPlacementRowHigher){
	TicTacToeBoard board;
	ASSERT_EQ(Invalid, board.placePiece(3, 0));
}

TEST(TicTacToeBoardTest, invalidPlacementRowLower){
	TicTacToeBoard board;
	ASSERT_EQ(Invalid, board.placePiece(-1, 0));
}

TEST(TicTacToeBoardTest, invalidPlacementColumnHigher){
	TicTacToeBoard board;
	ASSERT_EQ(Invalid, board.placePiece(0, 3));
}

TEST(TicTacToeBoardTest, invalidPlacementColumnLower){
	TicTacToeBoard board;
	ASSERT_EQ(Invalid, board.placePiece(0, -1));
}

TEST(TicTacToeBoardTest, validPlacementRow){
	TicTacToeBoard board;
	ASSERT_EQ(X, board.placePiece(0, 0));
    ASSERT_EQ(O, board.placePiece(1, 0));
    ASSERT_EQ(X, board.placePiece(2, 0));
}

TEST(TicTacToeBoardTest, validPlacementColumn){
	TicTacToeBoard board;
	ASSERT_EQ(X, board.placePiece(0, 0));
    ASSERT_EQ(O, board.placePiece(0, 1));
    ASSERT_EQ(X, board.placePiece(0, 2));
}

TEST(TicTacToeBoardTest, invalidGetPieceRowHigher){
	TicTacToeBoard board;
	ASSERT_EQ(Invalid, board.getPiece(3, 0));
}

TEST(TicTacToeBoardTest, invalidGetPiceRowLower){
	TicTacToeBoard board;
	ASSERT_EQ(Invalid, board.getPiece(-1, 0));
}

TEST(TicTacToeBoardTest, invalidGetPieceColumnHigher){
	TicTacToeBoard board;
	ASSERT_EQ(Invalid, board.getPiece(0, 3));
}

TEST(TicTacToeBoardTest, invalidGetPieceColumnLower){
	TicTacToeBoard board;
	ASSERT_EQ(Invalid, board.getPiece(0, -1));
}

TEST(TicTacToeBoardTest, validGetPieceRow){
	TicTacToeBoard board;
	ASSERT_EQ(X, board.placePiece(0, 0));
	ASSERT_EQ(X, board.getPiece(0, 0));
    ASSERT_EQ(O, board.placePiece(1, 0));
    ASSERT_EQ(O, board.getPiece(1, 0));
    ASSERT_EQ(X, board.placePiece(2, 0));
    ASSERT_EQ(X, board.getPiece(2, 0));
}

TEST(TicTacToeBoardTest, validGetPieceColumn){
	TicTacToeBoard board;
	ASSERT_EQ(X, board.placePiece(0, 0));
	ASSERT_EQ(X, board.getPiece(0, 0));
    ASSERT_EQ(O, board.placePiece(0, 1));
    ASSERT_EQ(O, board.getPiece(0, 1));
    ASSERT_EQ(X, board.placePiece(0, 2));
    ASSERT_EQ(X, board.getPiece(0, 2));
}

