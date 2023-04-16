#include <SFML/Graphics.hpp>
#include "headers/game.hpp"

int main()
{
    Game game;
    while (game.is_running())
    {
        game.render(); // maybe better to render first and update later in  order  to reduce lag?
        game.update();
    }
    return 0;
}
