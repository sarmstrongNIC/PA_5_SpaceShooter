#include "game.h"


int main()
{
    Game game;

    while(!game.isDone())
    {
        game.handleInput();
        game.update();
        game.render();
    }

    return 0;
}
