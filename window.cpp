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

SDL_Surface *myImg;
SDL_Surface* image;
SDL_Texture* myTexture;


MainWindow::MainWindow()
{
  this->window = NULL;
  this->renderer = NULL;
  this->img == NULL;
  this->isRunning = true;

}

  // FONCTION INITIALISATION DE FENETRE + VERIF ERREURS

int MainWindow::init(const char* title,int width, int height)
{
  if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
  {
    std::cout << "SDL_INIT ERROR" << std::endl;
    return EXIT_FAILURE;
  }
  
  this->window = SDL_CreateWindow("Appli",SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1080, 720, SDL_WINDOW_RESIZABLE);
  if(this->window == NULL) { 
    std::cout << "WINDOW ERROR" << std::endl;
    return EXIT_FAILURE;
  }

  this->renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED );
  if(this->renderer == NULL) {
    std::cout << "RENDERER ERROR" << std::endl;
    return EXIT_FAILURE;
  }

  if(TTF_Init() == -1)
  {
    std::cout << "FONT ERROR" << std::endl;
    return EXIT_FAILURE;
  }


  if(IMG_Init(IMG_INIT_JPG != IMG_INIT_JPG) )
  {
    std::cout << "IMAGE ERROR" << std::endl;
    return EXIT_FAILURE;
  }


  isRunning = true;
  return 0;
}

MainWindow::~MainWindow()
{
  SDL_DestroyWindow(this->window);
  SDL_DestroyRenderer(this->renderer);
  TTF_CloseFont;
  TTF_Quit();
  IMG_Quit();
  SDL_Quit();  
}


  // FONCTION GESTION DES EVENTS

void MainWindow::handleEvents(){
  SDL_Event event;
  SDL_PollEvent(&event);
  if(event.type == SDL_QUIT) {
    isRunning = false;
    SDL_Quit();
  }
}

  // FONCTION DESTRUCTION DE FENETRE, RENDER

void MainWindow::clean() {
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  TTF_Quit();
  IMG_Quit();
  SDL_Quit();
}