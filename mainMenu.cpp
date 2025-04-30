#include "mainMenu.h"



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

bool MainMenu::handleInput(sf::RenderWindow &window)
{
    return false;
}