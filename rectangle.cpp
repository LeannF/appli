#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include "window.hpp"
#include "text.hpp"
#include "rectangle.hpp"

Rectangle::Rectangle()
{
}

Rectangle::~Rectangle()
{
}

void Rectangle::create(SDL_Renderer* renderer)
{
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255 );
    SDL_Rect rect;
    rect = {400, 600, 200, 200 };
    SDL_RenderFillRect(renderer, &rect);
    SDL_RenderDrawRect(renderer, &rect); // Dessine la tête du serpent
}