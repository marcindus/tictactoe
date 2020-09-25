#include "Board.hpp"
#include "GUI.hpp"
#include <memory>

class Game
{
public:
Game();
private:
std::shared_ptr<Board> board_;
std::shared_ptr<GUI> gui_;
};