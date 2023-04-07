#include "events.h"

void moveSnakeUp();
void moveSnakeDown();
void moveSnakeLeft();
void moveSnakeRight();
void compareSnakeAndFoodPosition();

void handleKeydownEvents(SDL_Event *event)
{
    switch (event->key.keysym.sym)
    {
    case SDLK_UP:
        moveSnakeUp();
        compareSnakeAndFoodPosition();
        break;

    case SDLK_DOWN:
        moveSnakeDown();
        compareSnakeAndFoodPosition();
        break;

    case SDLK_LEFT:
        moveSnakeLeft();
        compareSnakeAndFoodPosition();
        break;

    case SDLK_RIGHT:
        moveSnakeRight();
        compareSnakeAndFoodPosition();
        break;

    default:
        break;
    }
}

void moveSnakeUp()
{
    if (snake.y > 0)
        snake.y -= 10;
}

void moveSnakeDown()
{
    if (snake.y < WINDOW_H - SNAKE_SIZE)
        snake.y += 10;
}

void moveSnakeLeft()
{
    if (snake.x > 0)
        snake.x -= 10;
}

void moveSnakeRight()
{
    if (snake.x < WINDOW_W - SNAKE_SIZE)
        snake.x += 10;
}

void compareSnakeAndFoodPosition()
{
    SDL_bool snakeEnterInCollisionWithFood = food.x < snake.x + SNAKE_SIZE && food.x + FOOD_SIZE >= snake.x && food.y > snake.y && food.y < snake.y + SNAKE_SIZE;

    if (snakeEnterInCollisionWithFood)
        foodState = 0;
}