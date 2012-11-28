#include <stdio.h>

#include "../trunk/constantes.h"
#include "../trunk/regles.h"
#include <stdlib.h>
#include <check.h>


/* si c1 == c2 retourne 0, sinon 1 */
int compare_coup(coup *c1, coup *c2) {
	if((c1->old_case == c2->old_case)
			&& (c1->new_case == c2->new_case)
			&& (c1->nombre_prises == c1->nombre_prises)
			&& (c1->tc == c2->tc))
			return 0;
	return 1;
}

START_TEST(test_cas1) {

	/* fabrication de la liste des coups attendu */
	coup expectedCoups[9];
	expectedCoups[0].old_case = 31;
	expectedCoups[1].old_case = 31;
	expectedCoups[2].old_case = 32;
	expectedCoups[3].old_case = 32;
	expectedCoups[4].old_case = 33;
	expectedCoups[5].old_case = 33;
	expectedCoups[6].old_case = 34;
	expectedCoups[7].old_case = 34;
	expectedCoups[8].old_case = 35;

	expectedCoups[0].new_case = 26;
	expectedCoups[1].new_case = 27;
	expectedCoups[2].new_case = 27;
	expectedCoups[3].new_case = 28;
	expectedCoups[4].new_case = 28;
	expectedCoups[5].new_case = 29;
	expectedCoups[6].new_case = 29;
	expectedCoups[7].new_case = 30;
	expectedCoups[8].new_case = 30;

	int i;
	for (i = 0; i < 9; ++i) {
		expectedCoups[i].tc = t;
		expectedCoups[i].nombre_prises = -1;
	}


	joueur j1;
	j1.est_humain = 1;
	joueur j2;
	j2.est_humain = 1;

	plateau p = nouveau_plateau(j1,j2);

	coup *liste = getCoups(p.joueur1,p);

	int nb_coups = nombre_coups(liste);

	printf("\n\n\nEnumeration des coups possibles (%d):\n", nb_coups);

	fail_unless(nb_coups == 9, "on n'as trouvé le bon nombre de coups");
	fail_unless(!compare_coups(liste,expectedCoups), "les coups trouvés ne sont pas bons");

}
END_TEST

START_TEST(test_cas2) {

	/*
	 * - plateau vide
	 * - joueur 1: 30
	 * - joueur 2: 24,25
	 */

	coup *expected = malloc(sizeof(coup));
	expected->new_case = 19;
	expected->old_case = 30;
	expected->nombre_prises = 1;
	expected->tc = x;

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

	fail_unless(nombre_coups(liste) == 1, "on n'as trouvé le bon nombre de coups");
	fail_unless(!compare_coup(liste[0], expected), "les coups trouvés ne sont pas bons");

	free(expected);

}
END_TEST

START_TEST(test_cas3) {
	/*
	 * - plateau vide
	 * - joueur 1: 28
	 * - joueur 2: 22,12,13,23,32
	 */

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

	int nb_coups = nombre_coups(liste);

	fail_unless(nb_coups == 1, "on n'as trouvé le bon nombre de coups");
	fail_unless(liste[0].nombre_prises == 5, "on a pas le bon nombre de prises");
}
END_TEST

START_TEST(test_cas4) {
	/*
	 * - plateau vide
	 * - joueur 1: 33
	 * - joueur 2: 39,49,50
	 */

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

	coup *expected = malloc(sizeof(coup));
	expected->new_case = 44;
	expected->old_case = 33;
	expected->nombre_prises = 1;
	expected->tc = x;

	fail_unless(nombre_coups(liste) == 1, "on n'as trouvé le bon nombre de coups");
	fail_unless(!compare_coup(liste[0], expected), "on n'as trouvé le même coup");

}
END_TEST


START_TEST(test_cas5) {

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

	fail_unless(nombre_coups(liste) == 4, "on n'as trouvé le bon nombre de coups");

}



Suite *regles_suite(void){
	Suite *s = suite_create("regles");
	TCase *tc_core = tcase_create("Core");
	suite_add_tcase(s,tc_core);
	tcase_add_test(tc_core,test_cas1);
	tcase_add_test(tc_core,test_cas2);
	tcase_add_test(tc_core,test_cas3);
	tcase_add_test(tc_core,test_cas4);
	tcase_add_test(tc_core,test_cas5);
	return s;
}

int main(int argc, char *argv[]){
	int nf;
	Suite *s = regles_suite();
	SRunner *sr = srunner_create(s);
	srunner_run_all(sr,CK_VERBOSE);
	nf=srunner_ntests_failed(sr);
	srunner_free(sr);
	return (nf==0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
