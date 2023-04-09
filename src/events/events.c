#include "events.h"

void moveSnakeUp(void);
void moveSnakeDown(void);
void moveSnakeLeft(void);
void moveSnakeRight(void);
int snakeCollidesWithFood(void);
void updateFoodState(void);
void addRectToSnake(int x, int y);

void handleKeydownEvents(SDL_Event *event)
{
    switch (event->key.keysym.sym)
    {
    case SDLK_UP:
        moveSnakeUp();
        if (snakeCollidesWithFood())
        {
            updateFoodState();
            addRectToSnake(snake[0].x, snake[0].y + SNAKE_SIZE + 2);
        }
        break;

    case SDLK_DOWN:
        moveSnakeDown();
        if (snakeCollidesWithFood())
        {
            updateFoodState();
            addRectToSnake(snake[0].x, snake[0].y - SNAKE_SIZE - 2);
        }
        break;

    case SDLK_LEFT:
        moveSnakeLeft();
        if (snakeCollidesWithFood())
        {
            updateFoodState();
            addRectToSnake(snake[0].x + SNAKE_SIZE + 2, snake[0].y);
        }
        break;

    case SDLK_RIGHT:
        moveSnakeRight();
        if (snakeCollidesWithFood())
        {
            updateFoodState();
            addRectToSnake(snake[0].x - SNAKE_SIZE - 2, snake[0].y);
        }
        break;

    default:
        break;
    }
}

void moveSnakeUp(void)
{
    if (snake[0].y > 0)
        snake[0].y -= 10;
}

void moveSnakeDown(void)
{
    if (snake[0].y < WINDOW_H - SNAKE_SIZE)
        snake[0].y += 10;
}

void moveSnakeLeft(void)
{
    if (snake[0].x > 0)
        snake[0].x -= 10;
}

void moveSnakeRight(void)
{
    if (snake[0].x < WINDOW_W - SNAKE_SIZE)
        snake[0].x += 10;
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

void addRectToSnake(int x, int y)
{
    snakeLength++;
    snakeIndex++;
    snake = realloc(snake, sizeof(SDL_Rect) * snakeLength);
    snake[snakeIndex] = (SDL_Rect){x, y, SNAKE_SIZE, SNAKE_SIZE};
}