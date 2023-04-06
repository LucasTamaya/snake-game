#include "game.h"

int programLaunched = 1;

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
            case SDL_QUIT:
                programLaunched = 0;
                break;

            default:
                break;
            }
        }
        cleanRenderer();
        SDL_RenderPresent(renderer);
    }
}