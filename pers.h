#ifndef PERSONNAGE_H_INCLUDED
#define PERSONNAGE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
/**
* @struct pers
* @brief struct for person
*/
typedef struct 
{
SDL_Surface* pers1; /*!< Surface. */
SDL_Surface* pers2; /*!< Surface. */
SDL_Surface* pers3; /*!< Surface. */
SDL_Surface* pers4; /*!< Surface. */
SDL_Surface* pers5; /*!< Surface. */
SDL_Surface* pers6; /*!< Surface. */
SDL_Surface* pers7; /*!< Surface. */
SDL_Surface* persmort; /*!< Surface. */
//le personnage marche ez
SDL_Surface* jump1; /*!< Surface. */
SDL_Surface* jump2; /*!< Surface. */
SDL_Surface* jump3; /*!< Surface. */
SDL_Surface* jump4; /*!< Surface. */
//le sprite du jump du personnage
SDL_Rect perspos; /*!< varied*/
SDL_Surface* persobs; /*!< Surface. */
//int orientation;
int time;
int vie;
int score;
double vitesse ; /*!< speed. */
double acceleration;
}pers;
void initpers(pers *p,SDL_Surface* screen);
int inputpers(pers *p,int i,int *jump,int *pause,int *attaque,int *arriere,int *avant,Uint32 dt);
void affichepers(pers *p,int i,SDL_Surface* screen);
void affichepersar(pers *p,int i,SDL_Surface* screen);
void monterjump(pers *p,SDL_Surface *screen);
void decentejump(pers *p,SDL_Surface *screen);
void monterjumpar(pers *p,SDL_Surface *screen);
void decentejumpar(pers *p,SDL_Surface *screen);
void mortpers(pers *p,SDL_Surface *screen);
#endif 
