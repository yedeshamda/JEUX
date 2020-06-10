/**
* @file main.c
* @brief partie personnage du jeu complet.
* @author Yedes Hamda
* @version 1.2
* @date Apr 30, 2020
*
* Testing program
*
*/
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "pers.h"
int main (int argc,char** argv)
{
	SDL_Surface *screen=NULL;
	SDL_Surface *image=NULL;
        SDL_Surface *detective=NULL;
        SDL_WM_SetCaption("SDL_Mixer", NULL);
        SDL_WM_SetCaption("Gestion des évènements en SDL", NULL);
	SDL_Rect positionecran,detec;
int done=1,x,y,k=0,o=0,i=0,j=0,m=0,s=0,obstacle=0,jump,attaquee,pause,arriere,avant,vie=3;
pers p;
SDL_Event event;
positionecran.x=0;
positionecran.y=0;
const int FPS=32;
Uint32 dt=1;
Uint32 t_prev;
SDL_Init(SDL_INIT_EVERYTHING);
//screen=SDL_SetVideoMode(750,500,32,SDL_HWSURFACE);
screen=SDL_SetVideoMode(750,500,32,SDL_HWSURFACE);
SDL_WM_SetCaption("chargement d'image en SDL",NULL);
image=IMG_Load("Artboard 2.png");
//image=IMG_Load("Artboard 2.png");
if(!image)
{
printf("unable to load bitmap :%s\n",SDL_GetError());
return -1;}
detective=IMG_Load("pers1.png");
if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024)==-1)
// AP| Mixer init
{
printf("%s\n",Mix_GetError());
}
Mix_Music *music; //construct mix_music_pointer
music=Mix_LoadMUS("music.mp3"); //Load the music
Mix_PlayMusic(music, -1);//play music;
SDL_BlitSurface(image,NULL,screen,&positionecran);
SDL_Flip(screen);
	initpers(&p,screen);
while(p.vie >0)
{
	t_prev=SDL_GetTicks();
	i=inputpers(&p,i,&jump,&pause,&attaquee,&arriere,&avant,dt);
if(i!=0 && avant==1)
{	
	p.acceleration=p.acceleration-0.001;
	SDL_BlitSurface(image,NULL,screen,&positionecran);
	affichepers(&p,i,screen);
printf("acceleration egale %f\n",p.acceleration);
printf("position egale %d\n",p.perspos.x);
printf("dt egale %u\n",dt);
printf("tprev egale %u\n",t_prev);
printf("vitesse egale %f\n",p.vitesse);
}
if(i!=0 && arriere==1)
{
	p.acceleration=p.acceleration-0.001;
	SDL_BlitSurface(image,NULL,screen,&positionecran);
	affichepersar(&p,i,screen);
printf("vitesse egale %f\n",p.vitesse);
printf("acceleration egale %f\n",p.acceleration);
printf("position egale %d\n",p.perspos.x);
printf("dt egale %u\n",dt);
}
if(jump==1 && arriere==1)
{
	SDL_BlitSurface(image,NULL,screen,&positionecran);
	monterjumpar(&p,screen);
	jump=0;
}
if(jump==2 && arriere==1)
{
	SDL_BlitSurface(image,NULL,screen,&positionecran);
	decentejumpar(&p,screen);
	jump=0;
}
if(jump==1 && avant==1){
	SDL_BlitSurface(image,NULL,screen,&positionecran);
	monterjump(&p,screen);
	jump=0;
}
if(jump==2 && avant==1)
{
	SDL_BlitSurface(image,NULL,screen,&positionecran);
	decentejump(&p,screen);
printf("hamda");
	jump=0;
}
if (obstacle==1){
	p.vie=p.vie-1;
	printf("%d",p.vie);
obstacle=0;
}
dt=SDL_GetTicks()-t_prev;
	if(1000/FPS>dt)
	SDL_Delay(1000/FPS-dt);
}
if (p.vie==0){
	SDL_BlitSurface(image,NULL,screen,&positionecran);
	mortpers(&p,screen);}
//afficher GameOver;
SDL_FreeSurface(image);
Mix_FreeMusic(music);
Mix_CloseAudio();
return 0;}
