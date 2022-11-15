#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <cstdio>

#include "window.hpp"
#include "text.hpp"



TTF_Font *font;
MainWindow window;
SDL_Texture *texture;


Text::Text(SDL_Renderer *renderer, const std::string &font_path, int font_size, const std::string &message, const SDL_Color Color)
{
    MyTexture = loadFont(renderer, font_path, font_size,  message, Color);
    SDL_QueryTexture(MyTexture, nullptr, nullptr, &text_rect.w, &text_rect.h);
}

Text::~Text()
{
}

SDL_Texture *Text::loadFont(SDL_Renderer *renderer, const std::string &font_path, int font_size, const std::string &message, const SDL_Color Color)
{
    font = TTF_OpenFont(font_path.c_str(),font_size);
    if(!font)
    {
        std::cout << "failed to load font" << std::endl;

    }

    auto text_surface = TTF_RenderText_Solid(font, message.c_str(), Color);
    if(!text_surface)
    {
        std::cout << "failed to create text surface" << std::endl;

    }
    
    auto text_texture = SDL_CreateTextureFromSurface(renderer, text_surface );
    if(!text_texture)
    {
        std::cout << "failed to create text texture" << std::endl;

    }
    SDL_FreeSurface(text_surface );
    return text_texture;
}

void Text::display(int x, int y, SDL_Renderer *renderer)
{
    text_rect.x =x;
    text_rect.y =y;
  
    SDL_RenderCopy(renderer, MyTexture, nullptr, &text_rect);
}

int Text::getX()
{
    return xp;
}

int Text::getY()
{
    return yp;
}

void Text::post()
{
    SDL_Event event;
    if(SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_MOUSEMOTION:
            std::cout << event.motion.x << "," << event.motion.y;
            break;

            /*case SDL_MOUSEBUTTONDOWN:
            display( );  
            break;*/
        }
    }
    
}