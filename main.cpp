#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
#include "game.hpp"

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
