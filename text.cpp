#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <cstdio>

#include "window.hpp"
#include "text.hpp"
#include "image.hpp"

const Uint8 *keystates = SDL_GetKeyboardState(NULL);


TTF_Font *font;
MainWindow window;
SDL_Texture *texture;
Text *text;

Text::Text(SDL_Renderer *renderer, const std::string &font_path, int font_size, const std::string &message, const SDL_Color Color)
{
    MyTexture = loadFont(renderer, font_path, font_size,  message, Color);
    SDL_QueryTexture(MyTexture, nullptr, nullptr, &text_rect.w, &text_rect.h);

    MyTexture2 = loadFont(renderer, font_path, font_size,  message, Color);
    SDL_QueryTexture(MyTexture2, nullptr, nullptr, &text_rect.w, &text_rect.h);
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

void Text::display(SDL_Renderer *renderer)
{


    SDL_Rect dstrect = {100, 400, 100, 100};


    SDL_RenderCopy(renderer, MyTexture, nullptr, &dstrect);

}

/*void MouseKeyEvent(SDL_Event event, std::string inputText, const Uint8* keystates) {

    //if (keystates[SDL_SCANCODE_A]) cout << "A" << endl;
    if (SDL_MOUSEMOTION == event.type) 
    {

        int x, y;
        SDL_GetMouseState(&x, &y);

        std::cout << x << " : " << y << std::endl;
        
    }


    if (SDL_MOUSEBUTTONDOWN == event.type) {
        if (SDL_BUTTON_LEFT == event.button.button) {
            std::cout << "Left mouse button is down" << std::endl;
        }
    }
    if (keystates[SDL_SCANCODE_BACKSPACE] && inputText.length() > 0) {
        inputText.pop_back();
    }
    else if (keystates[SDL_SCANCODE_C] && SDL_GetModState() && KMOD_CTRL) {
        SDL_SetClipboardText(inputText.c_str());
    }
    else if (keystates[SDL_SCANCODE_V] && SDL_GetModState() && KMOD_CTRL) {
        inputText = SDL_GetClipboardText();
    }
    else if (event.type == SDL_TEXTINPUT) {
        inputText += event.text.text;        
        
    }
    if (inputText.length() > 0) {
        std::cout << inputText;
        std::cout.flush();
        
    }

    
    /*if (SDL_MOUSEBUTTONDOWN == event.type) {
        (loopinput = true)
    }

       
}*/
