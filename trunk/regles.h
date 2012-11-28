/**
 * 	\file regles.h
 * 	\brief module des regles et d'enumeration des coups.
 *	\author Paraita Wohler
 */
/* ----------------------------------------------- */

#include "plateau.h"

/**
 * \fn coup* coupsPossibles(const case_plateau c, const plateau p)
 * \brief retourne le tableau des coups possible pour un coup donné.
 *
 * \param c La case qui contient le pion de la recherche.
 * \param p la plateau courant.
 */
coup* coupsPossibles(const case_plateau c, const plateau p);


/**
 * \fn coup* getCoups(const joueur j, const plateau p)
 * \brief retourne le tableau des coups possible pour le joueur donné.
 *
 * \param j le joueur dont on chercher tout les coups
 * \param p la plateau courant.
 */
coup* getCoups(const joueur j, const plateau p);


/**
 * \fn coup* getCoupsMax(const coup cp)
 * \brief retourne les coups qui ont le max de prises possible.
 *
 * \param cp le tableau de tout les coups possibles
 */
coup* getCoupsMax(const coup *cp);


/**
 * \fn coup* get_deplacements(const case_plateau c, const plateau p)
 * \brief retourne les deplacements possibles du pion de la case donné
 *
 * \param c la case ou est situé le pion dont on va chercher les déplacements possibles.
 */
coup* get_deplacements(const case_plateau c, const plateau p);


/**
 * \fn coup * completer_coup_dame(const coup c, int mvt, plateau p);
 * \param mvt La diagonale du mouvement du coup précedent.
 * \return La liste des coups possibles commençant par le coup c.
 * \author Bastien Auda
 */
coup * completer_coup_dame(const coup c, int mvt, plateau p);


/**
 * \fn int get_possible_case_pos(int c, int diag, plateau p);
 * \param c Notation officielle de la case de départ.
 * \param diag Diagonale dans laquelle on recherche.
 * \return 0 si pas de cpions à prendre, la case sur laquelle se trouve le pion à prendre sinon.
 */
int get_possible_case_pos(int c, int diag, plateau p) ;


/**
 * \fn int compare_coups(coup *liste1, coup *liste2);
 * \param liste1 la premiere liste des coups
 * \param liste2 la seconde liste des coups
 * \return 0 si liste 1 == liste2, sinon 1
 */
int compare_coups(coup *liste1, coup *liste2);


/**
 * \fn case_plateau get_case_plateau_silent(int x, int y, plateau p);
 * \param x la position en abscisse
 * \param y la position en ordonnée
 * \param p le plateau courant
 * \return la case qui est en position x y dans p
 */
case_plateau get_case_plateau_silent(int x, int y, plateau p);
