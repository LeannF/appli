#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include "window.hpp"
#include "text.hpp"

  
int main(void) 
{
    TTF_Init();
    TTF_Font* font;
    MainWindow window;
    SDL_Surface* texte;
    Text *word;
    Uint32 frame_rate, frame_time, frame_delay = 20;
    window.init("Appli", 1920, 1080); // Creation de la fenetre 
    
    Text text(window.getRenderer(), "./Roboto-Black.ttf", 30, "Test", {255, 255, 255, 255});

    while(window.running() == true )
    {
       
        frame_rate = SDL_GetTicks();
        SDL_SetRenderDrawColor(window.getRenderer(), 46, 64, 83, 255); // Donne la couleur du render
        SDL_RenderClear(window.getRenderer());
        text.display(20, 20, window.getRenderer());

        word->post();

        SDL_RenderPresent(window.getRenderer());


        SDL_Event event;
        if(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT ){
                
                window.clean();
                break;
            }
        }
        frame_time = SDL_GetTicks() - frame_rate;
        if(frame_time < frame_delay){
            SDL_Delay( frame_delay - frame_time );
        }
    }
    
    return 0;
}

