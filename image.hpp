#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <cstdio>
#pragma once



class Image
{
private:
    SDL_Renderer* renderer;
    SDL_Rect img_rect;
    SDL_Texture* myTexture = nullptr;
    int _w, _h;
    int _x, _y;

public:
    Image(SDL_Renderer *renderer, int w, int h, int x, int y, const std::string &image_path);
    ~Image();
    void show(SDL_Renderer *renderer);
};

