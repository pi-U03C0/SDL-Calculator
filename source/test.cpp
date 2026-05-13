
#ifdef TEST

#include <SDL3/SDL.h>
#include <stdlib.h>
#include <stdio.h>

void write_to_file(Uint32* pixels)
{
  FILE* image_file = fopen("coolimage.raw", "wb");
  fwrite(pixels,sizeof(Uint32), 100*100,image_file);

  fclose(image_file);
}

void read_raw_file(Uint32* pixels)
{
  FILE* image_file = fopen("coolimage.raw", "rb");
  fread(pixels, sizeof(Uint32), 100*100, image_file);
  fclose(image_file);
}

int main()
{
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* window = SDL_CreateWindow( "Raw RGBA", 800, 600, 0);
 
    SDL_Renderer* renderer = SDL_CreateRenderer( window, NULL);

    // 2x2 RGBA image
    Uint32* pixels = (Uint32*)malloc( 100 * 100 * sizeof(Uint32));
    read_raw_file(pixels);

    SDL_Surface* surface = SDL_CreateSurfaceFrom( 100, 100, SDL_PIXELFORMAT_ARGB8888, pixels, 100 * sizeof(Uint32));

    SDL_Texture* texture = SDL_CreateTextureFromSurface( renderer, surface);

    SDL_DestroySurface(surface);

    SDL_FRect rect = { 10, 10, 100, 100 };

    bool running = true;
    SDL_Event event;

    while (running)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_EVENT_QUIT)
            {
                running = false;
            }
        }

        SDL_SetRenderDrawColor( renderer, 0,0,0,255);

        SDL_RenderClear(renderer);

        // Draw raw RGBA pixels
        SDL_RenderTexture( renderer, texture, NULL, &rect);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();
}
#endif // !TEST
