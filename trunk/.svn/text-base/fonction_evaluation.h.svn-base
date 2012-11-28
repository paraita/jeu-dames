/**
 * 	\file fonction_evaluation.h
 *	\brief La fonction d'evaluation de l'algorithme MinMax.
 *	Renvoie un double compris entre -1 et 1 caracterisant un etat du plateau plus ou moins favorable au joueur courant.
 *  \author Kyann Valai
 */

#include <stdio.h>
#include <stdlib.h>
#include "regles.h"

/**
* \fn double fct_eval(plateau * p);
* \brief La fonction principale
* \param Le plateau de jeu.
* \return Un double entre 1 (victoire du joueur courant) et -1 (victoire de l'adversaire).
*/
double fct_eval(const plateau * p);

/**
* \fn int valeur_case(plateau * p, case_plateau * c);
* \brief Renvoie, pour une case occupee, sa valeur. Independamment du joueur auquel appartient le pion.
*/
int valeur_case(const plateau * p, const case_plateau * c);

/**
* \fn int rang(const case_plateau * c);
* \brief Renvoie, pour une case occupee, son rang ie le numero de sa ligne. (depend du camp du pion)
*/
int rang(const case_plateau * c);

/**
* \fn int est_isole(const plateau * p, const case_plateau * c, int rang);
* \brief un pion isole n'est pas sur un bord et n'a aucun pion de son camp present dans une case adjacente.
*/
int est_isole(const plateau * p, const case_plateau * c, int rang);
