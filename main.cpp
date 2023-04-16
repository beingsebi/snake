#include <SFML/Graphics.hpp>
#include "headers/game.hpp"

int main()
{
    Game game;
    while (game.is_running())
    {
        game.render(); // maybe better in this order??
        game.update();
    }
    return 0;
}
