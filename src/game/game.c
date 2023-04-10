#include "game.h"

void handleKeydownEvents(SDL_Event *event);
void resetPressedKey();

int programLaunched = 1;
int keyUpPressed = 0;
int keyDownPressed = 0;
int keyLeftPressed = 0;
int keyRightPressed = 0;

void handleGame(void)
{
    // executed every frame to handle the game
    while (programLaunched)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_KEYDOWN:
                handleKeydownEvents(&event);
                break;

            case SDL_QUIT:
                programLaunched = 0;
                break;

            default:
                break;
            }
        }
        cleanRenderer();
        updateGame();
        renderGame();
    }
}

void handleKeydownEvents(SDL_Event *event)
{
    switch (event->key.keysym.sym)
    {
    case SDLK_UP:
        resetPressedKey();
        keyUpPressed = 1;
        break;

    case SDLK_DOWN:
        resetPressedKey();
        keyDownPressed = 1;
        break;

    case SDLK_LEFT:
        resetPressedKey();
        keyLeftPressed = 1;
        break;

    case SDLK_RIGHT:
        resetPressedKey();
        keyRightPressed = 1;
        break;

    default:
        break;
    }
}

void resetPressedKey()
{
    keyUpPressed = 0;
    keyDownPressed = 0;
    keyLeftPressed = 0;
    keyRightPressed = 0;
}