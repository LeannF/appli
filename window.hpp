#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <cstdio>
#pragma once

#include "text.hpp"

class MainWindow{
    public:
        MainWindow();
        ~MainWindow();
        int init(const char* title, int width, int height);
        void handleEvents();
        void clean();
        SDL_Renderer* getRenderer(){
            return renderer;
        };

        bool running(){
            return isRunning;
        }

    private:
        bool isRunning;
        SDL_Window* window;
        SDL_Renderer* renderer;
        
};