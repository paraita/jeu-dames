#include <stdio.h>

#include "../trunk/constantes.h"
#include "../trunk/regles.h"


void test1() {
	printf("debut test1 (partie avec plateau initialisé):\n");

	joueur j1;
	j1.est_humain = 1;
	joueur j2;
	j2.est_humain = 1;

	plateau p = nouveau_plateau(j1,j2);

	coup *liste = getCoups(p.joueur1,p);

	printf("\nEnumeration des coups possibles (%d):\n", nombre_coups(liste));
	coup *ptr = liste;
	int cpt = 1;
	while((ptr->old_case != 0) && (ptr->new_case != 0)) {
		printf("\n------------[%d]------------\n", cpt);
		printCoup(*ptr);
		printf("----------------------------\n");
		ptr++;cpt++;
	}

	printf("\n\n\nEnumeration des coups max:\n");
	ptr = getCoupsMax(liste);
	cpt = 1;
	while((ptr->old_case != 0) && (ptr->new_case != 0)) {
		printf("\n------------[%d]------------\n", cpt);
		printCoup(*ptr);
		printf("----------------------------\n");
		ptr++;cpt++;
	}
}

void test2() {

	/*
	 * - plateau vide
	 * - joueur 1: 30
	 * - joueur 2: 24,25
	 */

	printf("debut test2 (cas particulier):\n");

	joueur j1;
	j1.est_humain = 1;
	joueur j2;
	j2.est_humain = 0;

	plateau p = nouveau_plateau(j1,j2);

	/* pour vider le plateau */
	int i = 1;
	while(i < 52) {
		p.cases[i++].est_libre = 1;
	}

	pion dujoueur1;
	dujoueur1.couleur = blanc;
	dujoueur1.est_dame = 0;
	pion dujoueur2;
	dujoueur2.couleur = noir;
	dujoueur2.est_dame = 0;

	p.cases[30].est_libre = 0;
	p.cases[30].pion = dujoueur1;

	p.cases[25].est_libre = 0;
	p.cases[25].pion = dujoueur2;

	p.cases[24].est_libre = 0;
	p.cases[24].pion = dujoueur2;

	coup *liste = coupsPossibles(get_case_plateau(9,6,p),p);

	printf("\n\n\nEnumeration des coups possibles:\n");
	coup *ptr = liste;
	int cpt = 1;
	while((ptr->old_case != 0) && (ptr->new_case != 0)) {
		printf("\n------------[%d]------------\n", cpt);
		printCoup(*ptr);
		printf("----------------------------\n");
		ptr++;cpt++;
	}

	printf("\n\n\nEnumeration des coups max:\n");
	ptr = getCoupsMax(liste);
	cpt = 1;
	while((ptr->old_case != 0) && (ptr->new_case != 0)) {
		printf("\n------------[%d]------------\n", cpt);
		printCoup(*ptr);
		printf("----------------------------\n");
		ptr++;cpt++;
	}
}

void test3() {

	/*
	 * - plateau vide
	 * - joueur 1: 28
	 * - joueur 2: 22,12,13,23,32
	 */

	printf("debut test3 (cas particulier):\n");

	joueur j1;
	j1.est_humain = 1;
	joueur j2;
	j2.est_humain = 0;

	plateau p = nouveau_plateau(j1,j2);

	/* pour vider le plateau */
	int i = 1;
	while(i < 52) {
		p.cases[i++].est_libre = 1;
	}


	pion dujoueur1;
	dujoueur1.couleur = blanc;
	dujoueur1.est_dame = 0;
	pion dujoueur2;
	dujoueur2.couleur = noir;
	dujoueur2.est_dame = 0;

	p.cases[28].est_libre = 0;
	p.cases[28].pion = dujoueur1;

	p.cases[22].est_libre = 0;
	p.cases[22].pion = dujoueur2;

	p.cases[12].est_libre = 0;
	p.cases[12].pion = dujoueur2;

	p.cases[13].est_libre = 0;
	p.cases[13].pion = dujoueur2;

	p.cases[23].est_libre = 0;
	p.cases[23].pion = dujoueur2;

	p.cases[32].est_libre = 0;
	p.cases[32].pion = dujoueur2;

	coup *liste = getCoups(p.joueur1,p);

	printf("\n\n\nEnumeration des coups possibles:\n");
	coup *ptr = liste;
	int cpt = 1;
	while((ptr->old_case != 0) && (ptr->new_case != 0)) {
		printf("\n------------[%d]------------\n", cpt);
		printCoup(*ptr);
		printf("----------------------------\n");
		ptr++;cpt++;
	}

	printf("\n\n\nEnumeration des coups max:\n");
	ptr = getCoupsMax(liste);
	cpt = 1;
	while((ptr->old_case != 0) && (ptr->new_case != 0)) {
		printf("\n------------[%d]------------\n", cpt);
		printCoup(*ptr);
		printf("----------------------------\n");
		ptr++;cpt++;
	}
}

