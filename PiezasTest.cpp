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

TEST(PiezasTest, sanitytest)
{
	ASSERT_TRUE(true);
}

//Test dropPiece
TEST(PiezasTest, dropPieceXtest)
{
	Piezas game;
	ASSERT_EQ(game.dropPiece(-1), Invalid);
}

TEST(PiezasTest, dropPieceOtest)
{
	Piezas game;
	ASSERT_EQ(game.dropPiece(0), O);
}
TEST(PiezasTest, dropPieceInvalidtest)
{
	Piezas game;
	ASSERT_EQ(game.dropPiece(6), Invalid);	
}

TEST(PiezasTest, pieceAtXTest)
{
	Piezas game;
	game.dropPiece(0);
	ASSERT_EQ(X, game.pieceAt(0,0)); 
	game.dropPiece(0);
}

TEST(PiezasTest, pieceAtOTest)
{
	Piezas game;
	ASSERT_EQ(O, game.pieceAt(1,0)); 
	ASSERT_EQ(game.pieceAt(-1,0), Invalid));
	ASSERT_EQ(game.pieceAt(1,5), Invalid));
}

TEST(PiezasTest, pieceAtTest)
{
	Piezas game;
	game.dropPiece(0);
	ASSERT_EQ(game.pieceAt(0,0), X);
	ASSERT_TRUE(game.pieceAt(1,0), Blank);
}
TEST(PiezasTest, peiceInvalidtest)
{
	Piezas game;
	ASSERT_EQ(game.dropPiece(0,6), Invalid);
}

//Test Reset
TEST(PiezasTest, ResetTest)
{
	Piezas game;
	game.dropPiece(0);
	game.reset();
	ASSERT_EQ(game.pieceAt(0,0), Blank);
}

//Test gameState
TEST(PiezasTest, unfinishedstatetest)
{
	Piezas game;
	ASSERT_EQ(game.gameState(), Invalid);
}

TEST(PiezasTest, gameStateTietest)
{
	Piezas game;
	for(int i=0; i<BOARD_ROWS; i++){
    	for(int j=0; j<BOARD_COLS; j++){
        	game.dropPiece(j);
    	}
	}
	ASSERT_EQ(game.gameState(), Blank);
}

TEST(PiezasTest, gameStateRowtest)
{
	Piezas game;
	{
	for(int i=0; i<3; i++) {
		game.dropPiece(i);
		game.dropPiece(i);
	}
	game.dropPiece(3); 
	for(int i=0; i<4; i++) {
		game.dropPiece(i);
	}
	game.dropPiece(3); 
	ASSERT_TEST(X, game.gameState());
}
}

TEST(PiezasTest, colgameStatetest)
{
	Piezas obj;
	game.dropPiece(0);
	game.dropPiece(0);
	game.dropPiece(1);
	game.dropPiece(1);
	game.dropPiece(2);
	game.dropPiece(2);
	game.dropPiece(0);
	game.dropPiece(3);
	game.dropPiece(2);
	game.dropPiece(3);
	game.dropPiece(3);
	game.dropPiece(1);
	ASSERT_EQ(O, obj.gameState());
}

TEST(PiezasTest, Xcolgamestatetest)
{
	Piezas game;
	game.dropPiece(0);
	game.dropPiece(1);
	game.dropPiece(0);
	game.dropPiece(2);
	game.dropPiece(3);
	game.dropPiece(2);
	game.dropPiece(1);
	game.dropPiece(3);
	game.dropPiece(0);
	game.dropPiece(3);
	game.dropPiece(2);
	game.dropPiece(1);
	ASSERT_EQ(X, game.gameState());
}

TEST(PiezasTest, OColgamestatetest)
{
	Piezas game;
	game.dropPiece(1);
	game.dropPiece(0);
	game.dropPiece(2);
	game.dropPiece(3);
	game.dropPiece(3);
	game.dropPiece(0);
	game.dropPiece(1);
	game.dropPiece(2);
	game.dropPiece(2);
	game.dropPiece(0);
	game.dropPiece(3);
	game.dropPiece(1);
	ASSERT_EQ(O, game.gameState());
}