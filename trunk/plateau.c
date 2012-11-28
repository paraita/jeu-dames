/*
 * plateau.c
 *
 *  Created on: 20 mars 2011
 *      Author: bastien
 */

#include <stdio.h>
#include "plateau.h"

plateau nouveau_plateau(joueur j1, joueur j2) {
	plateau p;
	j1.couleur = blanc;
	j2.couleur = noir;
	p.joueur1 = j1;
	p.joueur2 = j2;
	p.tour = j1;
	p.i = 0;
	int i = 1;
	int x = 2;
	int y = 1;
	while (i <= 50) { /* on remplit le plateau ( bug ici j ai change le 20 en 50)*/
		pion pion;
		pion.est_dame = 0;
		case_plateau c;
		c.notation_officielle = i;
		c.couleur = noir;
		c.en_surbrillance = 0;
		c.x = x;
		c.y = y;
		if (i <= 20) { /* si on est du côté des noirs, on place les pions */
			c.est_libre = 0;
			pion.couleur = noir;
			pion.en_surbrillance = 0;
			c.pion = pion;
		} else if (i > 30) { /* si on est du côté des blancs */
			c.est_libre = 0;
			pion.couleur = blanc;
			pion.en_surbrillance = 0;
			c.pion = pion;
		} else { /* si on est au centre on a des case libres */
			c.est_libre = 1;
		}
		p.cases[i] = c;

		i++;
		x = x + 2;
		if (i % 10 == 6) { /* on détecte les changements de ligne pour décaler x et incrémenter y */
			/*printf("%i mod 10 = %i\n",i,i%10);*/
			x = 1;
			y++;
		} else if (i % 10 == 1) {
			/*printf("%i mod 10 = %i\n",i,i%10);*/
			x = 2;
			y++;
		}
	}

	case_plateau case_blanche;
	case_blanche.couleur = blanc;
	case_blanche.est_libre = 1;
	case_blanche.notation_officielle = 0;
	case_blanche.en_surbrillance = 0;
	case_blanche.x = 0;
	case_blanche.y = 0;
	p.cases[0] = case_blanche;
	return p;
}

int plateau_deplacer_pion(int old_position, int new_position, plateau *p) {
	if (old_position < 1 || old_position > 50 || new_position < 1
			|| new_position > 50 || p->cases[old_position].est_libre
			|| !p->cases[new_position].est_libre) {
		return 0;
	} else {
		pion pion = p->cases[old_position].pion;
		p->cases[old_position].est_libre = 1;
		p->cases[new_position].est_libre = 0;
		p->cases[new_position].pion = pion;
		return 1;
	}
}

int plateau_prendre_pion(int position, plateau *p) {
	if (position < 1 || position > 50 || p->cases[position].est_libre) {
		return 0;
	} else {
		p->cases[position].est_libre = 1;
		return 1;
	}
}

void plateau_ajouter_coup(coup c, plateau *p) {
	int i = p->i;
	if (i < 500) {
		p->historique[i] = c;
		p->i = i + 1;
	}
}

case_plateau get_case_plateau(int x, int y, plateau p) {
	if (x < 1 || x > 10 || y < 1 || y > 10) {
		fprintf(stderr, "Case hors plateau (%i,%i)\n", x, y);
		return p.cases[0];
	}
	if ((x % 2) == (y % 2)) { /* si x et y sont tout les deux pairs (ou impairs), alors c'est une case blanche */
		return p.cases[0];
	} else {
		int i;
		for (i = 1; i <= 50; i++) { /* temporairement on fait une recherche dans le tableau, en attendant un algorithme qui offre de meilleures performances */
			case_plateau c = p.cases[i];
			if (c.x == x && c.y == y) {
				return c;
			}
		}
		return p.cases[0];
	}
}

void print_case(case_plateau c) {
		printf("Case [%i] : (%i,%i) couleur : %i, est_libre : %i surbrillance : %i\n",
				c.notation_officielle, c.x, c.y, c.couleur, c.est_libre,c.en_surbrillance);
}

void set_case_en_surbrillance(int numero,plateau *p) {
	p->cases[numero].en_surbrillance = 1;
}

void set_pion_en_surbrillance(int numero,plateau *p) {
	p->cases[numero].pion.en_surbrillance = 1;
}

void reset_surbrillance(plateau *p) {
	int i;
	for(i = 0; i < 51; i++) {
		p->cases[i].en_surbrillance = 0;
		p->cases[i].pion.en_surbrillance = 0;
	}
}

