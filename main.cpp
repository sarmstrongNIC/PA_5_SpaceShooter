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


//TODO


//populate enemies
    //EnemyBullet Class?
//Main menu
//Track points and high scores
//Handle re-spawn, track lives
//ship pixel width = 209, height =241
//handle window resizing well.
    //dynamic ship origin rather than magic #s
