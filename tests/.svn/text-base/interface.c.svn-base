/*
 * interface.c
 *
 *  Created on: Mar 22, 2011
 *      Author: Mehdi
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../trunk/fonctionInterface.h"


int main(int argc, char *argv[]){

	/*Initialisation des Variables*/
	int i,j;

	Carre_fonce *carre_fonce = malloc(sizeof(Carre_fonce));
	Carre_clair *carre_clair = malloc(sizeof(Carre_clair));
	Pion_clair *pion_clair = malloc(sizeof(Pion_clair));
	Pion_fonce *pion_fonce = malloc(sizeof(Pion_fonce));

	SDL_Event event;
	SDL_Surface *screen;
	int boucle = 1;

	/*Initialisation graphique*/
	SDL_Init(SDL_INIT_VIDEO);
	screen = SDL_SetVideoMode(LARGEUR,LONGUEUR, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);

	SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 0, 0));

	/*Depart*/
	initialisationPlateau(carre_clair,carre_fonce,screen);
	initialisationPion(pion_clair,pion_fonce,screen);

	SDL_Flip(screen);
	/*Boucle principal*/
	while(boucle){
		while(SDL_PollEvent(&event)){
			switch(event.type){
			case SDL_KEYDOWN:
				switch(event.key.keysym.sym){
					case SDLK_ESCAPE:
						boucle = 0;
						break;
					default :
						break;
				}
				default :
					break;
			}
		}
	}


	SDL_FreeSurface(carre_clair->surface);
	SDL_FreeSurface(carre_fonce->surface);
	SDL_Quit();

	return 0;
}
