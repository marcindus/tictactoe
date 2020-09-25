#include "Game.hpp"

Game::Game()
{
    board_ = std::make_shared<Board>(3, 3);
    gui_ = std::make_shared<GUI>(board_);
}