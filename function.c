/**
* @file function.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "function.h"
/**
* @brief To show the score
* @param texte est le texte de score
* @param ecran the screen
* @param pos la position de score texte
* @return Nothing
*/
void affichescore(SDL_Surface *ecran,SDL_Surface *texte,SDL_Rect pos){

SDL_BlitSurface(texte, NULL, ecran, &pos);
SDL_Flip(ecran); }
/**
* @brief To show the life 
* @param ecran the screen
* @param text2 texte de health pourcentage
* @param pos2 la position de healh texte
* @return Nothing

*/
void initaffichelife(SDL_Surface *ecran,SDL_Surface *text2,SDL_Rect pos2){
SDL_BlitSurface(text2, NULL, ecran, &pos2);
SDL_Flip(ecran);}

/**
* @brief To show the time
* @param screen the screen
* @param text3 texte de temps
* @param pos3 la position de temps texte
* @return Nothing
*/
 
void initaffichetemps(SDL_Surface *ecran,SDL_Surface *text3,SDL_Rect pos3){
SDL_BlitSurface(text3, NULL, ecran,&pos3);
SDL_Flip(ecran);}
//int collision_direction_droite_personnage(background * bg , personnage * p , int backnum)
//{
	/// background 1 :
	//if (backnum==1)
	//{
	//SDL_Color color3,color8,color7;
	//int collision=0;
	//color3=GetPixel(bg->image_backmasque[0],p->tabX[2],p->tabY[2]);
	//color8=GetPixel(bg->image_backmasque[0],p->tabX[7],p->tabY[7]);
   // color7=GetPixel(bg->image_backmasque[0],p->tabX[6],p->tabY[6]);
//	if(((color3.r==0)  &&  (color3.g==0)  &&  (color3.b==0)) ||
      // ((color8.r==0)  &&  (color8.g==0)  &&  (color8.b==0)) ||
      // ((color7.r==0)  &&  (color7.g==0)  &&  (color7.b==0)))
	  // {
	//	   collision=1;
	  // }
	 //  return collision;  
	//}
	/// background 2 :
	//if (backnum==2)
	//{
	//SDL_Color color3,color8,color7;
	//int collision=0;
	//color3=GetPixel(bg->image_backmasque[1],p->tabX[2],p->tabY[2]);
	//color8=GetPixel(bg->image_backmasque[1],p->tabX[7],p->tabY[7]);
    //color7=GetPixel(bg->image_backmasque[1],p->tabX[6],p->tabY[6]);
	//if(((color3.r==0)  &&  (color3.g==0)  &&  (color3.b==0)) ||
      // ((color8.r==0)  &&  (color8.g==0)  &&  (color8.b==0)) ||
       //((color7.r==0)  &&  (color7.g==0)  &&  (color7.b==0)))
	 //  {
		  // collision=1;
	 //  }
	//   return collision;  
	//}
    /// background 3 :
	//if (backnum==3)
	//{
	//SDL_Color color3,color8,color7;
	//int collision=0;
	//color3=GetPixel(bg->image_backmasque[2],p->tabX[2],p->tabY[2]);
	//color8=GetPixel(bg->image_backmasque[2],p->tabX[7],p->tabY[7]);
   // color7=GetPixel(bg->image_backmasque[2],p->tabX[6],p->tabY[6]);
	///if(((color3.r==0)  &&  (color3.g==0)  &&  (color3.b==0)) ||
      // ((color8.r==0)  &&  (color8.g==0)  &&  (color8.b==0)) ||
       //((color7.r==0)  &&  (color7.g==0)  &&  (color7.b==0)))
	 //  {
		 //  collision=1;
	  // }
	 //  return collision;  
	//}
//}


//void initaffichetemps(temps *p,SDL_Surface *ecran);
