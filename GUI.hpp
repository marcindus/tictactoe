#pragma once
#include <string>
#include <memory>
#include "Board.hpp"

static const std::string SEPARATOR;

class GUI
{
public:
    GUI(std::shared_ptr<Board> board);

private:
    void PrintInitialInformation();
    std::shared_ptr<Board> board_;
};