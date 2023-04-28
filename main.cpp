#include <SFML/Graphics.hpp>
#include "headers/game.hpp"
#include <iostream>
#include <fstream>
using std::cout;
using std::endl;
using std::ofstream;

int main()
{
try_again:
    try
    {
        Game game;

        while (game.is_running())
        {
            game.render(); // maybe  better to render first and update later in  order  to reduce lag?
            game.update();
        }
    }
    catch (file_error &err)
    {
        cout << err.what();
    }
    catch (score_error &err)
    {
        cout << err.what() << endl;
        ofstream gg(Constants::HIGH_SCORE_PATH);
        gg << 0;
        gg.flush();
        goto try_again;
    }
    catch (...)
    {
        cout << "Something went wrong... :(" << endl;
    }
    return 0;
}
