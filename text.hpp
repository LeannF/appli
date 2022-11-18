#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <cstdio>
#pragma once



class Text
{
private:
    SDL_Texture *MyTexture = nullptr;
    SDL_Texture *MyTexture2 = nullptr;
    SDL_Rect text_rect;
    SDL_Renderer *renderer;


public:
    Text(SDL_Renderer *renderer,const std::string &font_path, int font_size, const std::string &message, const SDL_Color Color);
    ~Text();
    void MouseKeyEvent(SDL_Event event, std::string inputText, const Uint8* keystates);
    void display(SDL_Renderer *renderer);

    SDL_Texture *loadFont(SDL_Renderer *renderer, const std::string &font_path, int font_size, const std::string &message, const SDL_Color Color);
};

