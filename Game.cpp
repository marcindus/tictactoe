#include "Game.hpp"

Game::Game()
{
    gui_ = std::make_shared<GUI>();
    board_ = std::make_shared<Board>(3, 3);
}