#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>



typedef struct {
    int red;    // a vörös RGB komponens
    int green;  // a zöld RGB komponens
    int blue;   // a kék RGB komponens
} Color;

typedef struct {
    int x1, y1;  // elsõ végpont x és y koordinátái
    int x2, y2;  // második végpont x és y koordinátái
    Color color; // a szín a Color struktúra segítségével van definiálva
} Line;



int main(int argc, char** argv)
{
    // SDL inicializálása
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("Mouse motion handling",
                                          SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED,
                                          640, 480,
                                          SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

    // Eseménykezelõ ciklus
    SDL_Event event;
    while (1) {
        // Események kezelése
        while (SDL_PollEvent(&event)) {
            // Kilépés az eseménykezelõ ciklusból
            if (event.type == SDL_QUIT) {
                goto quit;
            }
            // Egér mozgás esemény kezelése
            if (event.type == SDL_MOUSEMOTION) {
                printf("Mouse position: x=%d, y=%d\n", event.motion.x, event.motion.y);
            }
        }
    }

quit:
    // SDL felszabadítása
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
