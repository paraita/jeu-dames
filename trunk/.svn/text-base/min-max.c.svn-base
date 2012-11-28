/*
 * min-max.c
 *
 *  Created on: 14 avr. 2011
 *      Author: bastien
 */

#define maximum(a,b) (a>=b?a:b)
#define minimum(a,b) (a<=b?a:b)

#include <stdlib.h>

#include "min-max.h"

double max(plateau p, int profondeur, double alpha, double beta);
double min(plateau p, int profondeur, double alpha, double beta);

coup jouerIA(const plateau p, int profondeur) {
	double alpha = MINIMUM;
	double beta = MAXIMUM;
	coup res;
	coup * coups_possibles = getCoupsMax(getCoups(p.tour,p));

	int i = 0;
	coup c;
	int nbCoups = nombre_coups(coups_possibles);

	if(nbCoups == 1) {
		return coups_possibles[0];
	}

	while ( i < nbCoups) { // On parcours la liste des coups possibles
		c = coups_possibles[i];
		plateau new_p = p;
		plateau_appliquer_coup(c,&new_p);
		double tmp = min(new_p, profondeur - 1,alpha,beta);
		if (tmp > alpha) { // si le coup est meilleur que le précedent, on le garde
			alpha = tmp;
			res = c;
		}
		i++;
	}
	return res;
}

double max(const plateau p, int profondeur, double alpha, double beta) {

	if (plateau_partie_finie(p) || profondeur == 0) { /* si on arrive à la profondeur max ou que la partie est gangée/perdue, on renvoie l'évaluation */

		return fct_eval(&p);
	} else {
		coup * coups_possibles = getCoupsMax(getCoups(p.tour,p));

		int i = 0;
		coup c;
		int nbCoups = nombre_coups(coups_possibles);
		while (i < nbCoups) { /* On parcours la liste des coups possibles */
			c = coups_possibles[i];
			plateau new_p = p;
			plateau_appliquer_coup(c,&new_p);
			alpha = maximum(alpha,min(new_p, profondeur - 1,alpha,beta));

			if (beta <= alpha) { /* si le coup est meilleur que le précedent, on le garde */
				return alpha;
			}
			i++;
		}
		free(coups_possibles);
		return alpha;
	}

}

double min(const plateau p, int profondeur, double alpha, double beta) {
	if (plateau_partie_finie(p) || profondeur == 0) { /* si on arrive à la profondeur max, on renvoie l'évaluation */
		return fct_eval(&p);
	} else {
		coup * coups_possibles = getCoupsMax(getCoups(p.tour,p));

		int i = 0;
		coup c;
		int nbCoups = nombre_coups(coups_possibles);
		while ( i < nbCoups ) { /* On parcours la liste des coups possibles */
			printf("evaluation min du coup : %i\n",i);
			c  = coups_possibles[i];
			plateau new_p = p;
			plateau_appliquer_coup(c,&new_p);
			beta = minimum(beta, max(new_p, profondeur - 1,alpha,beta));
			if (alpha >= beta) { /* coupure beta */
				return beta;
			}
			i++;
		}
		free(coups_possibles);
		return beta;
	}

}
