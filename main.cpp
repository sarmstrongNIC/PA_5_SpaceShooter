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
//Main menu
//Display remaining lives on main screen
//Display current score on main screen
//Handle bullet hits
    //User shoots Enemy - DONE
        //NEXT - destructor when bullet hits spaceship. 
            //decrement lives
            //maybe have some display change like flashing red.
    //enemy shoots user
//Handle re-spawn, track lives
//ship pixel width = 209, height =241
//handle window resizing well.
    //dynamic ship origin rather than magic #s


//STRETCH GOALS
//moving background with stars
//intro sequence of automated spaceship movement at main menu screen