#include "update.h"

void moveSnakeUp(void);
void moveSnakeDown(void);
void moveSnakeLeft(void);
void moveSnakeRight(void);
int snakeCollidesWithFood(void);
void updateFoodState(void);
void addRectToSnake();

void updateGame()
{
    if (keyUpPressed)
    {
        moveSnakeUp();
        if (snakeCollidesWithFood())
        {
            updateFoodState();
            addRectToSnake();
        }
    }

    if (keyDownPressed)
    {
        moveSnakeDown();
        if (snakeCollidesWithFood())
        {
            updateFoodState();
            addRectToSnake();
        }
    }

    if (keyLeftPressed)
    {
        moveSnakeLeft();
        if (snakeCollidesWithFood())
        {
            updateFoodState();
            addRectToSnake();
        }
    }

    if (keyRightPressed)
    {
        moveSnakeRight();
        if (snakeCollidesWithFood())
        {
            updateFoodState();
            addRectToSnake();
        }
    }
}

void moveSnakeUp(void)
{
    if (snake[0].y > 0)
    {
        for (int i = 0; i < snakeLength; i++)
        {
            if (i == 0)
            {
                snake[0].y -= 1;
                SDL_Delay(5);
            }
            else
            {
                snake[i].y = snake[i - 1].y + SNAKE_SIZE + 2;
                snake[i].x = snake[i - 1].x;
            }
        }
    }
}

void moveSnakeDown(void)
{
    if (snake[0].y < WINDOW_H - SNAKE_SIZE)
    {
        for (int i = 0; i < snakeLength; i++)
        {
            if (i == 0)
            {
                snake[0].y += 1;
                SDL_Delay(5);
            }
            else
            {
                snake[i].y = snake[i - 1].y - SNAKE_SIZE - 2;
                snake[i].x = snake[i - 1].x;
            }
        }
    }
}

void moveSnakeLeft(void)
{
    if (snake[0].x > 0)
    {
        for (int i = 0; i < snakeLength; i++)
        {
            if (i == 0)
            {
                snake[0].x -= 1;
                SDL_Delay(5);
            }
            else
            {
                snake[i].x = snake[i - 1].x + SNAKE_SIZE + 2;
                snake[i].y = snake[i - 1].y;
            }
        }
    }
}

void moveSnakeRight(void)
{
    if (snake[0].x < WINDOW_W - SNAKE_SIZE)
    {
        for (int i = 0; i < snakeLength; i++)
        {
            if (i == 0)
            {
                snake[0].x += 1;
                SDL_Delay(5);
            }
            else
            {
                snake[i].x = snake[i - 1].x - SNAKE_SIZE - 2;
                snake[i].y = snake[i - 1].y;
            }
        }
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

void addRectToSnake()
{
    snakeLength++;
    snakeIndex++;
    snake = realloc(snake, sizeof(SDL_Rect) * snakeLength);
    snake[snakeIndex] = (SDL_Rect){snake[0].x, snake[0].y + SNAKE_SIZE + 2, SNAKE_SIZE, SNAKE_SIZE};
}