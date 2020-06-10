/**
 * @file background.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "background.h"

/**
 * @brief Loader background 
 * @param Backg background
 * @return rien
 */
int loadBackground(Background *Backg)
{
	// load background
	Backg->backgroundImg =IMG_Load("forest.png");
	if (Backg->backgroundImg == NULL) {
		printf("Unable to load : %s\n", SDL_GetError());
		return (-1);
	}
	Backg->backgroundCollide = IMG_Load("forest.png");
	if (Backg->backgroundCollide == NULL) {
		printf("Unable to load : %s\n", SDL_GetError());
		return (-1);
	}

	return (0);
}

/**
 * @brief Initialiser background 
 * @param Backg background
 * @return rien
 */
void initBackground(Background *Backg)
{
	Backg->backgroundPos.x=0;
	Backg->backgroundPos.y=0;
	Backg->backgroundPos.w=(2500/2);
	Backg->backgroundPos.h=630;

        Backg->backgroundPos2.x=(2500/2)+2;
	Backg->backgroundPos2.y=0;
	Backg->backgroundPos2.w=(2500/2);
	Backg->backgroundPos2.h=630;
}

/**
 * @brief Faire le scrolling
 * @param Backg background
 * @param numBack numéro du background
 * @return rien
 */
void scrolling (Background *Backg, int numBack)
{
if (numBack==1)
Backg->backgroundPos.x++;
else
Backg->backgroundPos2.x++;
	
}
/**
 * @brief Afficher background 
 * @param Backg background
 * @param screen la surface
 * @return rien
 */
void blitBackground(Background *Backg,SDL_Surface *screen)
{
	//Blit the bachground to the backbuffer
	SDL_BlitSurface(Backg->backgroundImg, &(Backg->backgroundPos), screen,NULL); 
    SDL_BlitSurface(Backg->backgroundImg, NULL, screen,&(Backg->backgroundPos2));
}

/**
 * @brief Libérer background 
 * @param Backg background
 * @return rien
 */
void freeBackground(Background *Backg)
{
	SDL_FreeSurface(Backg->backgroundImg);
	SDL_FreeSurface(Backg->backgroundCollide);
}