void test4() {

	/*
	 * - plateau vide
	 * - joueur 1: 33
	 * - joueur 2: 39,49,50
	 */

	printf("debut test4 (cas particulier):\n");

	joueur j1;
	j1.est_humain = 1;
	joueur j2;
	j2.est_humain = 0;

	plateau p = nouveau_plateau(j1,j2);

	/* pour vider le plateau */

	int i = 1;
	while(i < 52) {
		p.cases[i++].est_libre = 1;
	}


	pion dujoueur1;
	dujoueur1.couleur = blanc;
	dujoueur1.est_dame = 0;
	pion dujoueur2;
	dujoueur2.couleur = noir;
	dujoueur2.est_dame = 0;

	p.cases[33].est_libre = 0;
	p.cases[33].pion = dujoueur1;

	p.cases[39].est_libre = 0;
	p.cases[39].pion = dujoueur2;

	p.cases[49].est_libre = 0;
	p.cases[49].pion = dujoueur2;

	p.cases[50].est_libre = 0;
	p.cases[50].pion = dujoueur2;

	coup *liste = getCoups(p.joueur1,p);

	printf("\n\n\nEnumeration des coups possibles:\n");
	coup *ptr = liste;
	int cpt = 1;
	while((ptr->old_case != 0) && (ptr->new_case != 0)) {
		printf("\n------------[%d]------------\n", cpt);
		printCoup(*ptr);
		printf("----------------------------\n");
		ptr++;cpt++;
	}

	printf("\n\n\nEnumeration des coups max:\n");
	ptr = getCoupsMax(liste);
	cpt = 1;
	while((ptr->old_case != 0) && (ptr->new_case != 0)) {
		printf("\n------------[%d]------------\n", cpt);
		printCoup(*ptr);
		printf("----------------------------\n");
		ptr++;cpt++;
	}
}

void test5() {

	printf("debut test5 (cas particulier):\n");

	/*
	 * - plateau vide
	 * - joueur 1: 17,18
	 * - joueur 2: 22,32,33
	 */

	joueur j1;
	j1.est_humain = 1;
	joueur j2;
	j2.est_humain = 0;

	plateau p = nouveau_plateau(j1,j2);

	pion dujoueur1;
	dujoueur1.couleur = blanc;
	dujoueur1.est_dame = 0;
	pion dujoueur2;
	dujoueur2.couleur = noir;
	dujoueur2.est_dame = 0;

	/* pour vider le plateau */

	int i = 1;
	while(i < 52) {
		p.cases[i++].est_libre = 1;
	}

	p.cases[17].est_libre = 0;
	p.cases[17].pion = dujoueur1;

	p.cases[18].est_libre = 0;
	p.cases[18].pion = dujoueur1;

	p.cases[22].est_libre = 0;
	p.cases[22].pion = dujoueur2;

	p.cases[32].est_libre = 0;
	p.cases[32].pion = dujoueur2;

	p.cases[33].est_libre = 0;
	p.cases[33].pion = dujoueur2;

	coup *liste = coupsPossibles(get_case_plateau(3,4,p),p);

	printf("\n\n\nEnumeration des coups possibles:\n");
	coup *ptr = liste;
	int cpt = 1;
	while((ptr->old_case != 0) && (ptr->new_case != 0)) {
		printf("\n------------[%d]------------\n", cpt);
		printCoup(*ptr);
		printf("----------------------------\n");
		ptr++;cpt++;
	}

	printf("\n\n\nEnumeration des coups max:\n");
	ptr = getCoupsMax(liste);
	cpt = 1;
	while((ptr->old_case != 0) && (ptr->new_case != 0)) {
		printf("\n------------[%d]------------\n", cpt);
		printCoup(*ptr);
		printf("----------------------------\n");
		ptr++;cpt++;
	}

}

int main(int argc, char **argv) {

	//test1(); ok
	//test2(); ok
	//test3(); ok
	//test4(); ok
	test5();
	return 0;
}
