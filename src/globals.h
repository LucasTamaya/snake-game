#ifndef GLOBALS_H_
#define GLOBALS_H_

#include <SDL.h>

extern SDL_Window *window;
extern SDL_Renderer *renderer;
extern SDL_Color color;
extern SDL_Color foodColor;
extern SDL_Rect snake;
extern SDL_Rect food;
extern int foodState;

#endif