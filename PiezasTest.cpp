/**
 * Unit Tests for Piezas
**/

#include <gtest/gtest.h>
#include "Piezas.h"
 
class PiezasTest : public ::testing::Test
{
	protected:
		PiezasTest(){} //constructor runs before each test
		virtual ~PiezasTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

TEST(PiezasTest, sanityCheck)
{
	ASSERT_TRUE(true);
}

//pieceAt blank return
TEST(PieazasTest, constructor) {
	Piezas game;
	ASSERT_TRUE(game.pieceAt(0,0) == Blank);
}

//Ensure first tuen is X and that dropPiece is working
TEST(PiezasTest, dropX)
{
	Piezas game;
	game.dropPiece(0);
	ASSERT_TRUE(game.pieceAt(0,0) == X);
}

//tests dropping and the switching of turns
TEST(PiezasTest, dropXO) {
	Piezas game;
	game.dropPiece(0);
	game.dropPiece(0);
	ASSERT_TRUE((game.pieceAt(0,0) == X) && (game.pieceAt(1,0) == O));
}

//Check out of bouinds for drop piece negative 
TEST(PiezasTest, dropPieceOOBN) 
{
	Piezas game;
	ASSERT_TRUE(game.dropPiece(-1) == Invalid);
}


//Check out of bouinds for drop piece > than # of cols
TEST(PiezasTest, dropPieceOOB) 
{	
	Piezas game;
	ASSERT_TRUE(game.dropPiece(6) == Invalid);
}

//test reset function
TEST(piezasTest, resetTest) {
		Piezas game;
		game.dropPiece(0);
		game.reset();
		ASSERT_TRUE(game.pieceAt(0,0) == Blank);
}

//test invalid pieceat
TEST(piezasTest, invalidPieceAt) {
	Piezas game;
	ASSERT_TRUE(game.pieceAt(10,1) == Invalid);
}

//test an x win through rows
TEST(piezasTest, xWin) {
		Piezas game;
		game.dropPiece(0); 
		game.dropPiece(0);
		game.dropPiece(1);
		game.dropPiece(1);
		game.dropPiece(2);
		game.dropPiece(2);
		game.dropPiece(3);
		game.dropPiece(0);
		game.dropPiece(3);
		game.dropPiece(1);
		game.dropPiece(2);
		game.dropPiece(3);
		ASSERT_TRUE(game.gameState() == X);
}

//test an x win through coulmns
TEST(piezasTest, xWinC) {
		Piezas game;
		game.dropPiece(0); 
		game.dropPiece(3);
		game.dropPiece(0);
		game.dropPiece(1);
		game.dropPiece(2);
		game.dropPiece(2);
		game.dropPiece(3);
		game.dropPiece(1);
		game.dropPiece(0);
		game.dropPiece(3);
		game.dropPiece(1);
		game.dropPiece(2);
		ASSERT_TRUE(game.gameState() == X);
}

//test an o win through columns
TEST(piezasTest, oWinC) {
		Piezas game;
		game.dropPiece(0); 
		game.dropPiece(3);
		game.dropPiece(1);
		game.dropPiece(3);
		game.dropPiece(0);
		game.dropPiece(2);
		game.dropPiece(2);
		game.dropPiece(1);
		game.dropPiece(2);
		game.dropPiece(3);
		game.dropPiece(1);
		game.dropPiece(0);
		ASSERT_TRUE(game.gameState() == O);
}

//test an o win through rows
TEST(piezasTest, oWin) {
		Piezas game;
		game.dropPiece(0); 
		game.dropPiece(0);
		game.dropPiece(1);
		game.dropPiece(1);
		game.dropPiece(2);
		game.dropPiece(2);
		game.dropPiece(0);
		game.dropPiece(3);
		game.dropPiece(1);
		game.dropPiece(3);
		game.dropPiece(2);
		game.dropPiece(3);
		ASSERT_TRUE(game.gameState() == O);
}

//test a game state on empty board
TEST(piezasTest, emptyBoard) {
		Piezas game;
		ASSERT_TRUE(game.gameState() == Invalid);
}

//test a tie game
TEST(piezasTest, tieGame) {
		Piezas game;
		game.dropPiece(0); 
		game.dropPiece(0);
		game.dropPiece(1);
		game.dropPiece(1);
		game.dropPiece(2);
		game.dropPiece(2);
		game.dropPiece(3);
		game.dropPiece(3);
		game.dropPiece(0);
		game.dropPiece(1);
		game.dropPiece(2);
		game.dropPiece(3);
		ASSERT_TRUE(game.gameState() == Blank);
}

//test a dropPiece on a fullBoard
TEST(piezasTest, fullBoard) {
		Piezas game;
		game.dropPiece(0); 
		game.dropPiece(0);
		game.dropPiece(1);
		game.dropPiece(1);
		game.dropPiece(2);
		game.dropPiece(2);
		game.dropPiece(3);
		game.dropPiece(3);
		game.dropPiece(0);
		game.dropPiece(1);
		game.dropPiece(2);
		game.dropPiece(3);
		ASSERT_TRUE(game.dropPiece(0) == Blank);
}














