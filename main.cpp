#include "game.h"
#include <iostream>


int main()
{
    
    sf::RenderWindow window(sf::VideoMode(1000, 800), "SpaceShooters");
    Game game(window);
    int menuChoice = -1;
    int menuHighlight = -1;
    sf::Event event;
    
    while (window.pollEvent(event)){}

    while(!game.isDone(window))
    {
        while(menuChoice < 0 || menuChoice > 4)
        {
            menuChoice = game.displayMainMenu(window);
            menuHighlight = game.getSelectedMenuItem();
            // std::cout << "Enter Menu Choice: " << std::endl;
            // std::cin >> menuChoice;
            //std::cout << "MenuHighlight is: " << menuHighlight << std::endl;
            game.mMenu.setColor(menuHighlight);

        }
        if (menuChoice == 0)
        {
            game.mMenu.setColor(menuChoice);
            game.handleInput(window);
            game.update(window);
            game.render(window);
        }
        else if(menuChoice == 1)
        {
            //game.mMenu.setColor(menuChoice);
            //display instructions
        }
        else if(menuChoice == 2)
        {
            //game.mMenu.setColor(menuChoice);
            //display high scores
        }
        else if(menuChoice == 3)
        {
            //game.mMenu.setColor(menuChoice);
            //exit
            std::cout << "game done selected " << std::endl; 
            game.setGameDone();
        }
        
    }

    return 0;
}

//ship pixel width = 209, height =241

//TODO

//populate enemies

//Main menu start screen
//Display current score on main screen
//User not affected by bullets for 3 seconds during respawn
//enemy destroyed and disappears when hit
//Handle re-spawn
//when out of lives        
    //pop up displaying score and asking to play again
        //displays under Game Over message, waits 2 or 3 seconds
        ///Game Over animating up in Y before displaying play again option would be cool
        //keyboard to select play again or exit
//cooldown for enemy bullets (shoot one at a time like spaceship)
    //maybe not necessary since button push shot is only for debugging

//generate rows of enemies
    //define rules of enemy shots.
    //respawn different color enemy with faster/different shots after eliminating a set


//STRETCH GOALS
//moving background with stars
//intro sequence of automated spaceship movement at main menu screen
//maybe have some display change like flashing red when user hit
//handle window resizing well.
    //dynamic ship origin rather than magic #s
//fade in display for user when respawning
    //flash red when hit

//DONE

//Handle bullet hits
    //User shoots Enemy - DONE
    //enemy shoots user
    //remove bullet from vector when there is a hit 
//Display remaining lives on main screen
//when out of lives        
    //display game over screen
//decrement lives when hit   

//BUGS
    ////Bullet hit counts as hit when it crosses bounding box but misses ship (top corners)
    //at main menu, game doesnt exit when window is closed