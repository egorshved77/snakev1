#include "GameModel.h"
GameModel::GameModel(int width, int height, Difficulty level)
    :width(width), height(height), snake(width / 2 - 1, height / 2 - 1), food(width, height, snake)
{
    is_running = true;
    setDifficulty(level);
}


void GameModel::loadScores() {
    std::ifstream file("../scores.txt");
    scores.clear();
    int score;
    while (file >> score) {
        scores.push_back(score);
    }
    file.close();
    std::sort(scores.rbegin(), scores.rend());
}

void GameModel::saveScores() {
    std::ofstream file("../scores.txt");
    for (const int score : scores) {
        file << score << std::endl;
    }
    file.close();
}

void GameModel::updateScores(int newScore) {
    scores.push_back(newScore);
    std::sort(scores.rbegin(), scores.rend());
    if (scores.size() > 10) {
        scores.resize(10);
    }
    saveScores();
}
const std::vector<int>& GameModel::getScores() const {
    return scores;
}
void GameModel::setDifficulty(Difficulty level) {
    switch (level) {
    case EASY:
        base_delay = 300; // 300 milliseconds for easy level
        break;
    case MEDIUM:
        base_delay = 200; // 200 milliseconds for medium level
        break;
    case HARD:
        base_delay = 100; // 100 milliseconds for hard level
        break;
    default:
        base_delay = 200; // Default to medium level
        break;
    }
}

void GameModel::update() {
    snake.move();
    if (snake.getBody()[0] == food.getPosition()) {
        snake.grow();
        score += 10;

        food.generate_new_position(getWidth(), getHeight(), snake);
    }

    if (snake.check_collision(getWidth(), getHeight())) {
        is_running = false;
    }
}

void GameModel::reset() {
    snake = Snake(getWidth() / 2 - 1, getHeight() / 2 - 1);
    food.generate_new_position(getWidth(), getHeight(), snake);
    is_running = true;
    score=0;
}

int GameModel::calculateDelay() const {
    int score = getScore();
    int delay = base_delay - (score / 10) * 10;
    if (delay < 50)
    {
        delay = 50;
    }
    return delay;
}

bool GameModel::isGameOver() const {
    return !is_running;
}

int GameModel::getScore() const {
    return score;
}
int GameModel::getHeight() const
{
    return height;
}

int GameModel::getWidth() const
{
    return width;
}
