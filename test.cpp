#include <string>
#include <vector>
#include "Game.hpp"
#include "Board.hpp"
#include "gtest/gtest.h"

bool checkIfNumberInRow(std::vector<char>& input, char x, int number)
{
	std::string s;
    std::string toFind(number, x);
	std::transform(input.begin(), input.end(), std::back_inserter(s),[](char c) {return c;});
    size_t found = s.find(toFind); 
    if (found != std::string::npos)
    {
        return true;
    }
    return false;
}

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
    EXPECT_EQ(true, checkIfNumberInRow(vec, 'x', 3));
}


TEST_F(BoardTest, shouldReturnFalseIfNot3InLine)
{
    std::vector<char> vec{'x','o','x'};
    EXPECT_EQ(false, checkIfNumberInRow(vec, 'x', 3));
}





