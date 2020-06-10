/**
* @file pers.c
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include "pers.h"

/**
* @brief To initialize the person p .
* @param p the pers
* @param screen the surface
* @return Nothing
*/
void initpers(pers *p,SDL_Surface* screen)
{
p->pers1=IMG_Load("pers1.png");
p->pers2=IMG_Load("pers2.png");
p->pers3=IMG_Load("pers3.png");
p->pers4=IMG_Load("Fichier 27.png");
p->pers5=IMG_Load("ar1.png");
p->pers6=IMG_Load("ar2.png");
p->pers7=IMG_Load("ar3.png");
p->persmort=IMG_Load("persmort.png");
p->jump1=IMG_Load("jump1.png");
p->jump2=IMG_Load("jump2.png");
p->jump3=IMG_Load("jumpar1.png");
p->jump4=IMG_Load("jumpar2.png");
//p->jump[2]=IMG_Load("jump3.png");
p->perspos.x=0;
p->perspos.y=150;
p->time=0;
p->vie=3;
p->score=0;
p->acceleration=0;
p->vitesse=2;
//SDL_SetColorKey(p->pers1,SDL_SRCCOLORKEY,SDL_MapRGB(p->pers1->format ,255,255,255));
SDL_BlitSurface(p->pers1,NULL,screen,&p->perspos);
SDL_Flip(screen);
}
/**
* @brief To input the person p and manip speed and Jump .
* @param p the pers
* @param i the counter
* @param other param the situation of the person 
* @return Nothing
*/
int inputpers(pers *p,int i,int *jump,int *pause,int *attaquee,int *arriere,int *avant,Uint32 dt)
{
SDL_Event e;
SDL_PollEvent(&e);
int occ=0;
switch(e.type)
{	
case SDL_KEYDOWN:
switch(e.key.keysym.sym)
{
case SDLK_RIGHT :
if(p->perspos.x+170<750){
i++;
*jump=0;
occ=1;
*avant=1;
*arriere=0;
if ((p->perspos.x+p->vitesse*(dt)+p->acceleration*(dt)*(dt))>p->perspos.x)
p->perspos.x=p->perspos.x+p->vitesse*(dt)+p->acceleration*(dt)*(dt);
else 
p->acceleration=0;}
if(p->perspos.x+170>=750){
p->perspos.x=0;
}
break;
case SDLK_LEFT :
i++;
*jump=0;
*arriere=1;
*avant=0;
occ=1;
if ((p->perspos.x - (p->vitesse*(dt)+p->acceleration*(dt)*(dt)))<p->perspos.x)
p->perspos.x=p->perspos.x-(p->vitesse*(dt)+p->acceleration*(dt)*(dt));
else 
p->acceleration=0;
if(p->perspos.x-20<0){
p->perspos.x=750;}
break;
case SDLK_UP:
if(p->perspos.y>0){
p->perspos.y=p->perspos.y-75;
*jump=1;
i=0;
occ=1;}
break;
case SDLK_ESCAPE :
*pause=1;
break;
case SDLK_DOWN:
if(p->perspos.y+250<500){
p->perspos.y=p->perspos.y+75;
*jump=2;
i=0;
occ=1;}
break;
case SDLK_v :
p->acceleration=p->acceleration + 0.01;
break;
case SDLK_f:
p->acceleration=p->acceleration-0.01;
break;
case SDLK_SPACE:
if(*avant==1){
   	    p->perspos.x=p->perspos.x+20;
            p->perspos.y=p->perspos.y-150;
if (p->perspos.x+210>750){p->perspos.x=0;}}
if(*arriere==1){
   	    p->perspos.x=p->perspos.x-20;
            p->perspos.y=p->perspos.y-150;
if (p->perspos.x<0){p->perspos.x=750;}}
break;
case SDLK_a:
*attaquee=1;
return 5;
break;
}
if(i>=5)
{
i=1;	
}	

case SDL_KEYUP:
                    switch (e.key.keysym.sym) {
                        case SDLK_SPACE:
if (*avant==1){
                            p->perspos.x=p->perspos.x+20;
            p->perspos.y=p->perspos.y+75;
if (p->perspos.x+210>750){p->perspos.x=0;}}
if (*arriere==1)
{
                            p->perspos.x=p->perspos.x-20;
            p->perspos.y=p->perspos.y+75;
if (p->perspos.x<0){p->perspos.x=750;}}
                            break;
                    }
                    break;
}
return i;
}
/*int done=1,m=1,s=0;
while(done)
{
SDL_Event event;
while (SDL_PollEvent(&event))
{
switch(event.type)
{
	case SDL_QUIT:
done=0;
break;
	case SDL_KEYDOWN:
if (event.key.keysym.sym==SDLK_RIGHT)
{
i++;
i=2;
*j=0;
done=1;
o=0;
p->perspos.x+=10;
}
if (event.key.keysym.sym==SDLK_LEFT)
{
o++;
*j=0;
i=0;
done=1;
p->perspos.x-=10;
}
if (m==1 && event.key.keysym.sym==SDLK_UP)
{
*j=11;
done=1;
p->perspos.y-=75;
s=1;
m=0;
i=0;
o=0;
}
if (s==1 && event.key.keysym.sym==SDLK_DOWN)
{
*j=12;
i=0;
done=1;
p->perspos.y+=75;
s=0;
m=1;
o=0;
}
break;
}
}
if(i>4)
i=1;
return i;
if(o>2)
o=1;
return o;
}
}*/

