#ifndef FUNCTION_H_INCLUDED
#define FUNCTION_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
/**
* @struct score 
* @brief struct score
*/
typedef struct
{
TTF_Font *police;
SDL_Rect pos;
int score;
SDL_Surface *texte;
//SDL_Surface *screen;
}score;
/**
* @struct life
* @brief struct life
*/
typedef struct
{
    
SDL_Surface *texte2;  

SDL_Rect pos2;
int life;
TTF_Font* police2;
}life;
/**
* @struct temps 
* @brief struct time
*/
typedef struct {
SDL_Surface *texte3; 
SDL_Rect pos3;
TTF_Font *police3;

}temps;
/**
* @struct background 
* @brief struct background
*/
typedef struct 
{
SDL_Surface * image_back[3]; /*!< Surface du background */
SDL_Rect pos_image_back[3];  /*!< Position du background */
SDL_Rect pos_camera; /*!< Position de la caméra */
SDL_Surface * image_backmasque[3]; /*!< Surface du background masque */
SDL_Rect pos_image_backmasque[3]; /*!< Position du background masque */
} background ;
/**
 * @struct personnage
 * @brief Structure du personnage
 */
typedef struct 
{
    SDL_Surface * image_perso; /*!< Surface du personnage */
    SDL_Rect pos_image_perso; /*!< Position du personnage */
    int tabX[8]; /*!< Tableau d'entiers des points situés au personnage lors de la collision avec un obstacle suivant l'axe  abscisses */
    int tabY[8]; /*!< Tableau d'entiers des points situés au personnage lors de la collision avec un obstacle suivant l'axe des ordonnées */
} personnage ;

void affichescore(SDL_Surface *ecran,SDL_Surface *texte,SDL_Rect pos);
void initaffichelife(SDL_Surface *ecran,SDL_Surface *text2,SDL_Rect pos2);
void initaffichetemps(SDL_Surface *ecran,SDL_Surface *text3,SDL_Rect pos3);
//int collision_direction_droite_personnage(background * bg , personnage * p , int backnum)
//void colisiontest(SDL_Surface *ecran,SDL_Surface *texte,SDL_Surface *text2);

#endif
