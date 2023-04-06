#include "render.h"

SDL_Color color = {22, 255, 0, 255};
SDL_Rect snake = {CENTER_X, CENTER_Y, SNAKE_SIZE, SNAKE_SIZE};

void renderGame(void)
{
    // set the color for the drawing
    if (SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a) != 0)
        exitWithError(__FILE__, __LINE__);

    // render the snake
    if (SDL_RenderFillRect(renderer, &snake) != 0)
        exitWithError(__FILE__, __LINE__);

    // update the renderer
    SDL_RenderPresent(renderer);
}

void cleanRenderer(void)
{
    if (SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255) != 0)
        exitWithError(__FILE__, __LINE__);

    if (SDL_RenderClear(renderer) != 0)
        exitWithError(__FILE__, __LINE__);
}