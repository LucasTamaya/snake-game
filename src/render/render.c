#include "render.h"

void renderSnake(void);
void generateFood(void);
void renderFood(void);

SDL_Color color = {22, 255, 0, 255};
SDL_Color foodColor = {226, 24, 24, 255};
SDL_Rect food = {};
int foodState = 0;

void renderGame(void)
{
    renderFood();
    renderSnake();
    SDL_RenderPresent(renderer);
}

void cleanRenderer(void)
{
    if (SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255) != 0)
        exitWithError(__FILE__, __LINE__);

    if (SDL_RenderClear(renderer) != 0)
        exitWithError(__FILE__, __LINE__);
}

void renderSnake(void)
{

    // set the color for the snake
    if (SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a) != 0)
        exitWithError(__FILE__, __LINE__);

    // render the snake
    if (SDL_RenderFillRects(renderer, snake, snakeLength) != 0)
        exitWithError(__FILE__, __LINE__);
}

void generateFood(void)
{
    food.x = getRandomNb(WINDOW_W - FOOD_SIZE);
    food.y = getRandomNb(WINDOW_H - FOOD_SIZE);
    food.w = FOOD_SIZE;
    food.h = FOOD_SIZE;
}

void renderFood(void)
{
    if (!foodState)
    {
        generateFood();
        foodState = 1;
    }
    // set the color for the food
    if (SDL_SetRenderDrawColor(renderer, foodColor.r, foodColor.g, foodColor.b, foodColor.a) != 0)
        exitWithError(__FILE__, __LINE__);

    if (SDL_RenderFillRect(renderer, &food) != 0)
        exitWithError(__FILE__, __LINE__);
}