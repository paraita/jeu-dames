/*
 * test_arbre.c
 *
 *  Created on: 9 avr. 2011
 *      Author: bastien
 */
#include <stdio.h>

#include "../trunk/constantes.h"
#include "../trunk/arbre.h";

int main(int argc, char *argv[]){

	arbre t;
	t.valeur = 0;
	t.nb_fils = 4;


	arbre f1;
	f1.valeur = 1;
	f1.nb_fils = 0;
	t.fils[0] = &f1;

	arbre f2;
	f2.valeur = 2;
	f2.nb_fils = 2;

	arbre f21;
	f21.valeur = 21;
	f21.nb_fils = 0;
	f2.fils[0] = &f21;

	arbre f22;
	f22.valeur = 22;
	f22.nb_fils = 0;
	f2.fils[1] = &f22;

	t.fils[1] = &f2;

	arbre f3;
	f3.valeur = 3;
	f3.nb_fils = 0;
	t.fils[2] = &f3;

	arbre f4;
	f4.valeur = 4;
	f4.nb_fils = 0;
	t.fils[3] = &f4;

	print_arbre(t);

	return 0;
}
