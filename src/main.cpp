// Using custom SDL and standard IO
// #include <SDL.h>
#include "/usr/include/SDL2/SDL.h"
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_video.h>
#include <stdio.h>

// Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char* args[]) {
    // The window we'll be rendering to
    SDL_Window* window = NULL;

    // The surface contained by the window
    SDL_Surface* screen_surface = NULL;

    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf(
            "SDL could not initialize!\nSDL_Error: %s\n",
            SDL_GetError()
        );
    } else {
        // Create window
        window = SDL_CreateWindow(
            "SDL Tutorial",
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            SCREEN_WIDTH,
            SCREEN_HEIGHT,
            SDL_WINDOW_SHOWN
        );
        if (window == NULL) {
            printf(
                "Window could not be created!\nSDL_Error: %s\n",
                SDL_GetError()
            );
        } else {
            // Get window surface
            screen_surface = SDL_GetWindowSurface(window);

            // Fill the surface white
            SDL_FillRect(
                screen_surface,
                NULL,
                SDL_MapRGB(
                    screen_surface->format,
                    0xff,
                    0xff,
                    0xff
                )
            );

            // Update the surface
            SDL_UpdateWindowSurface(window);

            // Hack to get the window to stay up
            SDL_Event e;
            bool quit = false;
            while (quit == false) {
                while (SDL_PollEvent(&e)) {
                    if (e.type == SDL_QUIT) {
                        quit = true;
                    }
                }
            } 
        }
    }

    // Destroy the window
    SDL_DestroyWindow(window);

    // Quit SDL subsystems
    SDL_Quit();

    return 0;
}