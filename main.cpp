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

//ship pixel width = 209, height =241

//TODO

//populate enemies
//Main menu
//Display remaining lives on main screen
//Display current score on main screen

    //decrement lives
//Handle re-spawn, track lives



//STRETCH GOALS
//moving background with stars
//intro sequence of automated spaceship movement at main menu screen
//maybe have some display change like flashing red when user hit
//handle window resizing well.
    //dynamic ship origin rather than magic #ss

//DONE

//Handle bullet hits
    //User shoots Enemy - DONE
    //enemy shoots user
    //remove bullet from vector when there is a hit 

//BUGS
    ////Bullet hit counts as hit when it crosses bounding box but misses ship