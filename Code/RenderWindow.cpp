#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>
#include "Entity.hpp"
#include "RenderWindow.hpp"

using namespace std;

RenderWindow::RenderWindow(const char* title, int width, int height)
    :window(NULL), renderer(NULL)
{
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

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
void RenderWindow::Render(Entity& entity)
{
    SDL_Rect src;
    src.x = entity.getCurrentFrame().x;
    src.y = entity.getCurrentFrame().y;
    src.w = entity.getCurrentFrame().w;
    src.h = entity.getCurrentFrame().h;

    SDL_Rect dst;
    dst.x = entity.getPos().x * 4;
    dst.y = entity.getPos().y * 4;
    dst.w = entity.getCurrentFrame().w * 4;
    dst.h = entity.getCurrentFrame().h * 4;
    SDL_RenderCopy(renderer,entity.getTex(),&src,&dst);
}
void RenderWindow::Display()
{
    SDL_RenderPresent(renderer);
}
void RenderWindow::CleanUp()
{
    SDL_DestroyWindow(window);
}

