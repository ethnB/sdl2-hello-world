#include <SDL2/SDL.h>

const int WIDTH = 640;
const int HEIGHT = 480;

int main(int argc, char* args[] )
{
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *window = SDL_CreateWindow(
        "Hello World",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        WIDTH,
        HEIGHT,
        SDL_WINDOW_SHOWN);

    // NULL window would indicate an error

    SDL_Surface *surface = SDL_GetWindowSurface(window);

    SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 0xFF, 0xFF, 0xFF));

    SDL_UpdateWindowSurface(window);

    // poll for events and allow the user to quit
    SDL_Event e;
    bool quit = false;
    while (quit == false)
    {
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
                quit = true;
        }
    }

    // free the memory held by the window
    // + the surface
    SDL_DestroyWindow(window);

    SDL_Quit();

    return 0;
}