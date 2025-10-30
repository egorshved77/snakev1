#ifndef GAMEMODEL_H
#define GAMEMODEL_H

#include "Snake.h"
#include "Food.h"
#include <algorithm>
#include <fstream>
class GameModel {
public:
    enum Difficulty { EASY, MEDIUM, HARD };

    GameModel(int width, int height, Difficulty level);

    void update();
    void reset();
    bool isGameOver() const;
    int getScore() const;
    int getWidth() const;
    int getHeight() const;
    /// FUNCTION INCREASES THE SPEED
    /// @return INCREASED
    int calculateDelay() const;

    Snake snake;
    Food food;
    bool is_running;
    void setDifficulty(Difficulty level);

    void loadScores();
    void saveScores();
    void updateScores(int newScore);
    const std::vector<int>& getScores() const;
private:
    std::vector<int> scores;
    int base_delay;
    int score;
    int width;
    int height;
};

#endif // GAMEMODEL_H
