#include <string>
#include <vector>
#include "Game.hpp"
#include "Board.hpp"
#include "gtest/gtest.h"



void getDiagonal(){}

struct BoardTest : public ::testing::Test
{
    std::string emptyBoard3x3String = ". . . \n. . . \n. . . \n";
};

TEST_F(BoardTest, BoardShouldDoSomething)
{
    Board br(3, 3);
    EXPECT_EQ(br.toString(), emptyBoard3x3String);
}

TEST_F(BoardTest, shouldReturnTrueIf3InLine)
{
    std::vector<char> vec{'x','x','x'};
 //   EXPECT_EQ(true, checkIfNumberInRow(vec, 'x', 3));
}


TEST_F(BoardTest, shouldReturnFalseIfNot3InLine)
{
    std::vector<char> vec{'x','o','x'};
  //  EXPECT_EQ(false, checkIfNumberInRow(vec, 'x', 3));
}





