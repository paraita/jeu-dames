/**
 * 	\file moteur.h
 *	\brief Le moteur de jeu.
 *	Il permet de gérer une partie, 1 ou 2 joueurs, fait jouer l'IA, fournit une aide au joueur.
 *  \author Mehdi M'rah
 *  \author Bastien Auda
 */
#include <stdio.h>
#include <stdlib.h>
#include "min-max.h"

/** Le plateau de jeu qui sera utilisé tout au long de la partie. (Ne pas utiliser en dehors de moteur.c, utilisez ::get_plateau()) */
plateau p_jeu;

/**
 * void initialiser_partie();
 * \brief Initialise une nouvelle partie, par défaut une partie 2 joueurs, le joueur pourra ensuite être piloté par l'IA en changeant son type grâce à la fonction ::set_joueur_est_humain.
 * \author Mehdi M'rah
 */
void initialiser_partie();

/**
 * 	\fn void set_joueur_est_humain(couleur_pion couleur, int boolean);
 * 	\brief Change le type humain ou IA du joueur.
 * 	\param couleur La couleur du joueur pour lequel on doit changer le type.
 * 	\param boolean Vrai si le joueur est humain, faux sinon.
 * 	\author Mehdi M'rah
 */
void set_joueur_est_humain(couleur_pion couleur, int boolean);


/**
 *	\fn plateau get_plateau();
 *	\brief Renvoie le plateau de la partie pour le consulter.
 *	\author Mehdi M'rah
 */
plateau get_plateau();

/**
 * 	\fn int sauvegarder_partie(char * filename);
 * 	\brief Sauvegarde l'état courant de la partie.
 * 	\param filename Le chemin vers le fichier de sauvegarde.
 * 	\return Vrai si la sauvegarde s'est bien effectuée, faux si un problème est survenu.
 * 	\author Mehdi M'rah
 */
int sauvegarder_partie(char * filename);

/**
 * 	\fn int charger_partie(char * filename);
 * 	\brief Charge une partie depuis le disque.
 * 	\param filename Le chemin vers le fichier à charger.
 * 	\return Vrai si le chargement s'est bien déroulé, faux sinon.
 * 	\author Mehdi M'rah
 */
int charger_partie(char * filename);

/**
 * 	\fn int jouer_coup(int depart, int arrivee);
 * 	\brief Joue le coup pour le joueur courant.
 * 	\param depart La case de départ du coup.
 * 	\param arrivee La case d'arrivée du coup.
 * 	\return \li 0 si le coup est invalide.
 * 			\li 1 si le coup est valide et terminé.
 * 			\li 2 si le mouvement fait partie d'un coup valide, on attend que le joueur termine son coup par un nouvel appel à cette fonction ::jouer_coup.
 * 	\author Bastien Auda
 */
int jouer_coup(int depart, int arrivee);

/**
 * 	\fn int jouer_coup(int x1, int y1, int x2, int y2);
 * 	\brief Identique à ::jouer_coup(int depart, int arrivee) mais prends les coordonnées (x,y) de la case.
 */
int jouer_coup_xy(int x1, int y1, int x2, int y2);

/**
 * 	\fn void jouer_tour_ia();
 * 	\brief Fait jouer un tour à l'IA.
 * 	\author Bastien Auda
 */
void jouer_tour_ia();

/**
 * 	\fn void set_difficulte(int i);
 * 	\brief Joue sur la profondeur d'évaluation du min-max.
 * 	\param i La profondeur d'évaluation.
 * 	\author Bastien Auda
 */
void set_difficulte(int i);

/**
 * 	\fn int commencer_tour();
 * 	\brief Débute un nouveau tour de jeu, fait jouer l'IA si c'est à elle de jouer, attend un coup humain sinon.
 * 	\return Faux si on attend q'un humain joue, vrai si l'IA à joué et qu'on doit relancer immédiatement un nouveau tour.
 * 	\author Bastien Auda
 */
int commencer_tour();

/**
 * \fn void hint_pions_jouables();
 * \brief Met en surbrillance les pions qui permettent un déplacement valide pour ce tour.
 * \author Bastien Auda
 */
void hint_pions_jouables();

/**
 * 	\fn int hint_deplacements_possibles(int c);
 * 	\brief Met en surbrillance les déplacements possibles partant d'une case donnée.
 * 	\param c Notation officielle de la case de départ.
 * 	\return Vrai si le pion séléctionné fait partie d'un coup authorisé.
 * 	\author Bastien Auda
 */
int hint_deplacements_possibles(int c);

/**
 * 	\fn int hint_deplacements_possibles_xy(int x,int y);
 * 	\brief Identique à ::hint_deplacements_possibles(int c) mais prends les coordonnées (x,y) de la case.
 */
int hint_deplacements_possibles_xy(int x,int y);

/**
 * \fn void hint_meilleur_coup();
 * \brief Met en surbrillance le meilleur coup à jouer en utilisant l'IA.
 * \author Mehdi M'rah
 */
void hint_meilleur_coup();

/**
 * \fn int partie_terminee();
 * \return Renvoie Faux si la partie n'est pas terminée, la couleur gagnante + 1 sinon.
 */
int partie_terminee();
