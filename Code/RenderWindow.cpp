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
void RenderWindow::CleanUp()
{
    SDL_DestroyWindow(window);
}
