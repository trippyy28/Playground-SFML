#include "Game.h"

int main()
{
    Game game;
    try
    {
        game.run();
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        // Handle error (e.g., show message to user, attempt recovery, etc.)
    }
    return 0;
}