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
//PlacingPieces test-------------------------------------------------------------------------
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
//-------------------------------------------------------------------------------------------------------
//getPiece tests
TEST(TicTacBoardTest, getPiece0_0Blank)
{
	TicTacToeBoard ticTacToeBoard;
	ASSERT_EQ( ticTacToeBoard.getPiece(0,0), Blank);
}

TEST(TicTacBoardTest, getPieceCenterBlank)
{
	TicTacToeBoard ticTacToeBoard;
	ASSERT_EQ( ticTacToeBoard.getPiece(1,1), Blank);
}

TEST(TicTacBoardTest, getPiece0_0X)
{
	TicTacToeBoard ticTacToeBoard;
	ticTacToeBoard.placePiece(0,0);
	ASSERT_EQ( ticTacToeBoard.getPiece(0,0), X);
}

TEST(TicTacBoardTest, getPieceCenterX)
{
	TicTacToeBoard ticTacToeBoard;
	ticTacToeBoard.placePiece(1,1);
	ASSERT_EQ( ticTacToeBoard.getPiece(1,1), X);
}

TEST(TicTacBoardTest, getPieceCenterInvalid)
{
	TicTacToeBoard ticTacToeBoard;
	ASSERT_EQ( ticTacToeBoard.getPiece(3,-1), Invalid);
}

TEST(TicTacBoardTest, getPiece2onBoardX)
{
	TicTacToeBoard ticTacToeBoard;
	ticTacToeBoard.placePiece(0,0);
	ticTacToeBoard.placePiece(1,1);
	ASSERT_EQ( ticTacToeBoard.getPiece(0,0), X);
}

TEST(TicTacBoardTest, getPiece2onBoardO)
{
	TicTacToeBoard ticTacToeBoard;
	ticTacToeBoard.placePiece(0,0);
	ticTacToeBoard.placePiece(1,1);
	ASSERT_EQ( ticTacToeBoard.getPiece(1,1), O);
}
//-----------------------------------------------------------
//getWinner tests
TEST(TicTacBoardTest, WinnerX)
{
	TicTacToeBoard ticTacToeBoard;
	ticTacToeBoard.placePiece(0,0); //X in upper left corner
	ticTacToeBoard.placePiece(1,1);
	ticTacToeBoard.placePiece(0,1); //X in middle left
	ticTacToeBoard.placePiece(2,2);
	ticTacToeBoard.placePiece(0,2); //X in the bottom left
	ASSERT_EQ( ticTacToeBoard.getWinner(), X);
}

TEST(TicTacBoardTest, WinnerO)
{
	TicTacToeBoard ticTacToeBoard;
	ticTacToeBoard.placePiece(1,1);
	ticTacToeBoard.placePiece(0,0); //O in upper left corner
	ticTacToeBoard.placePiece(1,1);
	ticTacToeBoard.placePiece(0,1); //O in middle left	
	ticTacToeBoard.placePiece(1,2);	
	ticTacToeBoard.placePiece(0,2); //O in the bottom left
	ASSERT_EQ( ticTacToeBoard.getWinner(), O);
}

TEST(TicTacBoardTest, gameNotOver)
{
	TicTacToeBoard ticTacToeBoard;
	ticTacToeBoard.placePiece(1,1);
	ticTacToeBoard.placePiece(0,0); //O in upper left corner
	ticTacToeBoard.placePiece(1,1);
	ASSERT_EQ( ticTacToeBoard.getWinner(), Invalid);
}

TEST(TicTacBoardTest, gameNotOver2)
{
	TicTacToeBoard ticTacToeBoard;
	ticTacToeBoard.placePiece(1,1);
	ticTacToeBoard.placePiece(0,0);
	ticTacToeBoard.placePiece(1,1);
	ticTacToeBoard.placePiece(2,1);
	ticTacToeBoard.placePiece(2,0);
	ticTacToeBoard.placePiece(0,1);
	ASSERT_EQ( ticTacToeBoard.getWinner(), Invalid);
}

TEST(TicTacBoardTest, noWinner)
{
	TicTacToeBoard ticTacToeBoard;
	ticTacToeBoard.placePiece(0,0);
	ticTacToeBoard.placePiece(1,1);
	ticTacToeBoard.placePiece(0,1);
	ticTacToeBoard.placePiece(0,2);
	ticTacToeBoard.placePiece(1,2);
	ticTacToeBoard.placePiece(1,0);
	ticTacToeBoard.placePiece(2,0);
	ticTacToeBoard.placePiece(2,1);
	ticTacToeBoard.placePiece(2,2);
	ASSERT_EQ( ticTacToeBoard.getWinner(), Blank);
	}