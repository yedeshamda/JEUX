#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"

/**
 * @struct Background
 * @brief Structure du background
 */
typedef struct Background
{
	SDL_Surface *background; /*!< Surface du background */
	SDL_Surface *background_mask; /*!< Surface du background_mask */
	SDL_Rect position_background; /*!< Position du background */
	SDL_Rect position_background_mask; /*!< Position du background_mask */
	SDL_Rect position_Camera; /*!< Position de la caméra */
}background;

/**
 * @struct Hero
 * @brief Structure de l'héro
 */
typedef struct Hero
{
	SDL_Surface *hero; /*!< Surface de l'héro */
    SDL_Rect position_hero; /*!< Position de l'héro */
    int collision_UP, collision_DOWN, collision_RIGHT, collision_LEFT; /*!< Les types de collision produits */
} hero;

void initialiser_background(background *b);
void afficher_background(background *b,SDL_Surface *screen);
void scrolling(background *b, SDL_Event event);
void free_background(background *b);
SDL_Color GetPixel(SDL_Surface *pSurface, int x, int y);
void collision_parfaite(hero *h,background b);
void initialiser_hero(hero *h);
void afficher_hero(hero *h,SDL_Surface *screen);
void deplacer_hero(hero *h, SDL_Event event,background *b);
void free_hero(hero *h);


