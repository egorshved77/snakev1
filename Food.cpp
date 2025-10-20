#include "Food.h"

Food::Food(int startX, int startY, const Snake& snake)
{
    std::srand(std::time(NULL)); // Seed the random number generator
    generate_new_position(startX, startY, snake);
}

void Food::generate_new_position(int field_width, int field_height, const Snake& snake)
{
    int new_x, new_y;
    do
    {
        new_x = std::rand() % (field_width - 2) + 1;
        new_y = std::rand() % (field_height - 2) + 1;
    }
    while (snake.isSnakeBody(new_x, new_y));
    position = {new_x, new_y};
}

std::pair<int, int> Food::getPosition() const
{
    return position;
}


bool Food::isPositionValid(int x, int y, const Snake& snake) const {
    return !snake.isSnakeBody(x, y);
}
