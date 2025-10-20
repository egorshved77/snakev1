#include "Snake.h"

using namespace std;

Snake::Snake(int startX, int startY){
    body.push_back({startX, startY});
    direction = 'R';
}

std::vector<std::pair<int, int>> Snake::getBody() const {
    return body;
}

bool Snake::isSnakeBody(int x, int y) const {
    for (const auto& part : body) {
        if (part.first == x && part.second == y) {
            return true;
        }
    }
    return false;
}

void Snake::move() {
    pair<int, int> new_head = body[0];
    switch (direction) {
    case 'U': new_head.second -= 1; break;
    case 'D': new_head.second += 1; break;
    case 'L': new_head.first -= 1; break;
    case 'R': new_head.first += 1; break;
    }
    body.insert(body.begin(), new_head);
    body.pop_back();
}

void Snake::grow() {
    pair<int, int> new_segment = body.back();
    body.push_back(new_segment);
}

bool Snake::check_collision(int width, int height) const {
    const pair<int, int>& head = body[0];
    // Проверка границ поля
    if (head.first < 0 || head.first >= width || head.second < 0 || head.second >= height) {
        return true;
    }
    // Проверка столкновения с телом змейки
    for (int i = 2; i < body.size(); ++i) {  // Начинаем с 1, чтобы исключить голову
        if (body[i] == head) {
            return true;
        }
    }
    return false;
}

char Snake::getDirection() const {
    return direction;
}

void Snake::setDirection(char newDirection) {
    direction = newDirection;
}

