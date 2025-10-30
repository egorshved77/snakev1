#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "GameModel.h"
#include "GameView.h"
#include "MenuView.h"
#include <thread>
#include <chrono>

class GameController {
public:
    GameController(GameModel& model, GameView& gameView, MenuView& menuView,sf::RenderWindow &window);

    void run();

private:
    void MainMenu();
    void LevelMenu();
    void Game();
    void LeaderBoard();
    void GameOver();
    void processInput(sf::RenderWindow& window);

    GameModel& model;
    GameView& gameView;
    MenuView& menuView;
    sf::RenderWindow& window;
    bool inMenu;
    bool inLevelMenu;
    bool gameFinished = false;
    bool inLeaderBoard;
    bool inGameOver;
};

#endif // GAMECONTROLLER_H
