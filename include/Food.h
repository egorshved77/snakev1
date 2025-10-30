#ifndef FOOD_H
#define FOOD_H

#include <utility>
#include "Snake.h"
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

class Food {
public:
    Food(int startX, int startY, const Snake& snake);

    std::pair<int, int> getPosition() const;
    void generate_new_position(int field_width, int field_height, const Snake& snake);

private:
    std::pair<int, int> position;
    bool isPositionValid(int x, int y, const Snake& snake) const;
};

#endif // FOOD_H
