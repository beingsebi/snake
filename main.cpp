#include <SFML/Graphics.hpp>
#include "headers/game.hpp"

int main()
{
    Game game;
    while (game.is_running())
    {
        game.update();
        game.render();
    }
    return 0;
}
