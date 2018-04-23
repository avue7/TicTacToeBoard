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
<<<<<<< HEAD
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


=======
*/
>>>>>>> d741d033c8b4b90c02b3fc3b844910e95165374b
