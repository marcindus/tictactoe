
#include <vector>
#include <sstream>
#include <string>

#include "Game.hpp"
#include "Board.hpp"
#include "gtest/gtest.h"

using Board = std::vector<std::vector<char>>;



std::string toString(Board& br)
{
    std::stringstream stm;
    for (auto& row : br)
    {
        for (auto& col : row)
        {
            stm << col << " ";
        }
        stm << std::endl;
    }
    return stm.str();
}

Board build_empty_board(size_t size_x, size_t size_y)
{
    std::vector<std::vector<char> > vec( size_x , std::vector<char> (size_y, '.'));
    return vec;
}


struct BoardTest : public ::testing::Test
{
    Board empty_board_3x3 = {{'.', '.', '.'}, {'.', '.', '.'}, {'.', '.', '.'}};
};

TEST_F(BoardTest, BoardSghouldDoSomething)
{
    Board br = build_empty_board(4,3);
    std::cout << toString(br);

    EXPECT_EQ(br, empty_board_3x3);
}