void plateau_appliquer_coup(coup c, plateau * p) {
	case_plateau * cases = p->cases;
	if(cases[c.old_case].est_libre || !cases[c.new_case].est_libre) {
		fprintf(stderr, "Impossible de jouer le coup (%d,%d) : case de départ vide ou case d'arrivée déjà occupée.",c.old_case,c.new_case);
	} else {
		plateau_deplacer_pion(c.old_case,c.new_case,p);	/* on déplace le pion */

		if(c.tc == x) {	/* puis, si le coup est une prise, on prend le(s) pion(s) */
			int i;
			for(i = 0; i < c.nombre_prises; i++) {
				plateau_prendre_pion(c.prises[i].notation_officielle,p);
			}
		}

		if(p->cases[c.new_case].pion.couleur == blanc && c.new_case <= 5) { /* puis on teste si le mouvement crée une dame */
			p->cases[c.new_case].pion.est_dame = 1;
		} else if( p->cases[c.new_case].pion.couleur == noir && c.new_case >= 46 ) {
			p->cases[c.new_case].pion.est_dame = 1;
		}

		if(p->tour.couleur == p->joueur1.couleur) { /* enfin on passe la main au joueur suivant */
			p->tour = p->joueur2;
		} else {
			p->tour = p->joueur1;
		}
		// TODO printf de debug a supprimer
		printf("\n------------------------\n");
		printf("\nCoup appliqué :\n");
		printCoup(c);
		printf("\n------------------------\n");
	}

}

int plateau_partie_finie(plateau p) {
	int i;
	int trouve = 0; /* on le passe à vrai quand on a trouvé le premier pion, puis on vérifie que tout les autres pions sont de la même couleur */
	couleur_pion couleur;
	for(i = 1; i <= 50; i++ ) {
		if(! p.cases[i].est_libre) {
			if(trouve) {
				if( couleur != p.cases[i].pion.couleur) {
					return 0;
				}
			} else {
				trouve = 1;
				couleur = p.cases[i].pion.couleur;
			}
		}
	}
	/* si on a parcouru le tout le damier et qu'on n'a pas trouvé deux pions de couleurs différentes, alors la partie est terminée */
	return couleur + 1; /* 1 si c'est les blancs, 2 si c'est les noirs. */
}


void print_plateau(plateau p) {
	int i, j;
	printf("\n---------------------\n");
	for(i = 1; i <= 10; i++) {
		printf("|");
		for(j = 1; j <=10 ; j++) {
			case_plateau c = get_case_plateau(j,i,p);
			if(c.couleur != blanc) {
				if(!c.est_libre) {
					if(c.pion.couleur == blanc) {
						if(c.pion.en_surbrillance)
							printf("o");
						else printf("O");
					} else {
						if(c.pion.en_surbrillance)
							printf("x");
						else printf("X");
					}
					if (c.pion.est_dame)
						printf("*");
				} else {
					if (c.en_surbrillance)
						printf("-");
					else printf(" ");
				}
			} else {
				printf(" ");
			}
			printf("|");
		}
		printf("\n---------------------\n");
	}
	return;
}


//TODO enlever les printf de debug ici
/* pretty print d'un coup */
void printCoup(const coup c) {
	if ((c.old_case == 0) && (c.new_case == 0)) {
		/* on tombe normalement jamais dessus mais utile au debug */
		printf("coup bidon");
	} else {
		printf("de [%d] vers [%d]\n", c.old_case, c.new_case);
		printf("parcours du coup:\n");
		int i;
		for (i = 0; i < c.nombre_prises; i++) {
			print_case(c.chemin[i]);
		}
		printf("la position des pions pris:\n");
		i = 0;
		for (i = 0; i < c.nombre_prises - 1; i++) {
			print_case(c.prises[i]);
		}
		printf("nombre_prises: %d\n", c.nombre_prises - 1);
		printf("type coup: %d\n", c.tc);
	}
}


//TODO declarer dans regles.h
/* predicat: est ce que le pion sur position est prenable ? */
int est_prenable(int position, plateau *p) {
	printf("prenabilité de [%d]: %d\n", position, p->cases[position].est_libre);
	if (position < 1 || position > 50 || p->cases[position].est_libre) {
		return 0;
	} else {
		return 1;
	}
}

//TODO declarer dans regles.h
/* affiche ce qu'il y a dans la liste de coups */
void print_liste_coups(coup *l) {
	printf("----------------------------\n");
	printf("etat de cp:\n");
	coup *ptr = l;
	int a = 1;
	while (ptr->old_case != 0 && ptr->new_case != 0) {
		printf("[%d]----~\n", a);
		printCoup(*ptr);
		ptr++;
		a++;
	}
	printf("----------------------------\n");
}

//TODO declarer dans regles.h
/* predicat: est ce que cette case_plateau est dans le tableau ? */
int coup_inclus(case_plateau c, case_plateau *liste, int taille) {
	int resultat = 0;
	int i;
	for (i = 0; i < taille - 1; ++i) {
		if (liste[i].notation_officielle == c.notation_officielle) {
			printf("[%d] est dans la liste !\n", c.notation_officielle);
			resultat = 1;
			break;
		}
	}
	return resultat;
}


/*//TODO debug retourne le nombre de coups dans un tableau */
int nombre_coups(coup *set) {
	int cpt = 0;
	while ((set->old_case != 0) && (set->new_case != 0)) {
		cpt++;
		set++;
	}
	return cpt;
}
