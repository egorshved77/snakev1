#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include <utility>

class Snake {
public:
    Snake(int startX, int startY);

    std::vector<std::pair<int, int>> getBody() const;
    bool isSnakeBody(int x, int y) const;
    void move();
    void grow();
    /// CO ROBI
    /// @param width SZEROKOSC PLANSZY W PIKSELACH
    /// @param height WYSOKOSC PLANSZY W PISKELACH
    /// @return prawda
    bool check_collision(int width, int height) const;
    char getDirection() const;
    void setDirection(char newDirection);


private:
    std::vector<std::pair<int, int>> body;
    char direction;
};

#endif // SNAKE_H
