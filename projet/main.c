#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
int main (int argc,char** argv)
{
	SDL_Surface *screen=NULL;
	SDL_Surface *image=NULL;
        SDL_Surface *detective=NULL;
        SDL_Surface *Ms = NULL;
        SDL_Surface *Mssel = NULL;
        SDL_Surface *Meis = NULL;
        SDL_Surface *Reglage = NULL;
        SDL_Surface *Reglagesel = NULL;
        SDL_Surface *Reg= NULL;
	SDL_Surface *Credits=NULL;
	SDL_Surface *Creditssel=NULL;
        SDL_Surface *Barre = NULL;
        SDL_Surface *Barre1 = NULL;
	SDL_Surface *Son = NULL;
	SDL_Surface *Mute = NULL;
	SDL_Surface *Score = NULL;
	SDL_Surface *Gold = NULL;
	SDL_Surface *Plus = NULL;
	SDL_Surface *Parametre = NULL;
	SDL_Surface *Aide = NULL;
        SDL_Surface *Fb = NULL;
        SDL_Surface *Gmail = NULL;
        SDL_Surface *Jouer = NULL;
        SDL_Surface *Jouersel = NULL;
        SDL_Surface *Cont = NULL;
        SDL_Surface *Np = NULL;
 	SDL_Surface *Contsel = NULL;
        SDL_Surface *Npsel = NULL;
        SDL_Surface *Quit = NULL;
        SDL_Surface *Quitsel = NULL;
        SDL_Surface *Quit2 = NULL;
        SDL_Surface *Ouisel = NULL;
        SDL_Surface *Nonsel = NULL;
        SDL_Surface *Return = NULL;
        SDL_Surface *Mdj = NULL;
        SDL_Surface *Facile = NULL;
        SDL_Surface *Facilesel = NULL;
	SDL_Surface *Difficile = NULL;
        SDL_Surface *Difficilesel = NULL;
 	SDL_Surface *Moyen = NULL;
        SDL_Surface *Moyensel = NULL;
        SDL_Surface *texte = NULL;
        SDL_Surface *Texte = NULL;
        SDL_Surface *So = NULL;
        SDL_Surface *Sonne = NULL;
        SDL_WM_SetCaption("SDL_Mixer", NULL);
        SDL_WM_SetCaption("Gestion des évènements en SDL", NULL);
	SDL_Rect positionecran,detec,posc,poscsel,posfa,posdi,posso,possonne,posmo,posmosel,postexte,posret,poscore,posouisel,posbar2,posnonsel,posqsel,posms,poscont,posnp,poscontsel,posnpsel,posmssel,posrsel,posmute,posbar,posbar1,posq,posj,posjsel,pospa,poss,posplus,posa,posg,posr,posfb,posgmail,direction;
int menu=0,vol,x,y,p=0,i=0,j=0,quitter=0,play=0,meilleurscore=0,credits=0,setting=0,done=1,doneq=0,openGAME=1,donej=0,donereg=0,reglage=0,jouer=0,donems=0,meis=0,donemdj=0,mdj=0;
SDL_Event event;
TTF_Font *police=NULL;
SDL_Color couleurNoire = {0,0,0};
positionecran.x=0;
positionecran.y=0;
//detec.x=300;
//detec.y=150;
posouisel.x=274.073;
posouisel.y=302.127;
posnonsel.x=418.591;
posnonsel.y=302.127;
posms.x=270;	
posms.y=160;
posmssel.x=270;
posmssel.y=160;
posr.x=270;
posr.y=225;
posret.x=20;
posret.y=35;
posrsel.x=270;
posrsel.y=225;
posbar.x=297;
posbar.y=180;
posbar1.x=297;
posbar1.y=250;
posbar2.x=297;
posbar2.y=220;
posc.x=270;
posc.y=305;
poscsel.x=270;
poscsel.y=305;
poss.x=290;
poss.y=3;
posmute.x=290;
posmute.y=3;
posa.x=400;
posa.y=10;
pospa.x=445;
pospa.y=10;
posg.x=580;
posg.y=10;
poscore.x=595;
poscore.y=12;
posplus.x=696;
posplus.y=16;
posfb.x=18;
posfb.y=7;
posgmail.x=70;
posgmail.y=10;
posj.x=549.43;
posj.y=420;
posjsel.x=549.43;
posjsel.y=420;
poscont.x=237.111;
poscont.y=160;
poscontsel.x=237.111;
poscontsel.y=160;
posnp.x=237.111;
posnp.y=270;
posnpsel.x=237.111;
posnpsel.y=270;
posq.x=20;
posq.y=420;
posqsel.x=20;
posqsel.y=420;
posfa.x=270;
posfa.y=235;
posdi.x=270;
posdi.y=370;
posmo.x=270;
posmo.y=305;
posmosel.x=270;
posmosel.y=305;
postexte.x=60;
postexte.y=50;
posso.x=410;
posso.y=258;
possonne.x=516;
possonne.y=250;
SDL_Init(SDL_INIT_EVERYTHING);
screen=SDL_SetVideoMode(750,500.85,32,SDL_HWSURFACE);
SDL_WM_SetCaption("chargement d'image en SDL",NULL);
image=IMG_Load("Artboard 2.png");
Barre=IMG_Load("BARRE.png");
Barre1=IMG_Load("BARRE.png");
Ms=IMG_Load("MS.png");
Mssel=IMG_Load("MSsel.png");
Reglage=IMG_Load("REGLAGE.png");
Reglagesel=IMG_Load("REGLAGEsel.png");
Credits=IMG_Load("CREDITS.png");
Creditssel=IMG_Load("CREDITSsel.png");
Son=IMG_Load("SON.png");
Mute=IMG_Load("MUTE.png");
Parametre=IMG_Load("PARAMETRE.png");
Aide=IMG_Load("AIDE.png");
Score=IMG_Load("SCORE.png");
Gold=IMG_Load("GOLD.png");
Plus=IMG_Load("PLUS.png");
Fb=IMG_Load("FB.png");
Gmail=IMG_Load("GMAIL.png");
Quit=IMG_Load("QUIT.png");
Quitsel=IMG_Load("QUITsel.png");
Quit2=IMG_Load("quitter.png");
Ouisel=IMG_Load("OUI.png");
Nonsel=IMG_Load("NON.png");
Jouer=IMG_Load("JOUER.png");
Jouersel=IMG_Load("JOUERsel.png");
Cont=IMG_Load("CONT.png");
Np=IMG_Load("NP.png");
texte=IMG_Load("andlsottf.png");
Contsel=IMG_Load("CONTsel.png");
Npsel=IMG_Load("NPsel.png");
Return=IMG_Load("RETURN.png");
Meis=IMG_Load("MEIS.png");
Mdj=IMG_Load("MDJ.png");
Facile=IMG_Load("FACILE.png");
Facilesel=IMG_Load("FACILEsel.png");
Difficile=IMG_Load("DIFFICILE.png");
Difficilesel=IMG_Load("DIFFICILEsel.png");
Moyen=IMG_Load("MOYEN.png");
Moyensel=IMG_Load("MOYENsel.png");
Reg=IMG_Load("REG.png");
police = TTF_OpenFont("andlso.ttf", 60);
Texte =TTF_RenderText_Blended(police,"HOHO",couleurNoire);
So=IMG_Load("so.png");
Sonne=IMG_Load("sonne.png");
//SDL_BlitSurface(image,NULL,screen,&positionecran);
if(!image)
{
printf("unable to load bitmap :%s\n",SDL_GetError());
return -1;}
if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024)==-1)
// AP| Mixer init
{
printf("%s\n",Mix_GetError());
}
Mix_Music *music; //construct mix_music_pointer
music=Mix_LoadMUS("music.mp3"); //Load the music
Mix_PlayMusic(music, -1);//play music;
while(openGAME){
while(done)
{
SDL_BlitSurface(image,NULL,screen,&positionecran);
SDL_BlitSurface(Barre,NULL,screen,&posbar);
SDL_BlitSurface(Barre1,NULL,screen,&posbar1);
SDL_BlitSurface(Ms,NULL,screen,&posms);
SDL_BlitSurface(Reglage,NULL,screen,&posr);
SDL_BlitSurface(Credits,NULL,screen,&posc);
SDL_BlitSurface(Son,NULL,screen,&poss);
SDL_BlitSurface(Parametre,NULL,screen,&pospa);
SDL_BlitSurface(texte,NULL,screen,&postexte);
SDL_BlitSurface(Aide,NULL,screen,&posa);
SDL_BlitSurface(Score,NULL,screen,&poscore);
SDL_BlitSurface(Gold,NULL,screen,&posg);
SDL_BlitSurface(Plus,NULL,screen,&posplus);
SDL_BlitSurface(Fb,NULL,screen,&posfb);
SDL_BlitSurface(Gmail,NULL,screen,&posgmail);
SDL_BlitSurface(Quit,NULL,screen,&posq);
SDL_BlitSurface(Jouer,NULL,screen,&posj);
SDL_BlitSurface(Texte,NULL,screen,&postexte);
SDL_Flip(screen);
done=done-1;
menu=1;
}
//detective=IMG_Load("detective.png");
//SDL_SetColorKey(detective,SDL_SRCCOLORKEY,SDL_MapRGB(detective->format ,255,255,255));
//SDL_BlitSurface(detective,NULL,screen,&detec);
while(menu)
{
SDL_Event event;
while (SDL_PollEvent(&event))
{
switch(event.type)
{
	case SDL_QUIT:
menu=0;
break;
	case SDL_KEYDOWN:
if (event.key.keysym.sym==SDLK_RIGHT){
if(p==0){
 SDL_BlitSurface(Jouersel,NULL,screen,&posjsel);
                    SDL_Flip(screen);
p=0;
		}}
		else {
			 SDL_BlitSurface(Jouer,NULL,screen,&posj);
		         SDL_Flip(screen);
			}
if (event.key.keysym.sym==SDLK_LEFT)
{
if(p==0){
SDL_BlitSurface(Quitsel,NULL,screen,&posqsel);
                    SDL_Flip(screen);
p=0;
		}}
		else {
			 SDL_BlitSurface(Quit,NULL,screen,&posq);
		         SDL_Flip(screen);
			}
if (event.key.keysym.sym==SDLK_UP)
{
if(p==2){
 SDL_BlitSurface(Mssel,NULL,screen,&posmssel);
                    SDL_Flip(screen);
p=3;
		}
		else {
			 SDL_BlitSurface(Ms,NULL,screen,&posms);
		         SDL_Flip(screen);
			}

              if(p==1){
                    SDL_BlitSurface(Reglagesel,NULL,screen,&posrsel);
                    SDL_Flip(screen);
			p=2;
		}
		else {
			 SDL_BlitSurface(Reglage,NULL,screen,&posr);
		         SDL_Flip(screen);
			}
		if(p==0)
                {
                    SDL_BlitSurface(Creditssel,NULL,screen,&poscsel);
                    SDL_Flip(screen);
			p=1;
		}
		else {
			 SDL_BlitSurface(Credits,NULL,screen,&posc);
		         SDL_Flip(screen);
			}}
if (event.key.keysym.sym==SDLK_DOWN)
{              if(p==1){

   SDL_BlitSurface(Creditssel,NULL,screen,&poscsel);
                    SDL_Flip(screen);
 p=0;
		}
		else {
			 
 SDL_BlitSurface(Credits,NULL,screen,&posc);
		         SDL_Flip(screen);
			}

              if(p==2){
                    SDL_BlitSurface(Reglagesel,NULL,screen,&posrsel);
                    SDL_Flip(screen);
			p=1;
		}
		else {
			 SDL_BlitSurface(Reglage,NULL,screen,&posr);
		         SDL_Flip(screen);
			}
		if(p==3)
                {
                 SDL_BlitSurface(Mssel,NULL,screen,&posmssel);
                    SDL_Flip(screen);
			p=2;
		}
		else {SDL_BlitSurface(Ms,NULL,screen,&posms);
		         SDL_Flip(screen);
			
			}}
break;
case SDL_MOUSEMOTION:
                x=0, y=0 ;
                //Get the mouse offsets
                x = event.motion.x;
                y = event.motion.y;
                //If the mouse is over the button
                if( ( posq.x+182>x) && (x>posq.x ) && ( posq.y+67>y) &&(y>posq.y))  
                {
                    //SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
                   // Hamda = IMG_Load("hamda.png");//
                    SDL_BlitSurface(Quitsel,NULL,screen,&posqsel);
                    SDL_Flip(screen);
		}
		else {
			 SDL_BlitSurface(Quit,NULL,screen,&posq);
		         SDL_Flip(screen);
			}
  		 if( ( posj.x+182>x) && (x>posj.x ) && ( posj.y+67>y) &&(y>posj.y))  
                {
                    //SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
                   // Hamda = IMG_Load("hamda.png");//
                    SDL_BlitSurface(Jouersel,NULL,screen,&posjsel);
                    SDL_Flip(screen);
		}
		else {
			 SDL_BlitSurface(Jouer,NULL,screen,&posj);
		         SDL_Flip(screen);
			}
		 if( ( posms.x+221>x) && (x>posms.x ) && ( posms.y+59>y) &&(y>posms.y))  
                {
                    //SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
                   // Hamda = IMG_Load("hamda.png");//
                    SDL_BlitSurface(Mssel,NULL,screen,&posmssel);
                    SDL_Flip(screen);
		}
		else {
			 SDL_BlitSurface(Ms,NULL,screen,&posms);
		         SDL_Flip(screen);
			}
 if( ( posr.x+222>x) && (x>posr.x ) && ( posr.y+63>y) &&(y>posr.y))  
                {
                    //SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
                   // Hamda = IMG_Load("hamda.png");//
                    SDL_BlitSurface(Reglagesel,NULL,screen,&posrsel);
                    SDL_Flip(screen);
		}
		else {
			 SDL_BlitSurface(Reglage,NULL,screen,&posr);
		         SDL_Flip(screen);
			}
if( ( posc.x+221>x) && (x>posc.x ) && ( posc.y+60>y) &&(y>posc.y))  
                {
                    //SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
                   // Hamda = IMG_Load("hamda.png");//
                    SDL_BlitSurface(Creditssel,NULL,screen,&poscsel);
                    SDL_Flip(screen);
		}
		else {
			 SDL_BlitSurface(Credits,NULL,screen,&posc);
		         SDL_Flip(screen);
			}
/*x=0, y=0 ;
					x=event.motion.x;
					y=event.motion.y;
					//Play_Button
					if (( posq.x+130>x) && (x>posq.x ) && ( posq.y+35>y) &&(y>posq.y))
					{
						SDL_BlitSurface(Quit2,NULL,screen,&posq);
					}
					//Settings_Button
				else if (x > (1350/2)-(370/2) && x < (1350/2)+(370/2) && y > 452 && y < 520)
					{
						SDL_BlitSurface(/*settings_hover_button,NULL,screen,&settings_button_rect);
					}
					//Toto_Button
					else if (x > (1350/2)-(370/2) && x < (1350/2)+(370/2) && y > 532 && y < 600)
					{
						SDL_BlitSurface(tutorial_hover_button,NULL,screen,&tutorial_button_rect);
					}
					else if (x > 1100 && x < 1100+199 && y > 555 && y < 555+40)
					{
						SDL_BlitSurface(credit_hover_button,NULL,screen,&credit_button_rect);
			//		}*/
					
/*						SDL_BlitSurface(settings_button,NULL,screen,&settings_button_rect);
						SDL_BlitSurface(tutorial_button,NULL,screen,&tutorial_button_rect);
						SDL_BlitSurface(credit_button,NULL,screen,&credit_button_rect);
					}*/
break;
case SDL_MOUSEBUTTONUP:
                   if(event.button.x >= 290 && event.button.x <= 333
                    && event.button.y >= 0 && event.button.y <= 40){
 			if(event.button.button == SDL_BUTTON_LEFT && i==0)
                   {
			SDL_BlitSurface(Mute,NULL,screen,&posmute);
                        SDL_Flip(screen);
				i++;}
		else if(event.button.button == SDL_BUTTON_LEFT && i!=0)
				{

			SDL_BlitSurface(Son,NULL,screen,&poss);
                        SDL_Flip(screen);
				i--;	}
		}
 		if(event.button.x >=20  && event.button.x <= 220
                   && event.button.y >= 450 && event.button.y <= 510){
 			if(event.button.button == SDL_BUTTON_LEFT)// && i==0)
                   {	
			doneq=1;
			menu=0;
				//i++;
		   }}
if(event.button.x >= 549.43 && event.button.x <= 731.43
                   && event.button.y >= 420 && event.button.y <= 487){
 			if(event.button.button == SDL_BUTTON_LEFT)// && i==0)
                   {	
			donej=1;
			menu=0;
				//i++;
		   }}
if(event.button.x >= 270 && event.button.x <= 491 && event.button.y >= 160 && event.button.y <= 219){
 			if(event.button.button == SDL_BUTTON_LEFT)// && i==0)
                   {	
			donems=1;
			menu=0;
				//i++;
		   }
	//	else if(event.button.button == SDL_BUTTON_LEFT && i!=0)
			//	{
			//SDL_BlitSurface(Quit,NULL,screen,&posq);
                    //    SDL_Flip(screen);
			//	i--;	}
		}
if(event.button.x >= 270 && event.button.x <= 491 && event.button.y >= 225 && event.button.y <= 284){
 			if(event.button.button == SDL_BUTTON_LEFT)// && i==0)
                   {	
			donereg=1;
			menu=0;
				//i++;
		   }}
break;
}
}
}
while(doneq)
{
SDL_BlitSurface(Quit2,NULL,screen,&positionecran);
SDL_Flip(screen);
doneq=0;
quitter=1;
}
while(quitter)
{
SDL_Event event;
while (SDL_PollEvent(&event))
{
switch(event.type)
{
	case SDL_QUIT:
menu=0;
break;
	case SDL_KEYDOWN:
if (event.key.keysym.sym==SDLK_RIGHT)
{
quitter=1;
detec.x+=10;
}
if (event.key.keysym.sym==SDLK_LEFT)
{
quitter=1;
detec.x-=10;}
if (event.key.keysym.sym==SDLK_UP)
{
quitter=1;
detec.y-=10;}
if (event.key.keysym.sym==SDLK_DOWN)
{
quitter=1;
detec.y+=10;}
break;
  case SDL_MOUSEMOTION:
                x=0, y=0 ;
                //Get the mouse offsets
                x = event.motion.x;
                y = event.motion.y;
                //If the mouse is over the button
          if( ( 316.177>x) && (x>276.073) && ( 333.782>y) &&(y>302.127))   
                {
                    //SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));//
                   // Hamda = IMG_Load("hamda.png");//
                    SDL_BlitSurface(Ouisel, NULL, screen, &posouisel);
                    SDL_Flip(screen);
                }
		else {
			 SDL_BlitSurface(Quit2,NULL,screen,&positionecran);
		         SDL_Flip(screen);
			}
   		 if( ( 469.645>x) && (x>418.591) && ( 333.782>y) &&(y>302.127))   
                {
                    //SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));//
                   // Hamda = IMG_Load("hamda.png");//
                    SDL_BlitSurface(Nonsel, NULL, screen, &posnonsel);
                    SDL_Flip(screen);
                }
		else {
			 SDL_BlitSurface(Quit2,NULL,screen,&positionecran);
		         SDL_Flip(screen);
			}

/*x=0, y=0 ;
					x=event.motion.x;
					y=event.motion.y;
					//Play_Button
					if (( posq.x+130>x) && (x>posq.x ) && ( posq.y+35>y) &&(y>posq.y))
					{
						SDL_BlitSurface(Quit2,NULL,screen,&posq);
					}
					//Settings_Button
				else if (x > (1350/2)-(370/2) && x < (1350/2)+(370/2) && y > 452 && y < 520)
					{
						SDL_BlitSurface(/*settings_hover_button,NULL,screen,&settings_button_rect);
					}
					//Toto_Button
					else if (x > (1350/2)-(370/2) && x < (1350/2)+(370/2) && y > 532 && y < 600)
					{
						SDL_BlitSurface(tutorial_hover_button,NULL,screen,&tutorial_button_rect);
					}
					else if (x > 1100 && x < 1100+199 && y > 555 && y < 555+40)
					{
						SDL_BlitSurface(credit_hover_button,NULL,screen,&credit_button_rect);
			//		}*/
			//		else
					//{
	//					SDL_BlitSurface(Quit,NULL,screen,&posq);}
/*						SDL_BlitSurface(settings_button,NULL,screen,&settings_button_rect);
						SDL_BlitSurface(tutorial_button,NULL,screen,&tutorial_button_rect);
						SDL_BlitSurface(credit_button,NULL,screen,&credit_button_rect);
					}*/
break;
	case SDL_MOUSEBUTTONUP:
 			if(event.button.x >=418.591  && event.button.x <= 469.645
                   && event.button.y >= 302.127 && event.button.y <= 333.782){
 			if(event.button.button == SDL_BUTTON_LEFT)// && i==0)
                   {	
			done=1;
		  	quitter=0;
				//i++;
		   }}
	//	else if(event.button.button == SDL_BUTTON_LEFT && i!=0)
			//	{
			//SDL_BlitSurface(Quit,NULL,screen,&posq);
                    //    SDL_Flip(screen);
			//	i--;	}
          if( ( 316.177>x) && (x>276.073) && ( 333.782>y) &&(y>302.127))   
	if(event.button.x >=276.073  && event.button.x <= 316.177
                   && event.button.y >= 302.127 && event.button.y <= 333.782){
 			if(event.button.button == SDL_BUTTON_LEFT)// && i==0)
                   {	
			return 0;
				//i++;
		   }}
break;
}
}
}
while(donej)
{
SDL_BlitSurface(image,NULL,screen,&positionecran);
SDL_BlitSurface(Barre,NULL,screen,&posbar2);
SDL_BlitSurface(Cont,NULL,screen,&poscont);
SDL_BlitSurface(Np,NULL,screen,&posnp);
SDL_BlitSurface(Return,NULL,screen,&posret);
SDL_BlitSurface(Score,NULL,screen,&poscore);
SDL_BlitSurface(Gold,NULL,screen,&posg);
SDL_BlitSurface(Plus,NULL,screen,&posplus);
SDL_Flip(screen);
donej=0;
jouer=1;
}
while(jouer)
{
SDL_Event event;
while (SDL_PollEvent(&event))
{
switch(event.type)
{
	case SDL_QUIT:
menu=0;
break;
	case SDL_KEYDOWN:
if (event.key.keysym.sym==SDLK_RIGHT)
{
quitter=1;
detec.x+=10;
}
if (event.key.keysym.sym==SDLK_LEFT)
{
quitter=1;
detec.x-=10;}
if (event.key.keysym.sym==SDLK_UP)
{
quitter=1;
detec.y-=10;}
if (event.key.keysym.sym==SDLK_DOWN)
{
quitter=1;
detec.y+=10;}
break;
  case SDL_MOUSEMOTION:
                x=0, y=0 ;
                //Get the mouse offsets
                x = event.motion.x;
                y = event.motion.y;
                //If the mouse is over the button
          if( ( poscont.x+285>x) && (x>poscont.x) && ( 100+poscont.y>y) &&(y>poscont.y))   
                {
                    //SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));//
                   // Hamda = IMG_Load("hamda.png");//
                    SDL_BlitSurface(Contsel, NULL, screen, &poscontsel);
                    SDL_Flip(screen);
                }
		else {
			 SDL_BlitSurface(Cont,NULL,screen,&poscont);
		         SDL_Flip(screen);
			}
   		 if((  posnp.x+286>x) && (x>posnp.x) && ( 118+posnp.y>y) &&(y>posnp.y))   
                {
                    //SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));//
                   // Hamda = IMG_Load("hamda.png");//
                    SDL_BlitSurface(Npsel, NULL, screen, &posnpsel);
                    SDL_Flip(screen);
                }
		else {
			 SDL_BlitSurface(Np,NULL,screen,&posnp);
		         SDL_Flip(screen);
			}

/*x=0, y=0 ;
					x=event.motion.x;
					y=event.motion.y;
					//Play_Button
					if (( posq.x+130>x) && (x>posq.x ) && ( posq.y+35>y) &&(y>posq.y))
					{
						SDL_BlitSurface(Quit2,NULL,screen,&posq);
					}
					//Settings_Button
				else if (x > (1350/2)-(370/2) && x < (1350/2)+(370/2) && y > 452 && y < 520)
					{
						SDL_BlitSurface(/*settings_hover_button,NULL,screen,&settings_button_rect);
					}
					//Toto_Button
					else if (x > (1350/2)-(370/2) && x < (1350/2)+(370/2) && y > 532 && y < 600)
					{
						SDL_BlitSurface(tutorial_hover_button,NULL,screen,&tutorial_button_rect);
					}
					else if (x > 1100 && x < 1100+199 && y > 555 && y < 555+40)
					{
						SDL_BlitSurface(credit_hover_button,NULL,screen,&credit_button_rect);
			//		}*/
			//		else
					//{
	//					SDL_BlitSurface(Quit,NULL,screen,&posq);}
/*						SDL_BlitSurface(settings_button,NULL,screen,&settings_button_rect);
						SDL_BlitSurface(tutorial_button,NULL,screen,&tutorial_button_rect);
						SDL_BlitSurface(credit_button,NULL,screen,&credit_button_rect);
					}*/
break;
	case SDL_MOUSEBUTTONUP:
 			if(event.button.x >=20  && event.button.x <= 59
                   && event.button.y >= 35 && event.button.y <= 72){
 			if(event.button.button == SDL_BUTTON_LEFT)// && i==0)
                   {	
			done=1;
		  	jouer=0;
				//i++;
		   }}
		if(event.button.x >=237.111  && event.button.x <= 523.111
                   && event.button.y >= 270 && event.button.y <= 388.5){
 			if(event.button.button == SDL_BUTTON_LEFT)// && i==0)
                   {	
			donemdj=1;
		  	jouer=0;
				//i++;
		   }}
	//	else if(event.button.button == SDL_BUTTON_LEFT && i!=0)
			//	{
			//SDL_BlitSurface(Quit,NULL,screen,&posq);
                    //    SDL_Flip(screen);
			//	i--;	}
break;
}
}
}
while(donems)
{
SDL_BlitSurface(Meis,NULL,screen,&positionecran);
SDL_BlitSurface(Return,NULL,screen,&posret);
SDL_BlitSurface(Score,NULL,screen,&poscore);
SDL_BlitSurface(Gold,NULL,screen,&posg);
SDL_BlitSurface(Plus,NULL,screen,&posplus);
SDL_Flip(screen);
donems=0;
meis=1;
}
while(meis)
{
SDL_Event event;
while (SDL_PollEvent(&event))
{
switch(event.type)
{
	case SDL_QUIT:
menu=0;
break;
	case SDL_KEYDOWN:
if (event.key.keysym.sym==SDLK_RIGHT)
{
quitter=1;
detec.x+=10;
}
if (event.key.keysym.sym==SDLK_LEFT)
{
quitter=1;
detec.x-=10;}
if (event.key.keysym.sym==SDLK_UP)
{
quitter=1;
detec.y-=10;}
if (event.key.keysym.sym==SDLK_DOWN)
{
quitter=1;
detec.y+=10;}
break;
  case SDL_MOUSEMOTION:
break;
	case SDL_MOUSEBUTTONUP:
 			if(event.button.x >=20  && event.button.x <= 59
                   && event.button.y >= 35 && event.button.y <= 72){
 			if(event.button.button == SDL_BUTTON_LEFT)// && i==0)
                   {	
			done=1;
		  	meis=0;
				//i++;
		   }}
	//	else if(event.button.button == SDL_BUTTON_LEFT && i!=0)
			//	{
			//SDL_BlitSurface(Quit,NULL,screen,&posq);
                    //    SDL_Flip(screen);
			//	i--;	}
break;
}
}
}
while(donemdj)
{
SDL_BlitSurface(Mdj,NULL,screen,&positionecran);
SDL_BlitSurface(Return,NULL,screen,&posret);
SDL_BlitSurface(Score,NULL,screen,&poscore);
SDL_BlitSurface(Gold,NULL,screen,&posg);
SDL_BlitSurface(Plus,NULL,screen,&posplus);
SDL_BlitSurface(Facile,NULL,screen,&posfa);
SDL_BlitSurface(Moyen,NULL,screen,&posmo);
SDL_BlitSurface(Difficile,NULL,screen,&posdi);
SDL_Flip(screen);
donemdj=0;
mdj=1;
}
while(mdj)
{
SDL_Event event;
while (SDL_PollEvent(&event))
{
switch(event.type)
{
	case SDL_QUIT:
menu=0;
break;
	case SDL_KEYDOWN:
if (event.key.keysym.sym==SDLK_RIGHT)
{
quitter=1;
detec.x+=10;
}
if (event.key.keysym.sym==SDLK_LEFT)
{
quitter=1;
detec.x-=10;}
if (event.key.keysym.sym==SDLK_UP)
{
quitter=1;
detec.y-=10;}
if (event.key.keysym.sym==SDLK_DOWN)
{
quitter=1;
detec.y+=10;}
break;
  case SDL_MOUSEMOTION:
  x=0, y=0 ;
                //Get the mouse offsets
                x = event.motion.x;
                y = event.motion.y;
	 if((posmo.x+166>x) && (x>posmo.x) && ( 66+posmo.y>y) &&(y>posmo.y))   
                {
                    //SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));//
                   // Hamda = IMG_Load("hamda.png");//
                    SDL_BlitSurface(Moyensel, NULL, screen, &posmosel);
            		SDL_Flip(screen);
                }
		else {
			 SDL_BlitSurface(Moyen,NULL,screen,&posmo);
		        SDL_Flip(screen);
		     }
 if((posfa.x+166>x) && (x>posfa.x) && ( 66+posfa.y>y) &&(y>posfa.y))   
                {
                    //SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));//
                   // Hamda = IMG_Load("hamda.png");//
                    SDL_BlitSurface(Facilesel, NULL, screen, &posfa);
            		SDL_Flip(screen);
                }
		else {
			 SDL_BlitSurface(Facile,NULL,screen,&posfa);
		        SDL_Flip(screen);
		     }
 if((posdi.x+166>x) && (x>posdi.x) && ( 66+posdi.y>y) &&(y>posdi.y))   
                {
                    //SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));//
                   // Hamda = IMG_Load("hamda.png");//
                    SDL_BlitSurface(Difficilesel, NULL, screen, &posdi);
            		SDL_Flip(screen);
                }
		else {
			 SDL_BlitSurface(Difficile,NULL,screen,&posdi);
		        SDL_Flip(screen);
		     }
break;
	case SDL_MOUSEBUTTONUP:
 			if(event.button.x >=20  && event.button.x <= 59
                   && event.button.y >= 35 && event.button.y <= 72){
 			if(event.button.button == SDL_BUTTON_LEFT)// && i==0)
                   {	
			donej=1;
		  	mdj=0;
				//i++;
		   }}
	//	else if(event.button.button == SDL_BUTTON_LEFT && i!=0)
			//	{
			//SDL_BlitSurface(Quit,NULL,screen,&posq);
                    //    SDL_Flip(screen);
			//	i--;	}
break;
}
}
}
while(donereg)
{
SDL_BlitSurface(Reg,NULL,screen,&positionecran);
SDL_BlitSurface(Return,NULL,screen,&posret);
SDL_BlitSurface(Score,NULL,screen,&poscore);
SDL_BlitSurface(Gold,NULL,screen,&posg);
SDL_BlitSurface(Plus,NULL,screen,&posplus);
SDL_BlitSurface(So,NULL,screen,&posso);
SDL_BlitSurface(Sonne,NULL,screen,&possonne);
SDL_Flip(screen);
donereg=0;
reglage=1;
}
while(reglage)
{
SDL_Event event;
while (SDL_PollEvent(&event))
{
switch(event.type)
{
	case SDL_QUIT:
menu=0;
break;
	case SDL_KEYDOWN:
if (event.key.keysym.sym==SDLK_RIGHT)
{
quitter=1;
detec.x+=10;
}
if (event.key.keysym.sym==SDLK_LEFT)
{
quitter=1;
detec.x-=10;}
if (event.key.keysym.sym==SDLK_UP)
{
quitter=1;
detec.y-=10;}
if (event.key.keysym.sym==SDLK_DOWN)
{
quitter=1;
detec.y+=10;}
break;
  case SDL_MOUSEMOTION:

break;
	case SDL_MOUSEBUTTONUP:
 			if(event.button.x >=20  && event.button.x <= 59
                   && event.button.y >= 35 && event.button.y <= 72){
 			if(event.button.button == SDL_BUTTON_LEFT)// && i==0)
                   {	
			done=1;
		  	reglage=0;
				//i++;
		   }}
if(event.button.x >=410 && event.button.x <= 526
                   && event.button.y >= 258 && event.button.y <= 262){
 			if(event.button.button == SDL_BUTTON_LEFT)
			{
			possonne.x=event.motion.x;
			vol=(((x-410)*100)/100);
			Mix_VolumeMusic(vol);
			SDL_Flip(screen);
			}}
	//	else if(event.button.button == SDL_BUTTON_LEFT && i!=0)
			//	{
			//SDL_BlitSurface(Quit,NULL,screen,&posq);
                    //    SDL_Flip(screen);
			//	i--;	}
break;
}
}
}
}
SDL_FreeSurface(image);
SDL_FreeSurface(Ms);
SDL_FreeSurface(Reglage);
SDL_FreeSurface(Credits);
SDL_FreeSurface(Barre);
SDL_FreeSurface(Son);
SDL_FreeSurface(Gold);
SDL_FreeSurface(Plus);
SDL_FreeSurface(Parametre);
SDL_FreeSurface(Aide);
SDL_FreeSurface(Gmail);
SDL_FreeSurface(Fb);
SDL_FreeSurface(Quit);
SDL_FreeSurface(Jouer);
SDL_FreeSurface(detective);
SDL_FreeSurface(Facile);
SDL_FreeSurface(Moyen);
Mix_FreeMusic(music);
Mix_CloseAudio();
TTF_Quit();
SDL_Quit();
return 0;
}
