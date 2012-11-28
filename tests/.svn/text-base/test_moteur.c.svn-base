#include <stdio.h>
#include "../trunk/moteur.h"
#include "../trunk/constantes.h"

int main(int argc, char* argv[]) {

	initialiser_partie();

	int depart, arrivee;

	do {
		commencer_tour();


		do {
		hint_pions_jouables();
		print_plateau(p_jeu);
		printf("Entrez la case de départ en notation officielle : ");
		scanf("%d", &depart);

		hint_deplacements_possibles(depart); // Case selectionné

		print_plateau(p_jeu);

		printf("Entrez la case d'arrivée en notation officielle : ");
		scanf("%d", &arrivee);



		} while(jouer_coup(depart, arrivee) != 1);

	} while (depart != 0);
	return 0;
}
