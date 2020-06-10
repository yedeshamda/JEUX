/**
 * @file main.c
 * @brief Tester le programme 
 * @author Legendary Group
 * @version 1
 * @date 26 mai 2020
*/

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "background.h"

int main(int argc, char **argv)
{
  SDL_Surface *screen;
  background b;
  hero h;
  int done = 1;
  SDL_Event event;
 
  if (SDL_Init(SDL_INIT_VIDEO) != 0)
  {
    printf("unable to initialize SDL : %s\n", SDL_GetError());
    return 1;
  }
  screen = SDL_SetVideoMode(800,630, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
  SDL_WM_SetCaption("*WELCOME TO OUR GAME*", NULL);
  if (screen == NULL)
  {
    printf("Unable to set video mode: %s\n", SDL_GetError());
  }
initialiser_background(&b);
initialiser_hero(&h);
  while (done)
  {
     afficher_background(&b,screen);
     afficher_hero(&h,screen);
 
    SDL_PollEvent(&event);
      
      if (event.type==SDL_QUIT)
      {
        done=0;
      }
      
     else if(event.type== SDL_KEYDOWN)
      {
        if (event.key.keysym.sym==SDLK_ESCAPE)
        {
          done=0;
        }
      }
     deplacer_hero(&h,event,&b);
    }

  free_background(&b);
  free_hero(&h);
  SDL_Quit();

  return EXIT_SUCCESS; // return 0;
}
