#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include "window.hpp"
#include "text.hpp"
#include "image.hpp"
#include "rectangle.hpp"
  
int main(void) 
{

    MainWindow window;
    Rectangle *rectangle;
    Rectangle *rectangle2;

    Uint32 frame_rate, frame_time, frame_delay = 20;
    window.init("Appli", 1920, 1080); // Creation de la fenetre 
    Text text(window.getRenderer(), "./font/Roboto/Roboto-Black.ttf", 30, "Timer", {255, 255, 255, 255});

    Image image(window.getRenderer(), 120, 120, 100, 100, "./img/biberon.jpg");

    while(window.running() == true )
    {
       
        frame_rate = SDL_GetTicks();
        SDL_SetRenderDrawColor(window.getRenderer(), 46, 64, 83, 255); // Donne la couleur du render
        SDL_RenderClear(window.getRenderer());
        text.display(20, 20, window.getRenderer());

        rectangle->create(window.getRenderer());
        image.show(window.getRenderer());
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

