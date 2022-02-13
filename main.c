#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "SDL.h"
#include "linalg.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

int scc(int code)
{
    if (code < 0)
    {
        fprintf(stderr, "SDL ERROR: %s\n", SDL_GetError());
        exit(1);
    }
    return code;
}

void *scp(void *ptr)
{
    if (ptr == NULL)
    {
        fprintf(stderr, "SDL ERROR: %s\n", SDL_GetError());
        exit(1);
    }

    return ptr;
}

void triangle(SDL_Renderer * renderer, Vec2 p1, Vec2 p2, Vec2 p3, int limit)
{
    if (limit <= 0) {
        SDL_RenderDrawLine(renderer, p1.x, p1.y, p2.x, p2.y);
        SDL_RenderDrawLine(renderer, p2.x, p2.y, p3.x, p3.y);
        SDL_RenderDrawLine(renderer, p3.x, p3.y, p1.x, p1.y);
    }
    else {
        Vec2 new_p1 = vec2_div(vec2_add(p1, p2), vec2s(2));
        Vec2 new_p2 = vec2_div(vec2_add(p2, p3), vec2s(2));
        Vec2 new_p3 = vec2_div(vec2_add(p3, p1), vec2s(2));

        triangle(renderer, new_p1, new_p3, p1, limit - 1);
        triangle(renderer, new_p2, new_p1, p2, limit - 1);
        triangle(renderer, new_p3, new_p2, p3, limit - 1);
    }
}

void render_fractal(SDL_Renderer * renderer)
{
    Vec2 middle_screen = vec2(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
    Vec2 p1 = vec2(middle_screen.x, middle_screen.y - 300);
    Vec2 p2 = vec2(middle_screen.x + 278, middle_screen.y + 160);
    Vec2 p3 = vec2(middle_screen.x - 278, middle_screen.y + 160);
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    triangle(renderer, p1, p2, p3, 5);
}

int main(void)
{
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *window = scp(SDL_CreateWindow("Fractal", 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL));
    SDL_Renderer *renderer = scp(SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC));

    SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);

    bool quit = false;

    while (!quit)
    {
        SDL_Event event = {0};

        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
            {
                quit = true;
            }
            break;
            }
        }

        SDL_SetRenderDrawColor(renderer, 30, 30, 30, 0);
        SDL_RenderClear(renderer);
        render_fractal(renderer);
        SDL_RenderPresent(renderer);
    }

    SDL_Quit();

    return 0;
}