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
 * @brief Initialiser background 
 * @param b background
 * @return rien
 */
void initialiser_background(background *b)
{
	b->background = IMG_Load("forest.png");
	b->background_mask = IMG_Load("mask1.png");
	b->position_background.x = 0;
	b->position_background.y = 0;
	b->position_background_mask.x = 0;
	b->position_background_mask.y = 0;
	b->position_Camera.x = 0; 
	b->position_Camera.y = 0; 
	b->position_Camera.w = b->background->w;
	b->position_Camera.h = b->background->h;
}

/**
 * @brief Afficher background 
 * @param b background
 * @param screen la surface
 * @return rien
 */
void afficher_background(background *b, SDL_Surface *screen)
{
 // SDL_BlitSurface(b->background_mask, &b->positon_Camera, screen, &b->position_hero_background_mask); 
	SDL_BlitSurface(b->background, &b->position_Camera, screen, &b->position_background);		
	SDL_Flip(screen);		  
}

/**
 * @brief Faire le scrolling
 * @param b background
 * @param event l'évenement a faire
 * @return rien
 */
void scrolling(background *b, SDL_Event event)
{
	switch (event.key.keysym.sym)
	{
	case SDLK_LEFT:
	{
		b->position_Camera.x -= 4;
		if (b->position_Camera.x <= 0)
			b->position_Camera.x = 0;
		break;
	}
	case SDLK_RIGHT:
	{
		b->position_Camera.x += 4;
		if (b->position_Camera.x + 800 >= b->background->w )
			b->position_Camera.x = b->background->w - 800;
		break;
	}
	}
}

/**
 * @brief Libérer background 
 * @param b background
 * @return rien
 */
void free_background(background *b)
{
	SDL_FreeSurface(b->background);
	SDL_FreeSurface(b->background_mask);
}

/**
 * @brief Envoyer la couleur d'un pixel dont les cordonnées (x,y) sur une surface
 * @param psurface la surface
 * @param x un point situé à l'héro suivant l'axe des abscisses
 * @param y un point situé à l'héro suivant l'axe des ordonnées
 * @return color 
 */
SDL_Color GetPixel(SDL_Surface *pSurface, int x, int y)
{
	SDL_Color color;
	Uint32 col = 0;
	char *pposition_hero = (char *)pSurface->pixels;
	pposition_hero += (pSurface->pitch * y);
	pposition_hero += (pSurface->format->BytesPerPixel * x);
	memcpy(&col, pposition_hero, pSurface->format->BytesPerPixel);
	SDL_GetRGB(col, pSurface->format, &color.r, &color.g, &color.b);
	return (color);
}

/**
 * @brief La collision parfaite
 * @param h l'héro
 * @param b background
 * @return rien
 */
void collision_parfaite(hero *h, background b)
{
	SDL_Color couleur_obstacle = {0,0,0};
	int i = 0;
	int collision = 0;
	SDL_Rect pos[8];

	h->collision_UP = -1;
	h->collision_DOWN = -1;
	h->collision_RIGHT = -1;
	h->collision_LEFT = -1;

	pos[0].x = h->position_hero.x;
	pos[0].y = h->position_hero.y;
	pos[1].x = h->position_hero.x +80;
	pos[1].y = h->position_hero.y;
	pos[2].x = h->position_hero.x +160;
	pos[2].y = h->position_hero.y;

	pos[3].x = h->position_hero.x;
	pos[3].y = h->position_hero.y +100;
	pos[4].x = h->position_hero.x +160;
	pos[4].y = h->position_hero.y +100;

	pos[5].x = h->position_hero.x;
	pos[5].y = h->position_hero.y +210;
	pos[6].x = h->position_hero.x +80;
	pos[6].y = h->position_hero.y +210;
	pos[7].x = h->position_hero.x +160;
	pos[7].y = h->position_hero.y +210;

	for (i = 0; i < 8; i++)
	{
		couleur_obstacle = GetPixel(b.background_mask,pos[i].x,pos[i].y);
		printf("%d,%d,%d\n",couleur_obstacle.r,couleur_obstacle.g,couleur_obstacle.b);
		if (couleur_obstacle.r == 0 && couleur_obstacle.g == 0 && couleur_obstacle.b == 0)
		{
			if (i == 0)
			{
				h->collision_LEFT++;
				h->collision_UP++;
			}
			if (i == 1)
			{
				h->collision_UP++;
			}
			if (i == 2)
			{
				h->collision_RIGHT++;
				h->collision_UP++;
			}
			if (i == 3)
			{
				h->collision_LEFT++;
			}
			if (i == 4)
			{
				h->collision_RIGHT++;
			}
			if (i == 5)
			{
				h->collision_LEFT++;
				h->collision_DOWN++;
			}
			if (i == 6)
			{
				h->collision_DOWN++;
			}
			if (i == 7)
			{
				h->collision_RIGHT++;
				h->collision_DOWN++;
			}
		}
	}
	/*if (h->collision_LEFT <= 0)
		h->collision_LEFT = 0;
	else
		h->collision_LEFT = 1;
	if (h->collision_RIGHT <= 0)
		h->collision_RIGHT = 0;
	else
		h->collision_RIGHT = 1;
	if (h->collision_UP <= 0)
		h->collision_UP = 0;
	else
		h->collision_UP;
	if (h->collision_DOWN <= 0)
		h->collision_DOWN = 0;
	else
		h->collision_DOWN = 1;*/
}

/**
 * @brief Initialiser l'héro
 * @param h l'héro
 * @return rien
 */
void initialiser_hero(hero *h)
{
	h->hero=IMG_Load("pers.png");
    h->position_hero.x = 0;
    h->position_hero.y = 350;
}

/**
 * @brief Afficher l'héro
 * @param h l'héro
 * @param screen la surface 
 * @return rien
 */
void afficher_hero(hero *h,SDL_Surface *screen)
{
	SDL_BlitSurface(h->hero,NULL,screen,&h->position_hero);
	SDL_Flip(screen);
}

/**
 * @brief Vérifier le scrolling et la collision parfaite
 * @param h l'héro
 * @param event l'évenment a faire
 * @param b background
 * @return rien
 */
void deplacer_hero(hero *h, SDL_Event event,background *b) 
{
	
    switch (event.type)
    {
    case SDL_KEYDOWN:
        switch (event.key.keysym.sym)
        {
        case SDLK_RIGHT:

			collision_parfaite(h,*b);
			if(h->collision_RIGHT==0)
			printf ("bravo\n");
			if(h->collision_RIGHT==-1)
			scrolling(b,event);
			
		
            break;
        case SDLK_LEFT:

            collision_parfaite(h,*b);
			if(h->collision_LEFT==0)
			printf ("bravo\n");
			if(h->collision_LEFT==-1)
			scrolling(b,event);
		
	
            break;
	    case SDLK_UP:

		collision_parfaite(h,*b);
			if(h->collision_UP==0)
			printf ("bravo\n");
			if(h->collision_UP==-1)
			h->position_hero.y--;

		    break;
		case SDLK_DOWN:

		collision_parfaite(h,*b);
			if(h->collision_DOWN==0)
			printf ("bravo\n");
			if(h->collision_DOWN==-1)
		    h->position_hero.y++;

            break;
        }
        break;
    }
}

/**
 * @brief Libérer l'héro
 * @param h l'héro
 * @return rien
 */
void free_hero(hero *h)
{
	SDL_FreeSurface(h->hero);
}
