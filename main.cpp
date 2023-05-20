// Good luck!
#include <SFML/Graphics.hpp>
#include "headers/game.hpp"
#include <iostream>
#include <fstream>
using std::cout;
using std::endl;
using std::ofstream;
void play();
int main()
{
    try
    {
        play();
    }
    catch (file_error &err)
    {
        cout << err.what() << endl;
    }
    catch (score_error &err)
    {
        cout << err.what() << endl;
        ofstream gg(Constants::HIGH_SCORE_PATH);
        gg << 0;
        gg.flush();
        // try again
        try
        {
            play();
        }
        catch (...)
        {
            cout << "Something went wrong... :(" << endl;
        }
    }
    catch (...)
    {
        cout << "Something went wrong... :(" << endl;
    }
    return 0;
}
void play()
{
    auto &game = Game<double>::get_game();

    while (game.is_running())
    {
        game.render(); // maybe  better to render first and update later in  order  to reduce lag?
        game.update();
    }
}