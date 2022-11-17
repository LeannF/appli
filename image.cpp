#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include "window.hpp"
#include "text.hpp"
#include "image.hpp"



Image::Image(SDL_Renderer *renderer, int w, int h, int x, int y, const std::string &image_path)
{

    auto surface = IMG_Load(image_path.c_str());
    if(!surface)
    {
        std::cerr << "failed to load surface";
    }

    myTexture = SDL_CreateTextureFromSurface(renderer, surface);
        if(!myTexture)
    {
        std::cerr << "failed to load texture";
    }

    SDL_QueryTexture(myTexture, NULL, NULL, &img_rect.w, &img_rect.h);


}

Image::~Image()
{
    SDL_DestroyTexture(myTexture);
}

void Image::show(SDL_Renderer *renderer)
{
    SDL_Rect rect = {_w, _h, _x, _y};
    SDL_Rect dstrect = {100, 200, 200, 200};

    if(myTexture){
    SDL_RenderCopy(renderer, myTexture, nullptr, &dstrect);
    }
}