/**
 * \file fonctionInterface.h
 *
 *  \author Mrah Mehdi
 *
 *  \brief Implémentation de fonctionnalités pour l'interface
 */

#include "constantes.h"
#include "moteur.h"

#ifndef FONCTIONINTERFACE_H_
#define FONCTIONINTERFACE_H_

/** Surface : marbre noir*/
Carre_fonce carre_fonce;

/** Surface : marbre blanc*/
Carre_clair carre_clair;

/** Surface : marbre noir en surbrillance*/
Carre_clair carre_surbrillance;

/** Pion : blanc*/
Pion_clair pion_clair;

/** Pion : noir*/
Pion_fonce pion_fonce;

/** Surface principal*/
SDL_Surface *screen;

int tableauChoix[4];
/**
 * \fn void rafraichir_plateau()
 * \brief Rafraichit le plateau aprés une action
 */
void rafraichir_plateau();

/**
 * \fn void afficher_ecran_depart_neutre(int choix)
 * \brief Affiche le menu de depart
 * \param choix Represente le choix dans le menu depart.
 */
void afficher_ecran_depart_neutre(int choix);

/**
 * \fn void afficher_ecran_depart_neutre(int choix)
 * \brief Affiche le menu pause
 * \param choix Represente le choix dans le menu pause.
 */
void afficher_ecran_pause(int choix);

/**
 * \fn void afficher_ecran_choix_joueur()
 * \brief Affiche le menu de choix IA/Joueur
 */
void afficher_ecran_choix_joueur();

/**
 * \fn void afficher_ecran_noirs_gagnent()
 * \brief Affiche l'ecran de fin de partie, les noirs gagnent
 */
void afficher_ecran_noirs_gagnent();

/**
 * \fn void afficher_ecran_blancs_gagnent()
 * \brief Affiche l'ecran de fin de partie, les blancs gagnent
 */
void afficher_ecran_blancs_gagnent();

/**
 * \fn int clique_souris_choix_joueur(SDL_Event evenement)
 * \brief Retourne la position de la souris après un clique dans le menu choix IA/Joueur
 * \return int Un entier representant le choix du joueur.
 */
int clique_souris_choix_joueur(SDL_Event evenement);

/**
 * \fn int* clique_souris(SDL_Event evenement)
 * \brief Retourne la position de la souris après un clique
 * \return int* Un tableau contenant la position x et y du clique
 */
int* clique_souris(SDL_Event evenement);

/**
 * \fn void initialisation_cases_blanches()
 * \brief Initialise les cases blanches
 */
void initialisation_cases_blanches();

/**
 * \fn int position_souris(SDL_Event evenement)
 * \brief Calcule la position de la souris a chaque mouvement
 * \return int Un entier representant une position dans le menu.
 */
int position_souris(SDL_Event evenement);
/**
 * \fn int position_souris(SDL_Event evenement)
 * \brief Calcule la position de la souris a chaque mouvement
 * \return int Un entier representant une position dans le menu pause.
 */
int position_souris_pause(SDL_Event evenement);
/**
 * \fn int position_souris(SDL_Event evenement)
 * \brief Calcule la position de la souris a chaque clique dans le menu principal.
 * \return int Un entier representant un choix dans le menu principal.
 */
int clique_souris_menu(SDL_Event evenement);
/**
 * \fn int position_souris(SDL_Event evenement)
 * \brief Calcule la position de la souris a chaque mouvement
 * \return int Un entier representant un choix dans le menu pause.
 */
int clique_souris_pause(SDL_Event evenement);


void control_manger_pion(case_plateau oldPosition, case_plateau newPosition);

/**
 * \fn case_plateau control_surbrillance(int *tab, plateau *p)
 * \brief Met en surbrillance un pion
 * \param tab Tableau contenant les coordonnees du click
 * \param p Plateau courant
 * \return case_plateau La case contenant le pion en surbrillance
 * \author Mehdi M'rah
 */
case_plateau control_surbrillance(int *tab);

/**
 * \fn case_plateau control_premier_click(SDL_Event event, int *tab, plateau *p, case_plateau *oldCase)
 * \brief Gere le premier click qui s'occupe uniquement de la selection du pion a jouer
 * \param tab Tableau contenant les coordonnees du click
 * \param oldCase la case de depart
 * \return case_plateau La case contenant le pion selectionne
 * \author Mehdi M'rah
 */
case_plateau control_premier_click(SDL_Event event, int *tab, plateau *p, case_plateau *oldCase);

/**
 * \fn case_plateau control_deuxieme_click(SDL_Event event, int *tab, plateau *p, case_plateau *newCase, case_plateau *oldCase, int *finTour)
 * \brief Gere le deuxieme click qui s'occupe uniquement de la selection de la case a jouer
 * \param tab Tableau contenant les coordonnees du click
 * \param oldCase La case de depart
 * \param newCase La case d'arrive
 * \param finTour Gere le tour
 * \return case_plateau La case contenant le pion selectionne
 * \author Mehdi M'rah
 */
case_plateau control_deuxieme_click(SDL_Event event, int *tab, plateau *p, case_plateau *newCase, case_plateau *oldCase);

#endif /* FONCTIONINTERFACE_H_ */
