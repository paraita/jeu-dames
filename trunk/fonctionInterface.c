/*
 * fonctionInerface.c
 *
 *  Created on: Mar 22, 2011
 *      Author: Mehdi
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "fonctionInterface.h"




void rafraichir_plateau(){
	int i;


	carre_fonce.surface = SDL_LoadBMP("Images/marbre_noir.bmp");
	carre_clair.surface = SDL_LoadBMP("Images/marbre.bmp");
	carre_surbrillance.surface = SDL_LoadBMP("Images/marbre_noir_selectionne.bmp");


	for(i=1; i <=50; i++){

		if(p_jeu.cases[i].en_surbrillance == 0){
			carre_fonce.position.x = (p_jeu.cases[i].x - 1) * TAILLECARRE;
			carre_fonce.position.y = (p_jeu.cases[i].y - 1) * TAILLECARRE;
			SDL_BlitSurface(carre_fonce.surface, NULL, screen, &carre_fonce.position);
			pion_clair.position.x = (p_jeu.cases[i].x - 1) * TAILLECARRE;
			pion_clair.position.y = (p_jeu.cases[i].y - 1) * TAILLECARRE;

			carre_fonce.position.x = (p_jeu.cases[i].x - 1) * TAILLECARRE;
			carre_fonce.position.y = (p_jeu.cases[i].y - 1) * TAILLECARRE;
			SDL_BlitSurface(carre_fonce.surface, NULL, screen, &carre_fonce.position);
			pion_fonce.position.x = (p_jeu.cases[i].x - 1) * TAILLECARRE;
			pion_fonce.position.y = (p_jeu.cases[i].y - 1) * TAILLECARRE;
		}
		else{
			carre_surbrillance.position.x = (p_jeu.cases[i].x - 1) * TAILLECARRE;
			carre_surbrillance.position.y = (p_jeu.cases[i].y - 1) * TAILLECARRE;
			SDL_BlitSurface(carre_surbrillance.surface, NULL, screen, &carre_surbrillance.position);
			pion_clair.position.x = (p_jeu.cases[i].x - 1) * TAILLECARRE;
			pion_clair.position.y = (p_jeu.cases[i].y - 1) * TAILLECARRE;

			carre_surbrillance.position.x = (p_jeu.cases[i].x - 1) * TAILLECARRE;
			carre_surbrillance.position.y = (p_jeu.cases[i].y - 1) * TAILLECARRE;
			SDL_BlitSurface(carre_surbrillance.surface, NULL, screen, &carre_surbrillance.position);
			pion_fonce.position.x = (p_jeu.cases[i].x - 1) * TAILLECARRE;
			pion_fonce.position.y = (p_jeu.cases[i].y - 1) * TAILLECARRE;
		}

		if(p_jeu.cases[i].est_libre == 0){ //SI la case n'est pas libre
			if(p_jeu.cases[i].pion.couleur == blanc){ // SI le pion est blanc
				if(p_jeu.cases[i].pion.est_dame == 0){ // SI ce n'est pas une dame
					if(p_jeu.cases[i].pion.en_surbrillance == 0){ // SI il n'est pas selectionne
						pion_clair.surface = SDL_LoadBMP("Images/pion_clair.bmp");
						SDL_SetColorKey(pion_clair.surface, SDL_SRCCOLORKEY, SDL_MapRGB(pion_clair.surface->format, 241, 241, 241));
						SDL_BlitSurface(pion_clair.surface, NULL, screen, &pion_clair.position);
					}
					else{
						pion_clair.surface = SDL_LoadBMP("Images/pion_clair_selectionne.bmp");
						SDL_SetColorKey(pion_clair.surface, SDL_SRCCOLORKEY, SDL_MapRGB(pion_clair.surface->format, 241, 241, 241));
						SDL_BlitSurface(pion_clair.surface, NULL, screen, &pion_clair.position);
					}
				}
				else{ // SI c'est une dame
					if(p_jeu.cases[i].pion.en_surbrillance == 0){ // SI il n'est pas selectionne
						pion_clair.surface = SDL_LoadBMP("Images/pion_clair_dame.bmp");
						SDL_SetColorKey(pion_clair.surface, SDL_SRCCOLORKEY, SDL_MapRGB(pion_clair.surface->format, 241, 241, 241));
						SDL_BlitSurface(pion_clair.surface, NULL, screen, &pion_clair.position);
					}
					else{
						pion_clair.surface = SDL_LoadBMP("Images/pion_clair_dame_selectionne.bmp");
						SDL_SetColorKey(pion_clair.surface, SDL_SRCCOLORKEY, SDL_MapRGB(pion_clair.surface->format, 241, 241, 241));
						SDL_BlitSurface(pion_clair.surface, NULL, screen, &pion_clair.position);
					}
				}
			}


			if(p_jeu.cases[i].pion.couleur == noir){
				if(p_jeu.cases[i].pion.est_dame == 0){
					if(p_jeu.cases[i].pion.en_surbrillance == 0){
						pion_fonce.surface = SDL_LoadBMP("Images/pion_fonce.bmp");
						SDL_SetColorKey(pion_fonce.surface, SDL_SRCCOLORKEY, SDL_MapRGB(pion_fonce.surface->format, 241, 241, 241));
						SDL_BlitSurface(pion_fonce.surface, NULL, screen, &pion_fonce.position);
					}
					else{
						pion_fonce.surface = SDL_LoadBMP("Images/pion_fonce_selectionne.bmp");
						SDL_SetColorKey(pion_fonce.surface, SDL_SRCCOLORKEY, SDL_MapRGB(pion_fonce.surface->format, 241, 241, 241));
						SDL_BlitSurface(pion_fonce.surface, NULL, screen, &pion_fonce.position);
					}
				}

				else{
					if(p_jeu.cases[i].pion.en_surbrillance == 0){
						pion_fonce.surface = SDL_LoadBMP("Images/pion_fonce_dame.bmp");
						SDL_SetColorKey(pion_fonce.surface, SDL_SRCCOLORKEY, SDL_MapRGB(pion_fonce.surface->format, 241, 241, 241));
						SDL_BlitSurface(pion_fonce.surface, NULL, screen, &pion_fonce.position);
					}
					else{
						pion_fonce.surface = SDL_LoadBMP("Images/pion_fonce_dame_selectionne.bmp");
						SDL_SetColorKey(pion_fonce.surface, SDL_SRCCOLORKEY, SDL_MapRGB(pion_fonce.surface->format, 241, 241, 241));
						SDL_BlitSurface(pion_fonce.surface, NULL, screen, &pion_fonce.position);
					}
				}
			}

		} //Fin non libre


	}
}


void afficher_ecran_depart_neutre(int choix){
	SDL_Surface *ecran_depart;
	SDL_Rect position_ecran;
	position_ecran.x = 0;
	position_ecran.y = 0;
	switch(choix){
		case 1:

			ecran_depart = SDL_LoadBMP("Images/demarrage_Commencer.bmp");
			SDL_BlitSurface(ecran_depart,NULL,screen,&position_ecran);
			SDL_Flip(screen);
			break;
		case 2:

			ecran_depart = SDL_LoadBMP("Images/demarrage_Charger.bmp");
			SDL_BlitSurface(ecran_depart,NULL,screen,&position_ecran);
			SDL_Flip(screen);
			break;
		case 3:

			ecran_depart = SDL_LoadBMP("Images/demarrage_Quitter.bmp");
			SDL_BlitSurface(ecran_depart,NULL,screen,&position_ecran);
			SDL_Flip(screen);
			break;
		default:

			ecran_depart = SDL_LoadBMP("Images/demarrage_neutre.bmp");
			SDL_BlitSurface(ecran_depart,NULL,screen,&position_ecran);
			SDL_Flip(screen);
			break;
	}



}

void afficher_ecran_choix_joueur(){
	SDL_Surface *ecran_joueur;
	SDL_Rect position_ecran_joueur;
	position_ecran_joueur.x = 0;
	position_ecran_joueur.y = 0;
	int choix;
	choix = tableauChoix[0] + tableauChoix[1] + tableauChoix[2] + tableauChoix[3];
	switch(choix){
	case 1:
		ecran_joueur = SDL_LoadBMP("Images/menu_selection_neutre_1.bmp");
		SDL_BlitSurface(ecran_joueur,NULL,screen,&position_ecran_joueur);
		SDL_Flip(screen);
		break;

	case 2:
		ecran_joueur = SDL_LoadBMP("Images/menu_selection_neutre_2.bmp");
		SDL_BlitSurface(ecran_joueur,NULL,screen,&position_ecran_joueur);
		SDL_Flip(screen);
		break;

	case 4:
		ecran_joueur = SDL_LoadBMP("Images/menu_selection_neutre_1_1.bmp");
		SDL_BlitSurface(ecran_joueur,NULL,screen,&position_ecran_joueur);
		SDL_Flip(screen);
		break;

	case 5:
		ecran_joueur = SDL_LoadBMP("Images/menu_selection_neutre_2_1.bmp");
		SDL_BlitSurface(ecran_joueur,NULL,screen,&position_ecran_joueur);
		SDL_Flip(screen);
		break;

	case 6:
		ecran_joueur = SDL_LoadBMP("Images/menu_selection_neutre_1_2.bmp");
		SDL_BlitSurface(ecran_joueur,NULL,screen,&position_ecran_joueur);
		SDL_Flip(screen);
		break;

	case 7:
		ecran_joueur = SDL_LoadBMP("Images/menu_selection_neutre_2_2.bmp");
		SDL_BlitSurface(ecran_joueur,NULL,screen,&position_ecran_joueur);
		SDL_Flip(screen);
		break;

	default :
		ecran_joueur = SDL_LoadBMP("Images/menu_selection_neutre.bmp");
		SDL_BlitSurface(ecran_joueur,NULL,screen,&position_ecran_joueur);
		SDL_Flip(screen);
		break;
	}
}

void afficher_ecran_pause(int choix){

	SDL_Surface *ecran_pause;
	SDL_Rect position_ecran;
	position_ecran.x = 0;
	position_ecran.y = 0;
	switch(choix){

	case 1:
		ecran_pause = SDL_LoadBMP("Images/pause_sauvegarder.bmp");
		SDL_BlitSurface(ecran_pause,NULL,screen,&position_ecran);
		SDL_Flip(screen);
		break;

	case 2:
		ecran_pause = SDL_LoadBMP("Images/pause_retour.bmp");
		SDL_BlitSurface(ecran_pause,NULL,screen,&position_ecran);
		SDL_Flip(screen);
		break;

	case 3:
		ecran_pause = SDL_LoadBMP("Images/pause_quitter.bmp");
		SDL_BlitSurface(ecran_pause,NULL,screen,&position_ecran);
		SDL_Flip(screen);
		break;

	default:
		ecran_pause = SDL_LoadBMP("Images/pause_neutre.bmp");
		SDL_BlitSurface(ecran_pause,NULL,screen,&position_ecran);
		SDL_Flip(screen);
		break;
	}

}
void afficher_ecran_blancs_gagnent(){
	SDL_Surface *ecran_blancs_gagnent;
	SDL_Rect position_ecran;
	position_ecran.x = 0;
	position_ecran.y = 0;

	ecran_blancs_gagnent = SDL_LoadBMP("Images/blancs_gagnent.bmp");
	SDL_BlitSurface(ecran_blancs_gagnent,NULL,screen,&position_ecran);
	SDL_Flip(screen);
}

void afficher_ecran_noirs_gagnent(){
	SDL_Surface *ecran_noirs_gagnent;
	SDL_Rect position_ecran;
	position_ecran.x = 0;
	position_ecran.y = 0;

	ecran_noirs_gagnent = SDL_LoadBMP("Images/noirs_gagnent.bmp");
	SDL_BlitSurface(ecran_noirs_gagnent,NULL,screen,&position_ecran);
	SDL_Flip(screen);
}


int* clique_souris(SDL_Event evenement){
	int* tableau = calloc(sizeof(int), 4); // A changer
	int xt,yt;
	SDL_Rect positionSouris;
	positionSouris.x = evenement.button.x;
	positionSouris.y = evenement.button.y;
	xt = positionSouris.x / 80 + 1;
	yt = positionSouris.y / 80 + 1;

	tableau[0] = xt;
	tableau[1] = yt;
	tableau[2] = positionSouris.x; // A virer
	tableau[3] = positionSouris.y;
	return tableau;
}

int position_souris(SDL_Event evenement){
	evenement.motion.x;
	evenement.motion.y;

	if(evenement.motion.x > 142 && evenement.motion.x < 670 && evenement.motion.y > 347 && evenement.motion.y < 380 ){
		return 1;
	}
	else{
		if(evenement.motion.x > 173 && evenement.motion.x < 640 && evenement.motion.y > 449 && evenement.motion.y < 480 ){
			return 2;
		}
		else{
			if(evenement.motion.x > 310 && evenement.motion.x < 500 && evenement.motion.y > 548 && evenement.motion.y < 580 ){
				return 3;
			}
			else{
				return 0;
			}
		}
	}
}

int clique_souris_choix_joueur(SDL_Event evenement){
	evenement.button.x;
	evenement.button.y;
	int choix = 0;
	choix = tableauChoix[0] + tableauChoix[1] + tableauChoix[2] + tableauChoix[3];
	if(evenement.button.x > 340 && evenement.button.x < 410 && evenement.button.y > 340 && evenement.button.y < 410){
		tableauChoix[1] = 0;
		tableauChoix[0] = 1;
		p_jeu.joueur1.est_humain = 1;


	}//Fin if case 1
	else{

		if(evenement.button.x > 510 && evenement.button.x < 610 && evenement.button.y > 350 && evenement.button.y < 410){
			tableauChoix[0] = 0;
			tableauChoix[1] = 2;
			p_jeu.joueur1.est_humain = 0;

		}//Fin if case 2
		else{
			if(evenement.button.x > 340 && evenement.button.x < 410 && evenement.button.y > 460 && evenement.button.y < 530){
				tableauChoix[3] = 0;
				tableauChoix[2] = 3;
				p_jeu.joueur2.est_humain = 1;

				}//Fin if case 3
				else{
					if(evenement.button.x > 510 && evenement.button.x < 610 && evenement.button.y > 480 && evenement.button.y < 540){
						tableauChoix[2] = 0;
						tableauChoix[3] = 5;
						p_jeu.joueur2.est_humain = 0;

					}//Fin if case 4

				}

		}
	}
	if(evenement.button.x > 50 && evenement.button.x < 250 && evenement.button.y > 630 && evenement.button.y < 670){
		return 1;
	}//Click Precedent

	if(choix >= 4 && choix <= 7){ //Controle qu'on a bien fait 2 choix

		if(evenement.button.x > 610 && evenement.button.x < 770 && evenement.button.y > 630 && evenement.button.y < 670){
			return 0;
		}//Click suivant

	}


}


int clique_souris_menu(SDL_Event evenement){
	evenement.button.x;
	evenement.button.y;

	if(evenement.button.x > 142 && evenement.button.x < 670 && evenement.button.y > 347 && evenement.button.y < 380 ){
		return 1;
	}
	else{
		if(evenement.button.x > 173 && evenement.button.x < 640 && evenement.button.y > 449 && evenement.button.y < 480 ){
			return 2;
		}
		else{
			if(evenement.button.x > 310 && evenement.button.x < 500 && evenement.button.y > 548 && evenement.button.y < 580 ){
				return 3;
			}
			else{
				return 0;
			}
		}
	}
}

int position_souris_pause(SDL_Event evenement){
	evenement.motion.x;
	evenement.motion.y;

	if(evenement.motion.x > 251 && evenement.motion.x < 540 && evenement.motion.y > 321 && evenement.motion.y < 356 ){
		return 1;
	}
	else{
		if(evenement.motion.x > 180 && evenement.motion.x < 624 && evenement.motion.y > 397 && evenement.motion.y < 429 ){
			return 2;
		}
		else{
			if(evenement.motion.x > 305 && evenement.motion.x < 494 && evenement.motion.y > 479 && evenement.motion.y < 510 ){
				return 3;
			}
			else{
				return 0;
			}
		}
	}
}

int clique_souris_pause(SDL_Event evenement){
	evenement.button.x;
	evenement.button.y;

	if(evenement.button.x > 251 && evenement.button.x < 540 && evenement.button.y > 321 && evenement.button.y < 356 ){
		return 1;
	}
	else{
		if(evenement.button.x > 180 && evenement.button.x < 624 && evenement.button.y > 397 && evenement.button.y < 429 ){
			return 2;
		}
		else{
			if(evenement.button.x > 305 && evenement.button.x < 494 && evenement.button.y > 479 && evenement.button.y < 510 ){
				return 3;
			}
			else{
				return 0;
			}
		}
	}
}
void initialisation_cases_blanches(){
	int i,j;
	carre_clair.surface = SDL_LoadBMP("Images/marbre.bmp");
	carre_clair.position.x = 0;
	carre_clair.position.y = 0;

	for(i = 0; i<=4; i++){
		for(j=0;j<=4;j++){
			SDL_BlitSurface(carre_clair.surface, NULL, screen, &carre_clair.position);
			carre_clair.position.x += 2 * TAILLECARRE;

		}
		carre_clair.position.y += TAILLECARRE;
		carre_clair.position.x = TAILLECARRE;

		for(j=0;j<=4;j++){
			SDL_BlitSurface(carre_clair.surface, NULL, screen, &carre_clair.position);
			carre_clair.position.x += 2 * TAILLECARRE;

		}
		carre_clair.position.y += TAILLECARRE;
		carre_clair.position.x = 0;

	}

}

void control_manger_pion(case_plateau oldPosition, case_plateau newPosition){
	int diffX, diffY;
	case_plateau caseSurvole;
	diffX = oldPosition.x - newPosition.x;
	diffY = oldPosition.y - newPosition.y;

	switch(diffX){
		case 2: //On va a gauche
			switch(diffY){
			case 2: //On va en haut a gauche
				caseSurvole = get_case_plateau( newPosition.x + 1, newPosition.y + 1, p_jeu);
				printf("Case survole :");
				print_case(caseSurvole);
				plateau_prendre_pion(caseSurvole.notation_officielle, &p_jeu);
				break;
			case -2: //On va en bas a gauche
				caseSurvole = get_case_plateau( newPosition.x + 1, newPosition.y - 1, p_jeu);
				printf("Case survole :");
				print_case(caseSurvole);
				plateau_prendre_pion(caseSurvole.notation_officielle, &p_jeu);
				break;
			default: //default
				printf("mouvement interdit \n");
				break;
			}
			break;

		case -2: //On va a droite
			switch(diffY){
			case 2: //On va en haut a droite
				caseSurvole = get_case_plateau( newPosition.x - 1, newPosition.y + 1, p_jeu);
				printf("Case survole :");
				print_case(caseSurvole);
				plateau_prendre_pion(caseSurvole.notation_officielle, &p_jeu);
				break;
			case -2: //On va en bas a droite
				caseSurvole = get_case_plateau( newPosition.x - 1, newPosition.y - 1, p_jeu);
				printf("Case survole :");
				print_case(caseSurvole);
				plateau_prendre_pion(caseSurvole.notation_officielle, &p_jeu);
				break;
			default:
				printf("mouvement interdit \n");
				break;
			}
			break;

		default:
			printf("mouvement interdit \n");
			break;
		}


}

case_plateau control_surbrillance(int *tab){
	case_plateau c;
	c = get_case_plateau(tab[0], tab[1], p_jeu);
	if(c.pion.couleur == p_jeu.tour.couleur){
		set_pion_en_surbrillance(c.notation_officielle, &p_jeu);
	}
	else{

	}
	return c;
}

case_plateau control_premier_click(SDL_Event event, int *tab, plateau *p, case_plateau *oldCase){
	case_plateau caseSelectionne;
	joueur joueurEnCours;
	joueurEnCours = p->tour;
	caseSelectionne = get_case_plateau(tab[0], tab[1],*p);


	if(caseSelectionne.est_libre == 0){ //Si elle n'est pas libre
		if(caseSelectionne.pion.couleur == joueurEnCours.couleur){ //Si couleurPion correspond au joueur en cours
			*oldCase = caseSelectionne;
			//caseSelectionne = control_surbrillance(tab, p);
			printf("premier click reussi : tab[0] = %d tab[1] = %d \n", tab[0], tab[1]);
		}//FinSi couleurPion correspond au joueur en cours
	}//FinSi elle n'est pas libre
	return caseSelectionne;
}

case_plateau control_deuxieme_click(SDL_Event event, int *tab, plateau *p, case_plateau *newCase, case_plateau *oldCase){
	case_plateau caseSelectionne;
	case_plateau caseCoup;


	caseSelectionne = get_case_plateau(tab[0], tab[1], *p);

	if(caseSelectionne.est_libre){ //Si la case est libre
		//Si la case selectionne correspond a une des cases du tableau des coups possibles
		*newCase = caseSelectionne;
		plateau_deplacer_pion(oldCase->notation_officielle,newCase->notation_officielle, p);
		printf("deuxieme click reussi \n");



	} //FinSi la case est libre

	return caseSelectionne;
}

void initialisation_tableau_choix(){
	tableauChoix[0] = 0;
	tableauChoix[1] = 0;
	tableauChoix[2] = 0;
	tableauChoix[3] = 0;
}
