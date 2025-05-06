#include "mainMenu.h"



MainMenu::MainMenu(sf::RenderWindow &window)
{
    std::cout << "MainMenu Constructor Called " << std::endl;

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

void MainMenu::display(sf::RenderWindow &window)
{
    window.clear();
    window.draw(mPlayText);
    window.draw(mInstructionsText);
    window.draw(mHighScoresText);
    window.draw(mExitText);
    window.display();
}

void MainMenu::displayInstructions(sf::RenderWindow &window)
{
    window.clear();
    window.draw(mInstructions);
    window.display();
}

bool MainMenu::handleInput(sf::RenderWindow &window)
{
    return false;
}

void MainMenu::setColor(int i)
{
    mPlayText.setFillColor(sf::Color::White);
    mInstructionsText.setFillColor(sf::Color::White);
    mHighScoresText.setFillColor(sf::Color::White);
    mExitText.setFillColor(sf::Color::White);

    if(i == 0)
    {
        //std::cout << "setColor is called " << std::endl; 
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