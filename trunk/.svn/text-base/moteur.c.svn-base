/*
 * moteur.c
 *
 *  Created on: 25 avr. 2011
 *      Author: bastien
 */

#include "moteur.h"

/** Permet de savoir si un coup non terminé de la part du joueur est en cours. (Ne pas utiliser en dehors de moteur.c) */
int coup_en_cours = 0;

/** Variable globale qui n'est calculée qu'une seule fois au début du tour. (Ne pas utiliser en dehors de moteur.c) */
coup * coups_possibles;

/** Variable globale qui permet de choisir la profondeur d'analyse de l'algorithme min-max (Ne pas utiliser en dehors de moteur.c, utilisez plutôt ::set_difficulte). */
int difficulte = 1;

/** sauvegarde de la case de départ dans le cas d'un coup en plusieurs mouvement */
int case_depart;

/** on garde la case intermédiaire afin de vérifier que le joueur reclique bien sur le même jeton après un mouvement partiel */
int case_intermediaire;

int jouer_coup(int depart, int arrivee) {
	reset_surbrillance(&p_jeu);
	if (coup_en_cours) { /* si un mouvement n'a pas été transfomé en coup complet */
		if (depart == case_intermediaire) { /* on vérifie qu'on déplace toujours le même pion */
			int i = 0;
			coup c;
			while ((c = coups_possibles[i]).old_case != 0) { /* on recherche à nouveau les coups qui correspondent à la case de départ */
				if (c.old_case == case_depart) {
					if (c.new_case == arrivee) {
						plateau_deplacer_pion(depart, case_depart, &p_jeu); /* on remet le pion à sa position initiale pour appeler plateau_appliquer_coup() */
						plateau_appliquer_coup(c, &p_jeu);
						coup_en_cours = 0;
						return 1;
					} else { /* sinon on recherche si le déplacement fait partie d'un coup valide */
						int j = 0;
						case_plateau case_path;
						int nb_prises = c.nombre_prises;
						while (j < nb_prises) {
							case_path = c.chemin[j];
							if (case_path.notation_officielle == arrivee) { /* si c'est le cas, on stocke la case de départ et on quitte en attendant la suite du coup */
								coup_en_cours = 1;
								case_intermediaire = arrivee;
								plateau_deplacer_pion(depart, arrivee, &p_jeu);
								return 2;
							}
							j++;
						}
					}
				}
				i++;
			}
		}
		/* si on n'a pas fait de return avant ce point, alors le coup est invalide, on remet le plateau dans sa position initiale */
		coup_en_cours = 0;
		case_depart = 0;
		case_intermediaire = 0;
		plateau_deplacer_pion(depart, case_depart, &p_jeu);
		return 0;
	} else { /* si on commence un nouveau tour */
		int i = 0;
		coup c;
		int nb_coups = nombre_coups(coups_possibles);
		while (i < nb_coups) { /* puis on le parcours à la recherche de la case cliquée */
			c = coups_possibles[i];
			if (c.old_case == depart) { /* si on la trouve on teste si c'est un coup complet */
				if (c.new_case == arrivee) {
					plateau_appliquer_coup(c, &p_jeu); /* si c'est le cas on met le plateau à jour */
					return 1;
				} else { /* sinon on cherche si le déplacement fait partie d'un coup valide */
					int j = 0;
					case_plateau case_path;
					int nb_prises = c.nombre_prises;
					while (j < nb_prises) {
						case_path = c.chemin[j];
						if (case_path.notation_officielle == arrivee) { /* si c'est le cas, on stocke la case de départ et on quitte en attendant la suite du coup */
							case_depart = depart;
							coup_en_cours = 1;
							case_intermediaire = arrivee;
							plateau_deplacer_pion(depart, arrivee, &p_jeu);
							return 2;
						}
						j++;
					}
				}
			}
			i++;
		}
		return 0; /* si on n'a pas touvé de case de départ ou de chemin correspondant, alors le coup n'est pas valide */
	}
}

int jouer_coup_xy(int x1, int y1, int x2, int y2) {
	case_plateau c1 = get_case_plateau(x1, y1, p_jeu);
	case_plateau c2 = get_case_plateau(x2, y2, p_jeu);
	return jouer_coup(c1.notation_officielle, c2.notation_officielle);
}

int hint_deplacements_possibles_xy(int x, int y) {
	case_plateau c = get_case_plateau(x, y, p_jeu);
	return hint_deplacements_possibles(c.notation_officielle);
}

