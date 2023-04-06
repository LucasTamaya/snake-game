#include "events.h"

void handleKeydownEvents(SDL_Event *event)
{
    switch (event->key.keysym.sym)
    {
    case SDLK_UP:
        snake.y -= 10;
        break;

    case SDLK_DOWN:
        snake.y += 10;
        break;

    case SDLK_LEFT:
        snake.x -= 10;
        break;

    case SDLK_RIGHT:
        snake.x += 10;
        break;

    default:
        break;
    }
}