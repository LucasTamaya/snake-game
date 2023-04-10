#include <stdio.h>
#include <SDL.h>
#include <SDL_ttf.h>

#include "constants.h"
#include "globals.h"
#include "utils/utils.h"
#include "game/game.h"

void programInit(void);
void windowAndRendererCreation(void);
void snakeInit(void);
void quitProgram(void);

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;
SDL_Rect *snake = NULL;
int snakeIndex = 0;
int snakeLength = 1;

int main(int argc, char **argv)
{
    programInit();
    windowAndRendererCreation();
    snakeInit();
    handleGame();
    quitProgram();
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

void snakeInit(void)
{
    // create snake as a dynamic array of SDL_Rect
    // so when the snake eat food, it will increment this array with 1 SDL_Rect
    snake = malloc(sizeof(SDL_Rect) * snakeLength);
    snake[snakeIndex] = (SDL_Rect){CENTER_X, CENTER_Y, SNAKE_SIZE, SNAKE_SIZE};
}

void quitProgram()
{
    free(snake);
    SDL_RenderClear(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}