int commencer_tour() {
	if (!coup_en_cours) {
		coups_possibles = getCoupsMax(getCoups(p_jeu.tour, p_jeu)); /* on met à jour le tableau des coups possibles */
		if (nombre_coups(coups_possibles) == 0) { // si on ne peut pas jouer, on passe la main.
			if(p_jeu.tour.couleur == p_jeu.joueur1.couleur)
				p_jeu.tour = p_jeu.joueur2;
			else
				p_jeu.tour = p_jeu.joueur1;
			return 1;
		}
	}
	if (p_jeu.tour.est_humain) {
		return 0;
	} else {
		jouer_tour_ia();
		return 1;
	}
}

void jouer_tour_ia() {
	reset_surbrillance(&p_jeu);
	coup c = jouerIA(p_jeu, difficulte);
	plateau_appliquer_coup(c, &p_jeu);
	set_case_en_surbrillance(c.old_case,&p_jeu);
	int i;
	for(i = 0; i < c.nombre_prises; i++) {
		set_case_en_surbrillance(c.chemin[i].notation_officielle,&p_jeu);
	}
	set_pion_en_surbrillance(c.new_case, &p_jeu);
}

void set_difficulte(int i) {
	difficulte = i;
}

void hint_pions_jouables() {
	reset_surbrillance(&p_jeu);
	if(!coup_en_cours) {
		coups_possibles = getCoupsMax(getCoups(p_jeu.tour,p_jeu));
	}
	int i = 0;
	int n = nombre_coups(coups_possibles);
	for (i = 0; i < n; i++) { /* On parcours toutes les cases de départ possibles et on les met en surbrillance */
		set_pion_en_surbrillance(coups_possibles[i].old_case, &p_jeu);
	}
}

int hint_deplacements_possibles(int c) {
	reset_surbrillance(&p_jeu);
	int res = 0;
	int i = 0;
	int n = nombre_coups(coups_possibles);
	int current_case = c;
	if (coup_en_cours) {
		c = case_depart;
	}
	int current_case_found = 0;
	for (i = 0; i < n; i++) { /* On parcours tous les coups */
		coup cp = coups_possibles[i];
		if (cp.old_case == c) { /* si la case de départ d'un coup correspond à celle qu'on cherche */
			case_plateau * cases = cp.chemin;
			int nb_cases = cp.nombre_prises;
			int j = 0;
			while (j < nb_cases) { /* on met en surbrillance toutes les cases par lesquelles passe le coup */
				int case_surbrillance = cases[j].notation_officielle;
				if (current_case_found)
					set_case_en_surbrillance(case_surbrillance, &p_jeu);
				if (case_surbrillance == current_case)
					current_case_found = 1;
				j++;
			}
			set_case_en_surbrillance(cp.new_case, &p_jeu);
			res = 1;
		}
	}
	return res;
}

int sauvegarder_partie(char * filename) {
	int i;
	FILE* fichier;

	fichier = fopen(filename, "w");

	if (fichier) {

		if (p_jeu.joueur1.couleur == blanc) {
			fprintf(fichier, "%d\t 1\n", p_jeu.joueur1.est_humain);
		} else {
			if (p_jeu.joueur1.couleur == noir) {
				fprintf(fichier, "%d\t 0\n", p_jeu.joueur1.est_humain);
			}
		}

		if (p_jeu.joueur2.couleur == blanc) {
			fprintf(fichier, "%d\t 1\n", p_jeu.joueur2.est_humain);
		} else {
			if (p_jeu.joueur2.couleur == noir) {
				fprintf(fichier, "%d\t 0\n", p_jeu.joueur2.est_humain);
			}
		}
		if (p_jeu.tour.couleur == p_jeu.joueur1.couleur) {
			fprintf(fichier, "1\n");
		} else {
			fprintf(fichier, "2\n");
		}
		for (i = 1; i <= 50; i++) {
			if (p_jeu.cases[i].pion.couleur == blanc) { //Couleur = 1 si blanc
				fprintf(fichier, "%d\t %d\t %d\t %d\t %d\t 0\t %d\t %d\t 1\n",
						p_jeu.cases[i].notation_officielle,
						p_jeu.cases[i].en_surbrillance, p_jeu.cases[i].x,
						p_jeu.cases[i].y, p_jeu.cases[i].est_libre,
						p_jeu.cases[i].pion.en_surbrillance,
						p_jeu.cases[i].pion.est_dame,
						p_jeu.cases[i].pion.est_dame);
			} else {
				if (p_jeu.cases[i].pion.couleur == noir) { //Couleur = 0 si noir
					fprintf(fichier,
							"%d\t %d\t %d\t %d\t %d\t 0\t %d\t %d\t 0\n",
							p_jeu.cases[i].notation_officielle,
							p_jeu.cases[i].en_surbrillance, p_jeu.cases[i].x,
							p_jeu.cases[i].y, p_jeu.cases[i].est_libre,
							p_jeu.cases[i].pion.en_surbrillance,
							p_jeu.cases[i].pion.est_dame,
							p_jeu.cases[i].pion.est_dame);

				}
			}
		}
		//fprintf(fichier,"LoL %d", p.cases[40].couleur);
		fclose(fichier);
		printf("Sauvegarde reussi \n");
		return 1;
	}

	else {
		printf("Erreur lors de l'ouverture de fichier \n");
		return 0;
	}

}

