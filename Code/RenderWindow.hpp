#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class RenderWindow
{
public:
    RenderWindow(const char* title, int width, int height);
    SDL_Texture* loadTexture(const char* file_path);
    void CleanUp();
    void Clear();
    void Render(SDL_Texture* tex);
    void Display();
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
};
