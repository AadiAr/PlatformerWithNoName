#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Entity.hpp"
class RenderWindow
{
public:
    RenderWindow(const char* title, int width, int height);
    SDL_Texture* loadTexture(const char* file_path);
    void CleanUp();
    void Clear();
    void Render(Entity& entity);
    void Display();
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
};
