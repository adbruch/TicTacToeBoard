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
TEST(TicTacToeBoardTest, unitTestName)
{
	ASSERT_TRUE(true);
}
*/
//Bottom tests are about ToggleTurn
TEST(TicTacBoardTest, toggleTurnO)
{
	TicTacToeBoard ticTacToeBoard;
	ASSERT_EQ( ticTacToeBoard.toggleTurn(), O);
}

TEST(TicTacBoardTest, toggleTurnX)
{
	TicTacToeBoard ticTacToeBoard;
	ticTacToeBoard.toggleTurn();
	ASSERT_EQ( ticTacToeBoard.toggleTurn(), X);
}
//PlacingPieces test
TEST(TicTacBoardTest, placePiece0_0X)
{
	TicTacToeBoard ticTacToeBoard;
	ASSERT_EQ( ticTacToeBoard.placePiece(0,0), X);
}

TEST(TicTacBoardTest, placePieceCenterX)
{
	TicTacToeBoard ticTacToeBoard;
	ASSERT_EQ( ticTacToeBoard.placePiece(1,1), X);
}
//Going Second
TEST(TicTacBoardTest, placePiece0_0O)
{
	TicTacToeBoard ticTacToeBoard;
	ticTacToeBoard.toggleTurn();
	ASSERT_EQ( ticTacToeBoard.placePiece(0,0), O);
}

TEST(TicTacBoardTest, placePieceCenterO)
{
	TicTacToeBoard ticTacToeBoard;
	ticTacToeBoard.toggleTurn();
	ASSERT_EQ( ticTacToeBoard.placePiece(1,1), O);
}
//Invalid piece test going out of bounds
TEST(TicTacBoardTest, placePieceInvalid)
{
	TicTacToeBoard ticTacToeBoard;
	ASSERT_EQ( ticTacToeBoard.placePiece(3,3), Invalid);
}
//Placing an O where an X is already, should get back what the original piece was.
TEST(TicTacBoardTest, placePieceExisting)
{
	TicTacToeBoard ticTacToeBoard;
	ticTacToeBoard.placePiece(1,1);
	ASSERT_EQ( ticTacToeBoard.placePiece(1,1), X);
}