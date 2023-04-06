#include <stdio.h>
#include <SDL.h>
#include <SDL_ttf.h>

#include "constants.h"
#include "globals.h"
#include "utils/utils.h"
#include "game/game.h"

void programInit(void);
void windowAndRendererCreation(void);

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;

int main(int argc, char **argv)
{
    programInit();
    windowAndRendererCreation();
    handleGame();
    return 0;
}

void programInit(void)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
        exitWithError(__FILE__, __LINE__);
}

void windowAndRendererCreation(void)
{
    window = SDL_CreateWindow("Snake Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_W, WINDOW_H, SDL_WINDOW_SHOWN);
    if (window == NULL)
        exitWithError(__FILE__, __LINE__);

    renderer = SDL_CreateRenderer(window, -1, 0);
    if (renderer == NULL)
        exitWithError(__FILE__, __LINE__);
}