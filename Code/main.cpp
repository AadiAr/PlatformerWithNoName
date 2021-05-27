#include <iostream>
#include <vector>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "RenderWindow.hpp"
#include "Entity.hpp"
#include "Utils.hpp"

using namespace std;

int main(int argc, char* argv[])
{
    if(SDL_Init(SDL_INIT_VIDEO) > 0)
    {
        cout << "SDL_Init HAS FAILED. SDL ERROR: " << SDL_GetError() << endl;
    }
    if(!(IMG_Init(IMG_INIT_PNG)))
    {
            cout << "IMG_Init has failed. Error: " << SDL_GetError() << endl;
    }

    RenderWindow window("INSERT GOOD NAME HERE", 1280, 720);

    SDL_Texture* grassTexture = window.loadTexture("assets/sprites/grass.png");

    Entity platform0(Vector2f (150, 75), grassTexture);
    Entity platform1(Vector2f(100,50),grassTexture);
    Entity platform2(Vector2f(50, 25), grassTexture);

    vector<Entity> entities = {platform0,platform1,platform2};

    bool gameRunning = true;

    SDL_Event event;

    const float deltaTime = 0.01f;
    float accumulator = 0.0f;
    float currentTime = utils::hireTimeInSeconds();

    while(gameRunning)
    {
        float newTime = utils::hireTimeInSeconds();
        float frameTime = newTime - currentTime;

        currentTime = newTime;

        accumulator += frameTime;

        while(accumulator >= deltaTime)
        {
            while(SDL_PollEvent(&event))
            {
                if(event.type == SDL_QUIT)
                {
                    gameRunning = false;
                }
            }

            accumulator -= deltaTime;
        }

        const float alpha = accumulator/deltaTime;

        window.Clear();
        for(Entity& e : entities)
        {
            window.Render(e);
        }

        window.Display();
    }

    window.CleanUp();
    SDL_Quit();

    return 0;
}
