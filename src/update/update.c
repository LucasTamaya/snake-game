#include "update.h"

void moveSnakeUp(void);
void moveSnakeDown(void);
void moveSnakeLeft(void);
void moveSnakeRight(void);
int snakeCollidesWithFood(void);
void updateFoodState(void);

void updateGame()
{
    if (keyUpPressed)
        moveSnakeUp();

    if (keyDownPressed)
        moveSnakeDown();

    if (keyLeftPressed)
        moveSnakeLeft();

    if (keyRightPressed)
        moveSnakeRight();

    if (snakeCollidesWithFood())
        updateFoodState();
}

void moveSnakeUp(void)
{
    if (snake[0].y > 0)
    {
        snake[0].y -= 1;
        SDL_Delay(10);
    }
}

void moveSnakeDown(void)
{
    if (snake[0].y < WINDOW_H - SNAKE_SIZE)
    {
        snake[0].y += 1;
        SDL_Delay(10);
    }
}

void moveSnakeLeft(void)
{
    if (snake[0].x > 0)
    {
        snake[0].x -= 1;
        SDL_Delay(10);
    }
}

void moveSnakeRight(void)
{
    if (snake[0].x < WINDOW_W - SNAKE_SIZE)
    {
        snake[0].x += 1;
        SDL_Delay(10);
    }
}

int snakeCollidesWithFood(void)
{
    SDL_bool collisionBetweenSnakeAndFood = food.x < snake[0].x + SNAKE_SIZE && food.x + FOOD_SIZE >= snake[0].x && food.y > snake[0].y && food.y < snake[0].y + SNAKE_SIZE;

    if (collisionBetweenSnakeAndFood)
        return 1;
    else
        return 0;
}

void updateFoodState(void)
{
    foodState = 0;
}