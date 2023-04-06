#include "utils.h"

void exitWithError(char *file, int line)
{
    SDL_Log("Error in file %s at line %d : %s", file, line, SDL_GetError());
}
