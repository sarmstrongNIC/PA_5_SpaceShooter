#ifndef MAINMENU_H
#define MAINMENU_H

#include <SFML/Graphics.hpp>
#include <iostream>

const int TEXTSIZE = 100; 
class MainMenu
{
public:
    MainMenu(sf::RenderWindow &window);
    void display(sf::RenderWindow &window);
    void displayInstructions(sf::RenderWindow &window);
    void setColor(int i);

private:
    sf::Text mPlayText;
    sf::Text mInstructionsText;
    sf::Text mHighScoresText;
    sf::Text mExitText;
    sf::Text mInstructions;
    int mSelectedOption;
    sf::Font mFont;
};


#endif 