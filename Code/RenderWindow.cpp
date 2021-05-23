#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>

#include "RenderWindow.hpp"

using namespace std;

RenderWindow::RenderWindow(const char* title, int width, int height)
    :window(NULL), renderer(NULL)
{
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if(window == NULL)
    {
        cout << "Window failed to init. Error: " << SDL_GetError() << endl;
    }

}
SDL_Texture* RenderWindow::loadTexture(const char* file_path)
{
    SDL_Texture* texture = NULL;
    texture = IMG_LoadTexture(renderer, file_path);

    if(texture == NULL)
    {
        cout << "Failed to load texture. Error:" << SDL_GetError() << endl;
    }
    return texture;
}
void RenderWindow::Clear()
{
    SDL_RenderClear(renderer);
}
void RenderWindow::Render(SDL_Texture* tex)
{
    SDL_RenderCopy(renderer,tex,NULL,NULL);
}
void RenderWindow::Display()
{
    SDL_RenderPresent(renderer);
}
void RenderWindow::CleanUp()
{
    SDL_DestroyWindow(window);
}

