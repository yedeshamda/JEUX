#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"

/**
 * @struct Background
 * @brief Structure du background
 */
struct Background
{
	SDL_Surface *backgroundImg;  /*!< Surface de la premiére moitié du background */
	SDL_Surface *backgroundCollide;  /*!< Surface de la deuxiéme moitié du background */
	SDL_Rect backgroundPos;  /*!< Position de la premiére moitié du background */
    SDL_Rect backgroundPos2; /*!< Position de la deuxiéme moitié du background */
};
typedef struct Background Background;

int loadBackground(Background *Backg);
void initBackground(Background *Backg);
void freeBackground(Background *Backg);
void blitBackground(Background *Backg,SDL_Surface *screen);
void scrolling (Background *Backg, int numBack);



