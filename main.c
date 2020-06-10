/**
* @file main.c
* @brief Testing Program.
* @author MedAzaiez
* @version 2.0
* @date may 27, 2020
*
* affichage score ,life and the time
*
*/
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "function.h"

int main(int argc, char *argv[])
{



    SDL_Surface *ecran = NULL, *texte = NULL, *fond = NULL,*text2=NULL,*text3=NULL;
    SDL_Rect position,pos,pos2,pos3;

   int tempsActuel = 0, tempsPrecedent = 0, compteur = 0,compteur2=0,compteur3=0;
/* Tableau de char suffisamment grand */
char score[20]="";
    char temps[20] = ""; 

char health[20]= "";


    SDL_Event event;
/*initialisation de police */
    TTF_Font *police = NULL;
    TTF_Font *police2 = NULL;
    TTF_Font *police3 = NULL;
/*initialisation de couleur */
    SDL_Color couleurNoire = {255, 1, 5},col={255,255,255};
 SDL_Color couleur = {1, 1, 1};
SDL_Color couleur2 = {0, 0,0};

    int continuer = 1;
/*initialisation de screen */
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init(); /*text*/

    ecran = SDL_SetVideoMode(900, 506, 32, SDL_HWSURFACE | SDL_DOUBLEBUF| SDL_INIT_TIMER);
    SDL_WM_SetCaption("Gestion du texte avec SDL_ttf", NULL);

    fond = IMG_Load("aa.jpg");

    /* Chargement de la police */
     police = TTF_OpenFont("angelina.ttf", 65);
     police2=TTF_OpenFont("angelina.ttf", 65);
     police3=TTF_OpenFont("angelina.ttf", 65);
    /* Écriture du texte dans la SDL_Surface texte en mode Blended (optimal) */

    text2=TTF_RenderText_Blended(police2,"health : 100%" , couleur);
/*inistialisation de score*/
   sprintf(score, "Score : %d", compteur2);


texte = TTF_RenderText_Blended(police, score, couleurNoire);



/*inistialisation de Temps*/
tempsActuel = SDL_GetTicks();

    sprintf(temps, "Temps : %d", compteur);
    text3 = TTF_RenderText_Blended(police3, temps, couleur2);
    
   while (continuer)
{
    SDL_WaitEvent(&event);
    switch(event.type)
    {
        case SDL_QUIT:
            continuer = 0;
            break;
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
                case SDLK_ESCAPE: /* Appui sur la touche Echap, on arrête le programme */
                    continuer = 0;
                    break;
            }
            break;
    }

        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));

        position.x = 0;
        position.y = 0;
        SDL_BlitSurface(fond, NULL, ecran, &position); /* Blit du fond */
/*function collision test*/
//if (colisiontest){
compteur2+=10;  
   sprintf(score, "Score : %d", compteur2);
    SDL_FreeSurface(texte);
texte = TTF_RenderText_Blended(police, score, couleurNoire);
pos.x=350;
pos.y=10;



affichescore(ecran,texte,pos);

 /* Blit du fond */
      pos2.x = 20;
        pos2.y = 10;

        initaffichelife(ecran,text2,pos2);
/*Fonctionement de temps*/
 tempsActuel = SDL_GetTicks();
        if (tempsActuel - tempsPrecedent >= 100) /* Si 100 ms au moins se sont écoulées */
        {
            compteur += 1; /* On rajoute 100 ms au compteur */
            sprintf(temps, "Temps : %d", compteur); /* On écrit dans la chaîne "temps" le nouveau temps */
            SDL_FreeSurface(text3); /* On supprime la surface précédente */
            text3 = TTF_RenderText_Blended(police3, temps, couleur2); /* On écrit la chaîne temps dans la SDL_Surface */
            tempsPrecedent = tempsActuel; /* On met à jour le tempsPrecedent */
        }



 /* On supprime la surface précédente */
pos3.x=600;
pos3.y=10;

initaffichetemps(ecran,text3,pos3);

 
        
    }

    TTF_CloseFont(police);
    TTF_CloseFont(police2);
    TTF_CloseFont(police3);
    TTF_Quit();

    SDL_FreeSurface(texte);
    SDL_FreeSurface(text2);

    
SDL_FreeSurface(text3);
    SDL_Quit();


    return EXIT_SUCCESS;
}

