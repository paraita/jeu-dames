/*
 * arbre.c
 *
 *  Created on: 9 avr. 2011
 *      Author: bastien
 */

#include <stdio.h>;

#include "arbre.h";


int arbre_est_feuille(arbre t) {
	return t.nb_fils == 0;
}


void print_arbre(arbre t) {
	if(arbre_est_feuille(t)) {
		printf(" %i",t.valeur);
		return;
	} else {
		printf(" (%i", t.valeur);
		int i;
		for(i = 0; i < t.nb_fils; i++) {
			print_arbre(*(t.fils[i]));
		}
		printf(")");
	}
}