int charger_partie(char * filename) {

	joueur j1;
	joueur j2;

	int couleurJ1, couleurJ2, estHumainJ1, estHumainJ2, tourCouleur,
			notationOff, surbrillance, x, y, estLibre, couleurCase,
			pionSurbrillance, estDame, pionCouleur, i;
	FILE* fichier;
	fichier = fopen(filename, "r");

	if (fichier) {
		//Recuperation donnees joueur 1
		fscanf(fichier, "%d\t %d\n", &estHumainJ1, &couleurJ1);
		if (couleurJ1 == 1) {
			p_jeu.joueur1.couleur = blanc;
			p_jeu.joueur1.est_humain = estHumainJ1;
		} else {
			p_jeu.joueur1.couleur = noir;
			p_jeu.joueur1.est_humain = estHumainJ1;
		}

		//Recuperation donnees joueur 2
		fscanf(fichier, "%d\t %d\n", &estHumainJ2, &couleurJ2);
		if (couleurJ2 == 1) {
			p_jeu.joueur2.couleur = blanc;
			p_jeu.joueur2.est_humain = estHumainJ2;
		} else {
			p_jeu.joueur2.couleur = noir;
			p_jeu.joueur2.est_humain = estHumainJ2;
		}

		//Recuperation donnees tour
		fscanf(fichier, "%d\n", &tourCouleur);
		if (tourCouleur == 1) {
			p_jeu.tour.couleur = p_jeu.joueur1.couleur;
		} else {
			p_jeu.tour.couleur = p_jeu.joueur2.couleur;
		}

		//Recuperation donnees cases
		for (i = 1; i <= 50; i++) {
			fscanf(fichier, "%d\t %d\t %d\t %d\t %d\t %d\t %d\t %d\t %d\n",
					&notationOff, &surbrillance, &x, &y, &estLibre,
					&couleurCase, &pionSurbrillance, &estDame, &pionCouleur);
			if (pionCouleur == 1) {
				p_jeu.cases[i].notation_officielle = notationOff;
				p_jeu.cases[i].en_surbrillance = surbrillance;
				p_jeu.cases[i].x = x;
				p_jeu.cases[i].y = y;
				p_jeu.cases[i].est_libre = estLibre;
				p_jeu.cases[i].couleur = noir;
				p_jeu.cases[i].pion.en_surbrillance = pionSurbrillance;
				p_jeu.cases[i].pion.est_dame = estDame;
				p_jeu.cases[i].pion.couleur = blanc;
			} else {
				p_jeu.cases[i].notation_officielle = notationOff;
				p_jeu.cases[i].en_surbrillance = surbrillance;
				p_jeu.cases[i].x = x;
				p_jeu.cases[i].y = y;
				p_jeu.cases[i].est_libre = estLibre;
				p_jeu.cases[i].couleur = noir;
				p_jeu.cases[i].pion.en_surbrillance = pionSurbrillance;
				p_jeu.cases[i].pion.est_dame = estDame;
				p_jeu.cases[i].pion.couleur = noir;
			}
		}
		printf("Chargement termine avec succes \n");
		return 1;
	} else {
		printf("Erreur lors de l'ouverture du fichier \n");
		return 0;
	}

}

void initialiser_partie() {
	joueur joueur1;
	joueur joueur2;

	joueur1.est_humain = 1;
	joueur2.est_humain = 1;

	p_jeu = nouveau_plateau(joueur1, joueur2);
}

void set_joueur_est_humain(couleur_pion couleur, int boolean) {
	if (couleur == blanc) {
		p_jeu.joueur1.est_humain = boolean;
	} else {
		if (couleur == noir) {
			p_jeu.joueur2.est_humain = boolean;

		} else {
			printf(
					"Erreur : set_joueur_est_humain(couleur_pion couleur, int boolean) : mauvaise couleur");
			exit(1);
		}
	}

}

plateau get_plateau() {
	return p_jeu;
}

int partie_terminee() {
	return plateau_partie_finie(p_jeu);
}
