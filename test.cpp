
#include <vector>
#include "Game.hpp"
#include "Board.hpp"
#include "gtest/gtest.h"

bool checkIfNumberInRow(std::vector<char>& input)
{
    std::cout << input[0] << "\n";
    return true;
}

struct BoardTest : public ::testing::Test
{
//    std::string emptyBoard3x3String = ". . .\n. . .\n. . .";
    std::string emptyBoard3x3String = "";
};

TEST_F(BoardTest, BoardShouldDoSomething)
{
    Board br(3, 3);
    EXPECT_EQ(br.toString(), emptyBoard3x3String);
}

TEST_F(BoardTest, shouldReturnTrueIf3InLine)
{
    std::vector<char> vec{'x','x','x'};
    EXPECT_EQ(true, checkIfNumberInRow(vec));
}
