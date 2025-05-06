/**
 * @file mainMenu.cpp
 * @author Sam Armstrong
 * @brief main menu class
 * @version 0.1
 * @date 2025-05-05
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "mainMenu.h"

/**
 * @brief Construct a new Main Menu:: Main Menu object
 * 
 * @param window 
 */
MainMenu::MainMenu(sf::RenderWindow &window)
{
    if (!mFont.loadFromFile("game_over.ttf"))
    {
        std::cout << "Error loading font" << std::endl;
    }

    mPlayText.setFont(mFont);
    mPlayText.setString("Play Game");
    mPlayText.setCharacterSize(TEXTSIZE);
    mPlayText.setFillColor(sf::Color::White);
    mPlayText.setPosition(100, 100);

    mInstructionsText.setFont(mFont);
    mInstructionsText.setString("Instructions");
    mInstructionsText.setCharacterSize(TEXTSIZE);
    mInstructionsText.setFillColor(sf::Color::White);
    mInstructionsText.setPosition(100, 150);

    mHighScoresText.setFont(mFont);
    mHighScoresText.setString("High Scores");
    mHighScoresText.setCharacterSize(TEXTSIZE);
    mHighScoresText.setFillColor(sf::Color::White);
    mHighScoresText.setPosition(100, 200);

    mExitText.setFont(mFont);
    mExitText.setString("Exit");
    mExitText.setCharacterSize(TEXTSIZE);
    mExitText.setFillColor(sf::Color::White);
    mExitText.setPosition(100, 250);

    mInstructions.setFont(mFont);
    mInstructions.setString("Press Spacebar to shoot. \nMove with the left and right arrows. "
        "\nShoot enemies to eliminate them. "
        "\nTry to survive as long as you can!"
        "\n\n\nPress Spacebar to return to Main Menu");
    mInstructions.setCharacterSize(TEXTSIZE);
    mInstructions.setFillColor(sf::Color::White);
    mInstructions.setPosition(20, 150);
}

/**
 * @brief main menu display loop
 * 
 * @param window 
 */
void MainMenu::display(sf::RenderWindow &window)
{
    window.clear();
    window.draw(mPlayText);
    window.draw(mInstructionsText);
    window.draw(mHighScoresText);
    window.draw(mExitText);
    window.display();
}

/**
 * @brief display the instructions page
 * 
 * @param window 
 */
void MainMenu::displayInstructions(sf::RenderWindow &window)
{
    window.clear();
    window.draw(mInstructions);
    window.display();
}

/**
 * @brief sets the color for menu for selection 
 * 
 * @param i 
 */
void MainMenu::setColor(int i)
{
    mPlayText.setFillColor(sf::Color::White);
    mInstructionsText.setFillColor(sf::Color::White);
    mHighScoresText.setFillColor(sf::Color::White);
    mExitText.setFillColor(sf::Color::White);

    if(i == 0)
    {
        mPlayText.setFillColor(sf::Color::Red);
    }
    else if(i == 1)
    {
        mInstructionsText.setFillColor(sf::Color::Red);
    }
    else if(i == 2)
    {
        mHighScoresText.setFillColor(sf::Color::Red);
    }
    else if(i == 3)
    {
        mExitText.setFillColor(sf::Color::Red);
    }
}