#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <stdbool.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define MAX_LINE_COUNT 100

typedef struct {
    int x1, y1;  // elsõ végpont x és y koordinátái
    int x2, y2;  // második végpont x és y koordinátái
    SDL_Color color;
} Line;



Line lines[MAX_LINE_COUNT];
int line_count = 0;

void draw_line(SDL_Renderer *renderer, Line line) {
    SDL_SetRenderDrawColor(renderer, line.color.r, line.color.g, line.color.b, 255);
    SDL_RenderDrawLine(renderer, line.x1, line.y1, line.x2, line.y2);
}

int main(int argc, char** argv)
{
    SDL_Window * window;
    SDL_Renderer * renderer;
    SDL_Event event;
    bool running = true;
    int start_x = -1, start_y = -1;

    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("Line Drawer", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
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
                    Line line = {
                        .x1 = start_x,
                        .y1 = start_y,
                        .x2 = event.button.x,
                        .y2 = event.button.y,
                        .color = {
                            .r = rand () % 256,
                            .g = rand () % 256,
                            .b = rand () % 256,
                        }
                    };
                    lines[line_count++] = line;
                    if (line_count >= MAX_LINE_COUNT) {
                        running = false;
                    }
                    start_x = -1;
                    start_y = -1;
                }
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // fekete háttér
        SDL_RenderClear(renderer);

        for (int i = 0; i < line_count; i++) {
            draw_line(renderer, lines[i]);
        }

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
