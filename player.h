#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "background.h"

/**
 * @struct Hero
 * @brief Structure de l'héro
 */
struct Player
{
	SDL_Rect position; /*!< Position de l'héro */
	SDL_Surface * image; /*!< Surface de l'héro */
	int jouer; /*!< Mouvements de l'héro */
};
typedef struct Player Player;

int loadPlayerImages(Player *A);
void initPlayer(Player *A);
void freePlayer(Player *A);
void movePlayer(Player *A);

