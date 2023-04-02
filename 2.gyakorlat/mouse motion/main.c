#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>



typedef struct {
    int red;    // a v�r�s RGB komponens
    int green;  // a z�ld RGB komponens
    int blue;   // a k�k RGB komponens
} Color;

typedef struct {
    int x1, y1;  // els� v�gpont x �s y koordin�t�i
    int x2, y2;  // m�sodik v�gpont x �s y koordin�t�i
    Color color; // a sz�n a Color strukt�ra seg�ts�g�vel van defini�lva
} Line;



int main(int argc, char** argv)
{
    // SDL inicializ�l�sa
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("Mouse motion handling",
                                          SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED,
                                          640, 480,
                                          SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

    // Esem�nykezel� ciklus
    SDL_Event event;
    while (1) {
        // Esem�nyek kezel�se
        while (SDL_PollEvent(&event)) {
            // Kil�p�s az esem�nykezel� ciklusb�l
            if (event.type == SDL_QUIT) {
                goto quit;
            }
            // Eg�r mozg�s esem�ny kezel�se
            if (event.type == SDL_MOUSEMOTION) {
                printf("Mouse position: x=%d, y=%d\n", event.motion.x, event.motion.y);
            }
        }
    }

quit:
    // SDL felszabad�t�sa
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
