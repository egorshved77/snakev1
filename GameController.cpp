#include "GameController.h"


GameController::GameController(GameModel& model,GameView& gameView, MenuView& menuView,sf::RenderWindow &window)
    : model(model), gameView(gameView), menuView(menuView), window(window),inMenu(true),inLevelMenu(false),inLeaderBoard(false),inGameOver(false
        )
{

    model.loadScores();
}


void GameController::run() {
    while (window.isOpen()) {
        if (inMenu) MainMenu();
        else if (inLevelMenu) LevelMenu();
        else if(inLeaderBoard) LeaderBoard();
        else if(inGameOver) GameOver();
        else Game();
    }
}

void GameController::LevelMenu()
{
    menuView.draw_level();
    sf::Event event;
    menuView.handleEvent(event);
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        if (menuView.isbackButtonPressed(event.mouseButton.x, event.mouseButton.y)) {model.setDifficulty(GameModel::EASY);
            inLevelMenu=false;
            inGameOver=false;
            inLeaderBoard=false;
            inMenu=true;
        }

        if (menuView.isEasyButtonPressed(event.mouseButton.x, event.mouseButton.y)) {
           model.setDifficulty(GameModel::EASY);
            inLevelMenu=false;

        }

        if (menuView.isMediumButtonPressed(event.mouseButton.x, event.mouseButton.y)) {
            model.setDifficulty(GameModel::MEDIUM);
            inLevelMenu=false;
        }

        if (menuView.isHardButtonPressed(event.mouseButton.x, event.mouseButton.y)) {
            model.setDifficulty(GameModel::HARD);
            inLevelMenu=false;
        }

        model.reset();
    }
}

void GameController::LeaderBoard()
{   menuView.drawScores(model.getScores());
    sf::Event event;
    menuView.handleEvent(event);

    while (window.pollEvent(event))
    {   if (menuView.isbackButtonPressed(event.mouseButton.x, event.mouseButton.y)) {model.setDifficulty(GameModel::EASY);
        inLeaderBoard=false;
        inMenu=true;
    }
        if (event.type == sf::Event::Closed) {
            window.close();
        }
    }
}

void GameController::GameOver()
{
    menuView.drawGameOverScreen(model.getScore());
    sf::Event event;
    menuView.handleEvent(event);

    while (window.pollEvent(event))
    {   if (menuView.isbackButtonPressed(event.mouseButton.x, event.mouseButton.y)) {model.setDifficulty(GameModel::EASY);
        inGameOver=false;
        inMenu=true;
    }
        if (event.type == sf::Event::Closed) {
            window.close();
        }
    }
}

void GameController::MainMenu() {
    menuView.draw_start();
    sf::Event event;
    menuView.handleEvent(event);
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                if (menuView.isPlayButtonPressed(event.mouseButton.x, event.mouseButton.y)) {
                    inMenu = false;
                    inLevelMenu=true;
                }

                if (menuView.isLeaderBoardButtonPressed(event.mouseButton.x, event.mouseButton.y)) {
                    inMenu = false;
                    inLeaderBoard=true;

                }
                // Проверяем нажатие кнопки Exit
                if (menuView.isExitButtonPressed(event.mouseButton.x, event.mouseButton.y)) {
                    window.close();
                }
            }
        }
    }
}

void GameController::Game()
{
    processInput(window);
    if (model.isGameOver()) {
        model.updateScores(model.getScore());
        inGameOver = true;
    }
    model.update();
    gameView.updateScoreText();

    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("../images/grass.jpg"))
    {
        return;
    }
    sf::Sprite background(backgroundTexture);


    background.setTexture(backgroundTexture);

    sf::Vector2u windowSize = window.getSize();
    sf::Vector2u textureSize = backgroundTexture.getSize();


    float scaleX = static_cast<float>(windowSize.x) / textureSize.x;
    float scaleY = static_cast<float>(windowSize.y) / textureSize.y;


    background.setScale(scaleX, scaleY);
    window.clear(sf::Color::Black);
    window.draw(background);



    gameView.draw(window);
    window.display();
    std::this_thread::sleep_for(std::chrono::milliseconds(model.calculateDelay()));
}

void GameController::processInput(sf::RenderWindow& window) {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Escape) {
                model.is_running = false;
                inMenu = false;
            }

            char currentDirection = model.snake.getDirection();

            if (event.key.code == sf::Keyboard::A) {
                //turn left
                switch (currentDirection) {
                case 'U': model.snake.setDirection('L'); break;
                case 'D': model.snake.setDirection('R'); break;
                case 'L': model.snake.setDirection('D'); break;
                case 'R': model.snake.setDirection('U'); break;
                }
            }

            if (event.key.code == sf::Keyboard::D) {
                //turn right
                switch (currentDirection) {
                case 'U': model.snake.setDirection('R'); break;
                case 'D': model.snake.setDirection('L'); break;
                case 'L': model.snake.setDirection('U'); break;
                case 'R': model.snake.setDirection('D'); break;
                }
            }
        }
    }
}
