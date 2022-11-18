#include "text.hpp"
#include "Functions.hpp"



void MouseKeyEvent(SDL_Event event, string inputText, const Uint8* keystates) {

    if (SDL_MOUSEMOTION == event.type) {

        int x, y;
        SDL_GetMouseState(&x, &y);

        cout << x << " : " << y << endl;

    }


    if (SDL_MOUSEBUTTONDOWN == event.type) {
        if (SDL_BUTTON_LEFT == event.button.button) {
            cout << "Left mouse button is down" << endl;
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
    if (inputText.length() > 0) cout << inputText;
    cout.flush();
    
    /*if (SDL_MOUSEBUTTONDOWN == event.type) {
        (loopinput = true)
    }*/

       
}

