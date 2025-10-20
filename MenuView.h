#ifndef MENUVIEW_H
#define MENUVIEW_H

#include <SFML/Graphics.hpp>

class MenuView
{
public:
    MenuView(sf::RenderWindow& window);

    void draw_start();
    void draw_level();
    void drawGameOverScreen(int score);

    void handleEvent(const sf::Event& event);

    bool isPlayButtonPressed(int x, int y) const;
    bool isExitButtonPressed(int x, int y) const;


    void drawScores(const std::vector<int>& scores);

    bool isMediumButtonPressed(int mouseX, int mouseY) const;
    bool isHardButtonPressed(int mouseX, int mouseY) const;
    bool isEasyButtonPressed(int mouseX, int mouseY) const;
    bool isLeaderBoardButtonPressed(int x, int y) const;
    bool isbackButtonPressed(int x, int y) const;
private:
    sf::Text titleText;
    sf::Text developed;
    sf::Text levelchangeText;
    sf::Text scoreText;
    sf::RenderWindow& window;
    sf::Font font;
    sf::Text playButton;
    sf::Text leaderboardButton;
    sf::Text exitButton;
    sf::Text easyButton;
    sf::Text mediumButton;
    sf::Text hardButton;
    sf::Text backButton;
    sf::Text gameOverText;
    sf::Text finalScoreText;

    void updateButtonColor(sf::Text& button, bool isHovered);
};

#endif // MENUVIEW_H
