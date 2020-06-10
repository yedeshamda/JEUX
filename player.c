/**
 * @file player.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "player.h"
#include "background.h"

/**
 * @brief Loader l'héro
 * @param A l'héro
 * @return rien
 */
int loadPlayerImages(Player *A)
{
		A->image = IMG_Load("pers.png");
		if (A->image== NULL) {
			printf("Unable to load :\n", SDL_GetError());
			return (-1);
		}
		SDL_SetColorKey( A->image, SDL_SRCCOLORKEY, SDL_MapRGB(A->image->format, 255, 255, 255) );
	
	return(0);
}

/**
 * @brief Initialiser l'héro 
 * @param A l'héro 
 * @return rien
 */
void initPlayer(Player *A)
{
	A->position.x=0;
	A->position.y=350;
	A->position.w=162;
	A->position.h=A->image->h;
	A->jouer=0;
        
}

/**
 * @brief Déplacer l'héro 
 * @param A l'héro
 * @return rien
 */
void movePlayer(Player *A)
{
A->position.x++;
}

/**
 * @brief Libérer l'héro
 * @param A l'héro
 * @return rien
 */
void freePlayer(Player *A)
{
		SDL_FreeSurface(A->image);
}
