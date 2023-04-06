#include "events.h"

void moveSnakeUp();
void moveSnakeDown();
void moveSnakeLeft();
void moveSnakeRight();

void handleKeydownEvents(SDL_Event *event)
{
    switch (event->key.keysym.sym)
    {
    case SDLK_UP:
        moveSnakeUp();
        break;

    case SDLK_DOWN:
        moveSnakeDown();
        break;

    case SDLK_LEFT:
        moveSnakeLeft();
        break;

    case SDLK_RIGHT:
        moveSnakeRight();
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