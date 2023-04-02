#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <stdbool.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define MAX_RECT_COUNT 100

typedef struct rect{
    int x, y;  // bal felsõ sarok x és y koordinátái
    int width, height; // szélesség és magasság
    SDL_Color color;
} Rect;

Rect rects[MAX_RECT_COUNT];
int rect_count = 0;

void draw_rect(SDL_Renderer *renderer, Rect rect) {
    SDL_SetRenderDrawColor(renderer, rect.color.r, rect.color.g, rect.color.b, 255);
    SDL_Rect r = {rect.x, rect.y, rect.width, rect.height};
    SDL_RenderFillRect(renderer, &r);
}

int main(int argc, char** argv)
{
    SDL_Window * window;
    SDL_Renderer * renderer;
    SDL_Event event;
    bool running = true;
    int start_x = -1, start_y = -1;

    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("Rectangle Drawer", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
    SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
                break;
            }
            if (event.type == SDL_MOUSEBUTTONDOWN) {
                if (event.button.button == SDL_BUTTON_LEFT) {
                    start_x = event.button.x;
                    start_y = event.button.y;
                }
            }
            if (event.type == SDL_MOUSEBUTTONUP) {
                if (event.button.button == SDL_BUTTON_LEFT && start_x != -1 && start_y != -1) {
                    Rect rect = {
                        .x = start_x,
                        .y = start_y,
                        .width = event.button.x - start_x,
                        .height = event.button.y - start_y,
                        .color = {
                            .r = rand () % 256,
                            .g = rand () % 256,
                            .b = rand () % 256,
                        }
                    };
                    rects[rect_count++] = rect;
                    if (rect_count >= MAX_RECT_COUNT) {
                        running = false;
                    }
                    start_x = -1;
                    start_y = -1;
                }
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // black background
        SDL_RenderClear(renderer);

        for (int i = 0; i < rect_count; i++) {
            draw_rect(renderer, rects[i]);
        }

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
