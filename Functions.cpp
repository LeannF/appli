#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include "window.hpp"
#include "text.hpp"



using namespace std;

void MouseKeyEvent(SDL_Event event, std::string inputText, const Uint8* keystates) {

    if (SDL_MOUSEMOTION == event.type) {

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
    if (inputText.length() > 0) std::cout << inputText;
    std::cout.flush();
    
    /*if (SDL_MOUSEBUTTONDOWN == event.type) {
        (loopinput = true)
    }*/      
}