/*
 * testInterface2.c
 *
 *  Created on: Apr 10, 2011
 *      Author: Mehdi
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "fonctionInterface.h"

int main(int argc, char *argv[]) {
	int quitterJeu, fenetreActive, menuPrincipal, fenetreJeu, menuPause,
			menuSelectionJoueur, pos, click, posPause, nbclick, diffX, diffY,
			jouer_coup, joueur2, clickSelectPlayer;
	SDL_Event event;

	//plateau *p = malloc(sizeof(plateau));
	//plateau p = p_jeu;
	char * fic_sauvegarde = "save.txt";
	int* tab = calloc(sizeof(int), 2);
	int* tab2 = calloc(sizeof(int), 2);
	int tableau[2];
	int tableau2[2];
	int tour_ia = 0;
	joueur j1;
	joueur j2;
	case_plateau c, oldPosition, newPosition, caseSurvole, case_depart,
			case_intermediaire;
	case_plateau *oldCase = malloc(sizeof(case_plateau));
	case_plateau *newCase = malloc(sizeof(case_plateau));
	int* finTour = malloc(sizeof(int));
	int* tourJoueur = malloc(sizeof(int));

	*finTour = 0;
	*tourJoueur = 0;
	clickSelectPlayer = 0;
	nbclick = 0;
	joueur2 = 0;
	quitterJeu = 1;
	menuPrincipal = 1;
	fenetreJeu = 1;
	menuPause = 1;
	menuSelectionJoueur = 1;
	fenetreActive = 0;
	//p_jeu = nouveau_plateau(j1,j2);
	int tour_en_cours = 0;

	SDL_Init(SDL_INIT_VIDEO);
	SDL_WM_SetIcon(SDL_LoadBMP("Images/icon.bmp"), NULL);
	screen = SDL_SetVideoMode(LARGEUR, LONGUEUR, 32,
			SDL_SWSURFACE | SDL_DOUBLEBUF);
	SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 0, 0));

	printf("0) J'entre dans la boucle \n");
	while (quitterJeu) {

		switch (fenetreActive) {

		case 0: //Fenetre Menu principal
			afficher_ecran_depart_neutre(pos);
			while (menuPrincipal) {

				while (SDL_PollEvent(&event)) {
					switch (event.type) {
					case SDL_KEYDOWN:
						switch (event.key.keysym.sym) {
						case SDLK_a:
							afficher_ecran_depart_neutre(0);
							break;
						case SDLK_b:

							menuPrincipal = 0;
							fenetreActive = 1;
							break;
						case SDLK_ESCAPE:
							menuPrincipal = 0;
							fenetreActive = 9;
							break;
						default:
							quitterJeu = 1;
							break;
						}//Fin switch touche choisi

					case SDL_MOUSEMOTION:
						pos = position_souris(event);
						afficher_ecran_depart_neutre(pos);
						break;
						//Fin du cas : la souris bouge
					case SDL_MOUSEBUTTONUP:
						switch (event.button.button) {
						case SDL_BUTTON_LEFT:
							click = clique_souris_menu(event);
							switch (click) {
							case 1:
								// Clique sur commencer partie
								initialiser_partie();
								menuPrincipal = 0;
								menuSelectionJoueur = 1;
								fenetreActive = 3;
								break;
							case 2:
								// Clique sur charger partie
								initialiser_partie();
								charger_partie(fic_sauvegarde);
								menuPrincipal = 0;
								fenetreActive = 1;
								break;
							case 3:
								// Clique sur quitter
								menuPrincipal = 0;
								fenetreActive = 9;
								break;
							default:
								break;
							}//Fin switch click
							break;
						default:
							break;
						}//Fin choix bouton de souris UP
						break;
					}//Fin switch event.type

				}//Fin while PollEvent

			}
			break;

		case 1: //Fenetre Jeu
			initialisation_cases_blanches();
			rafraichir_plateau();
			SDL_Flip(screen);

			while (fenetreJeu) {

				while (SDL_PollEvent(&event) && !partie_terminee()) {

					switch (event.type) {
					case SDL_MOUSEBUTTONUP:
						switch (event.button.button) {
						case SDL_BUTTON_LEFT:

							// ASTUCE : Appuyer sur la touche H affiche les pions jouables
							// Mais ce n est pas necessaire si on sait quoi jouer on peut le jouer directement.

							if (!joueur2) { // Tour Joueur 1

								nbclick = nbclick % 2; // Quel click ?

								if (nbclick == 0) { //Premier click

									if (!tour_en_cours) {
										tour_ia = commencer_tour();
										tour_en_cours = 1;
									}

									if (!tour_ia) {
										tab = clique_souris(event); // Recupère les coordonnees du premier click


										rafraichir_plateau();
										SDL_Flip(screen);

										case_depart = get_case_plateau(tab[0],
												tab[1], p_jeu);

										int click_ok =
												hint_deplacements_possibles_xy(
														tab[0], tab[1]); // Une fois le pion selectionne, cela affiche les deplacements possibles

										printf("Premier click reussi \n");

										if (click_ok) {
											nbclick += 1; // On autorise l'acces au deuxieme click
											control_surbrillance(tab);
										}
									} else { // si c'est l'ia qui a joué
										joueur2 = 1;
										tour_en_cours = 0;
										tour_ia = 0;
									}

									rafraichir_plateau();
									SDL_Flip(screen);
								}

								else {
									if (nbclick == 1) { //Deuxieme click

										tab = clique_souris(event); // Recupère les coordonnees du deuxieme click

										case_intermediaire = get_case_plateau(
												tab[0], tab[1], p_jeu);

										jouer_coup = jouer_coup_xy(
												case_depart.x, case_depart.y,
												case_intermediaire.x,
												case_intermediaire.y); //On joue le coup


										rafraichir_plateau();
										SDL_Flip(screen);

										switch (jouer_coup) {
										case 0:
											joueur2 = 0;
											printf(
													"###########################\nOn garde la main (joueur 1)\n###########################\n");
											break;
										case 1:
											joueur2 = 1;
											printf(
													"###########################\nOn passe au joueur 2 \n###########################\n");
											tour_en_cours = 0;
											break;
										case 2:
											joueur2 = 0;
											printf(
													"###########################\nOn garde la main (joueur 1)\n###########################\n");
											break;
										}
										if (!partie_terminee()) {
											printf("Deuxieme click reussi \n");
											nbclick += 1;
										} else {
											fenetreJeu = 0;
											fenetreActive = 4;
										}
									}
								}

							}

							else {
								if (joueur2) { // Tour Joueur 2

									nbclick = nbclick % 2;

									if (nbclick == 0) { //Premier click
										if (!tour_en_cours) {
											tour_ia = commencer_tour();
											tour_en_cours = 1;
										}

										if (!tour_ia) {
											tab = clique_souris(event); // Recupère les coordonnees du premier click


											rafraichir_plateau();
											SDL_Flip(screen);

											case_depart = get_case_plateau(
													tab[0], tab[1], p_jeu);

											int
													click_ok =
															hint_deplacements_possibles_xy(
																	tab[0],
																	tab[1]);

											printf("Premier click reussi \n");

											if (click_ok) {
												nbclick += 1;
												control_surbrillance(tab);
											}
										} else {
											joueur2 = 0;
											tour_en_cours = 0;
											tour_ia = 0;
										}
										rafraichir_plateau();
										SDL_Flip(screen);
									}

									else {
										if (nbclick == 1) { //Deuxieme click
											tab = clique_souris(event);

											case_intermediaire
													= get_case_plateau(tab[0],
															tab[1], p_jeu);

											jouer_coup = jouer_coup_xy(
													case_depart.x,
													case_depart.y,
													case_intermediaire.x,
													case_intermediaire.y);

											rafraichir_plateau();
											SDL_Flip(screen);

											switch (jouer_coup) {
											case 0:
												joueur2 = 1;
												printf(
														"###########################\nOn garde la main (joueur 2)\n###########################\n");
												break;
											case 1:
												joueur2 = 0;
												printf(
														"###########################\nOn passe au joueur 1 \n###########################\n");
												tour_en_cours = 0;
												break;
											case 2:
												joueur2 = 1;
												printf(
														"###########################\nOn garde la main (joueur 2)\n###########################\n");
												break;
											}

											if (!partie_terminee()) {
												printf(
														"Deuxieme click reussi \n");
												nbclick += 1;
											} else {
												fenetreJeu = 0;
												fenetreActive = 4;
											}
										}
									}

								}
							}

						}
						break;
					case SDL_KEYDOWN:
						switch (event.key.keysym.sym) {
						case SDLK_ESCAPE:
							menuPause = 1;
							fenetreActive = 2;
							fenetreJeu = 0;

							break;
						case SDLK_e:
							fenetreActive = 9;
							fenetreJeu = 0;

							break;
						case SDLK_h:
							hint_pions_jouables();
							rafraichir_plateau();
							SDL_Flip(screen);
							break;
						default:
							quitterJeu = 1;
							break;
						}//Fin choix de la touche
					}//Fin switch.type
				}//Fin PollEvent

			}
			break;

		case 2: //Fentre Menu Pause
			afficher_ecran_pause(posPause);
			while (menuPause) {

				while (SDL_PollEvent(&event)) {
					switch (event.type) {
					case SDL_KEYDOWN:
						switch (event.key.keysym.sym) {
						case SDLK_ESCAPE:
							menuPause = 0;
							fenetreActive = 9;
							break;
						default:
							break;

						}//Fin switch Keydown
					case SDL_MOUSEMOTION:
						posPause = position_souris_pause(event);
						afficher_ecran_pause(posPause);
					case SDL_MOUSEBUTTONUP:
						switch (event.button.button) {
						case SDL_BUTTON_LEFT:
							click = clique_souris_pause(event);
							printf("click souris = %d \n", click);
							switch (click) {
							case 1:
								sauvegarder_partie(fic_sauvegarde);
								menuPause = 0;
								fenetreActive = 9;
								break;
							case 2:
								fenetreJeu = 1;
								menuPause = 0;
								fenetreActive = 1;

								break;
							case 3:
								menuPause = 0;
								fenetreActive = 9;
								break;
							default:
								break;
							}//Fin switch click

							break;
						}// Fin switch choix click
					default:
						break;
					}//Fin switch event.type

				}
			}
			break;

		case 3: // Choix joueur
			afficher_ecran_choix_joueur();
			while (menuSelectionJoueur) {

				while (SDL_PollEvent(&event)) {

					switch (event.type) {
					case SDL_KEYDOWN:
						switch (event.key.keysym.sym) {
						case SDLK_ESCAPE:
							menuSelectionJoueur = 0;
							menuPrincipal = 1;
							fenetreActive = 0;
							break;

						default:
							break;

						}//Fin switch Keydown


					case SDL_MOUSEBUTTONUP:
						switch (event.button.button) {
						case SDL_BUTTON_LEFT:
							clickSelectPlayer = clique_souris_choix_joueur(
									event);
							afficher_ecran_choix_joueur();

							switch (clickSelectPlayer) {
							case 0: //CLique Suivant
								menuSelectionJoueur = 0;
								fenetreActive = 1;
								break;
							case 1: //Clique Precedent
								menuSelectionJoueur = 0;
								menuPrincipal = 1;
								fenetreActive = 0;
								break;
							default:
								break;
							}
							break;
						}// Fin switch choix click
					default:
						break;
					}//Fin switch event.type

				}
			}
			break;

		case 4: // Fin de partie
			if (partie_terminee() == 1) {
				afficher_ecran_blancs_gagnent();
			} else {
				afficher_ecran_noirs_gagnent();
			}
			while (SDL_PollEvent(&event)) {

				switch (event.type) {
				case SDL_KEYDOWN:
					switch (event.key.keysym.sym) {
					case SDLK_ESCAPE:
						fenetreActive = 9;
						break;

					default:
						break;

					}//Fin switch Keydown
				}
			}
			break;

		default:
			printf("10) Je sors de la \n");
			quitterJeu = 0;
			break;
		}
	}

	printf("11) Fin du test \n");

	free(tab);
	free(tab2);
	SDL_FreeSurface(screen);
	SDL_Quit();

	return 0;
}
