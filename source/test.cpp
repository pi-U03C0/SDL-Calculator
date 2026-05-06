
#ifdef TEST

#include <SDL3/SDL.h>
#include <SDL3/SDL3_ttf/SDL_ttf.h>
#include <stdio.h>

int main()
{
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();

    SDL_Window* window = SDL_CreateWindow( "SDL3 Text", 800, 600, 0);

    SDL_Renderer* renderer = SDL_CreateRenderer( window, NULL);

    // Load font
    TTF_Font* font = TTF_OpenFont( "C:/Windows/Fonts/arial.ttf", 48);

    if (!font)
    {
        printf("%s\n", SDL_GetError());
        return 1;
    }

    // Create text surface
    SDL_Surface* surface = TTF_RenderText_Blended( font, "Hello SDL3", 0, (SDL_Color){5,255,255,255});

    // Convert surface to texture
    SDL_Texture* texture = SDL_CreateTextureFromSurface( renderer, surface);

    SDL_FRect rect = { 100, 100, (float)surface->w, (float)surface->h };

    SDL_DestroySurface(surface);

    bool running = true;
    SDL_Event event;

    while (running)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_EVENT_QUIT) running = false;
        }

        SDL_SetRenderDrawColor( renderer, 0,0,0,255);

        SDL_RenderClear(renderer);

        // Draw text
        SDL_RenderTexture( renderer, texture, NULL, &rect);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyTexture(texture);
    TTF_CloseFont(font);

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    TTF_Quit();
    SDL_Quit();
}

#endif // !TEST