/**
* @brief To poster the person p .
* @param p the pers
* @param screen the surface
* @return Nothing
*/
void affichepers(pers *p,int i,SDL_Surface* screen)
{
if(i==1){
printf("\n soso");
SDL_SetColorKey(p->pers3,SDL_SRCCOLORKEY,SDL_MapRGB(p->pers3->format ,255,255,255));//
SDL_BlitSurface(p->pers3,NULL,screen,&p->perspos);
SDL_Flip(screen);}
if(i==2){
SDL_SetColorKey(p->pers2,SDL_SRCCOLORKEY,SDL_MapRGB(p->pers2->format ,255,255,255));//
SDL_BlitSurface(p->pers2,NULL,screen,&p->perspos);
SDL_Flip(screen);}
if(i==3){
SDL_SetColorKey(p->pers4,SDL_SRCCOLORKEY,SDL_MapRGB(p->pers4->format ,255,255,255));//
SDL_BlitSurface(p->pers4,NULL,screen,&p->perspos);
SDL_Flip(screen);}
if(i==4){
SDL_SetColorKey(p->pers2,SDL_SRCCOLORKEY,SDL_MapRGB(p->pers2->format ,255,255,255));//
SDL_BlitSurface(p->pers2,NULL,screen,&p->perspos);
SDL_Flip(screen);}
}
/**
* @brief To poster the person p .
* @param p the pers
* @param i the counter
* @param screen the surface
* @return Nothing
*/
void affichepersar(pers *p,int i,SDL_Surface* screen)
{
if(i==1){
printf("\n soso");
SDL_SetColorKey(p->pers5,SDL_SRCCOLORKEY,SDL_MapRGB(p->pers5->format ,255,255,255));//
SDL_BlitSurface(p->pers5,NULL,screen,&p->perspos);
SDL_Flip(screen);}
if(i==2){
SDL_SetColorKey(p->pers6,SDL_SRCCOLORKEY,SDL_MapRGB(p->pers6->format ,255,255,255));//
SDL_BlitSurface(p->pers6,NULL,screen,&p->perspos);
SDL_Flip(screen);}
if(i==3){
SDL_SetColorKey(p->pers7,SDL_SRCCOLORKEY,SDL_MapRGB(p->pers7->format ,255,255,255));//
SDL_BlitSurface(p->pers7,NULL,screen,&p->perspos);
SDL_Flip(screen);}
if(i==4){
SDL_SetColorKey(p->pers6,SDL_SRCCOLORKEY,SDL_MapRGB(p->pers6->format ,255,255,255));//
SDL_BlitSurface(p->pers6,NULL,screen,&p->perspos);
SDL_Flip(screen);}
}
/**
* @brief To poster the person p .
* @param p the pers
* @param screen the surface
* @return Nothing
*/
void monterjump(pers *p,SDL_Surface* screen)
{
SDL_SetColorKey(p->jump1,SDL_SRCCOLORKEY,SDL_MapRGB(p->jump1->format ,255,255,255));//
SDL_BlitSurface(p->jump1,NULL,screen,&p->perspos);	
SDL_Flip(screen);
}
/**
* @brief To poster the person p .
* @param p the pers
* @param screen the surface
* @return Nothing
*/
void decentejump(pers *p,SDL_Surface* screen)
{
SDL_SetColorKey(p->jump2,SDL_SRCCOLORKEY,SDL_MapRGB(p->jump2->format ,255,255,255));//
SDL_BlitSurface(p->jump2,NULL,screen,&p->perspos);
SDL_Flip(screen);
}
/**
* @brief To poster the person p .
* @param p the pers
* @param screen the surface
* @return Nothing
*/
void monterjumpar(pers *p,SDL_Surface* screen)
{
SDL_SetColorKey(p->jump3,SDL_SRCCOLORKEY,SDL_MapRGB(p->jump3->format ,255,255,255));//
SDL_BlitSurface(p->jump3,NULL,screen,&p->perspos);	
SDL_Flip(screen);
}
/**
* @brief To poster the person p .
* @param p the pers
* @param screen the surface
* @return Nothing
*/
void decentejumpar(pers *p,SDL_Surface* screen)
{
SDL_SetColorKey(p->jump4,SDL_SRCCOLORKEY,SDL_MapRGB(p->jump4->format ,255,255,255));//
SDL_BlitSurface(p->jump4,NULL,screen,&p->perspos);
SDL_Flip(screen);
}
/**
* @brief To poster the person p .
* @param p the pers
* @param screen the surface
* @return Nothing
*/
void mortpers(pers *p,SDL_Surface *screen)
{
	SDL_SetColorKey(p->persmort,SDL_SRCCOLORKEY,SDL_MapRGB(p->persmort->format ,255,255,255));//
	SDL_BlitSurface(p->persmort,NULL,screen,&p->perspos);
	SDL_Flip(screen);
}
void saut(pers *p)
{


}
