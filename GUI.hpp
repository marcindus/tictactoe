#include <string>

namespace ConstString
{
    std::string separator("*", 35);
}

class GUI
{
public:
    GUI();

private:
    void PrintInitialInformation();
};