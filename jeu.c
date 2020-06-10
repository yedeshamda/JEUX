/**
 * @file jeu.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "player.h"
#include "background.h"
#include "jeu.h"

int jouer(SDL_Surface * screen)
{
	int done = 0;
	Player hero1, hero2;
	Background Backg;
	SDL_Event event;
	int keysHeld[323] = {0}; 
	long ret;
	Uint32 t_prev,dt=1;

	if(loadPlayerImages(&hero1) == -1)
        {
		printf("Erreur Chargement Player Images\n");
		return(-1);

	}

if(loadPlayerImages(&hero2) == -1)
        {
		printf("Erreur Chargement Player Images\n");
		return(-1);

	}
	if(loadBackground(&Backg) == -1)
        {
		printf("Erreur Chargement Background Images\n");
		return(-1);
	}
//Initialisation
	initBackground(&Backg);
	initPlayer(&hero1);
    initPlayer(&hero2);
    hero2.position.x=2500 /2 +1;
	hero2.position.y=350;
// Game loop
	SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY,SDL_DEFAULT_REPEAT_INTERVAL);
	while(!done) {
		t_prev = SDL_GetTicks();
//Display
blitBackground(&Backg,screen);
SDL_BlitSurface(hero1.image,NULL,screen,&hero1.position);
SDL_BlitSurface(hero2.image,NULL,screen,&hero2.position);
SDL_Flip(screen);
		
//Input
		while (SDL_PollEvent(&event)) 
                        {
			
			switch (event.type) {
			case SDL_QUIT:
				done = 1;
				break;
			case SDL_KEYDOWN:
				keysHeld[event.key.keysym.sym] = 1;
				break;
			case SDL_KEYUP:
				keysHeld[event.key.keysym.sym] = 0;
				break;

			default:
				;
			}


		} 
//Update

if ((keysHeld[SDLK_RIGHT])&& hero1.position.x<2500/2 - hero1.position.w) 
movePlayer(&hero1);
if ((keysHeld[SDLK_LEFT])&& hero2.position.x<2500- hero2.position.w) 
movePlayer(&hero2);
		if (keysHeld[SDLK_ESCAPE]) 
		done = 1;
		if(keysHeld[SDLK_RETURN] ) 
		hero1.jouer=1;      
	}  
// free loaded images
	freePlayer(&hero1);
	freePlayer(&hero2);
	freeBackground(&Backg);
	return(0);
}

