/*
 * regles.c
 *
 *  Created on: 14 avr. 2011
 *      Author: paraita
 */
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h> /* pour NULL */
#include <string.h> /* pour memcpy */
#include "regles.h"

#define NBCOUPS 2000
#define NBDEPLACEMENTS 2

/*
 * POSITION 1: x-1,y-1
 * POSITION 2: x+1,y-1
 * POSITION 3: x-1,y+1
 * POSITION 4: x+1,y+1
 */

/* retourne les coups possibles pour un pion */
coup* coupsPossibles(const case_plateau c, const plateau p) {

	coup *cp = calloc(NBCOUPS, sizeof(coup));
	plateau p_futur = p;
	int cnt_coup = 0;
	case_plateau case_courant = c;
	couleur_pion adversaire = (c.pion.couleur == blanc) ? noir : blanc;

	/* conditions de départ */
	coup coup_courant;
	coup_courant.old_case = case_courant.notation_officielle;
	coup_courant.nombre_prises = 0;
	coup_courant.tc = x;
	coup_courant.chemin[coup_courant.nombre_prises++] = case_courant;

	/* pour signaler qu'on est dans une rafle */
	int nouvelle_rafle = 0;
	int fini = 0;
	int derniere_position = 0;

	/* quand on est sur la case de départ on marque l'element qu'on va visiter
	 * ainsi on ne reparcours pas une deuxieme fois quand on revient durant le backtrack
	 */
	case_plateau to_avoid_depart[5];
	int cnt_avoid_depart = 0;

	/*
	 * quand on est sur une case pendant une prise, on marque les pions alentours qu'on a visité
	 * au cas ou il y a plusieurs choix possibles
	 */
	case_plateau to_avoid_parcours[5];
	int cnt_avoid_parcours = 0;

	/* ---------------------------------------------------------------------------
	 * stratégie:
	 *
	 * 		       |       |
	 *         1   |       |   2				On teste d'abord les cases
	 * 		_______|_______|_______				dans l'ordre indiqué toujours
	 * 		       | case  |					par rapport à la case courante
	 *             |courant|
	 * 		_______|_______|_______
	 *		       |       |
	 * 		   3   |       |   4
	 *             |       |
	 *
	 *
	 *
	 * ---------------------------------------------------------------------------
	 */

	/* aTester est la case qu'on veut prendre s'il y a un pion du joueur adverse dessus */
	case_plateau aTester = get_case_plateau_silent(case_courant.x-1,case_courant.y-1,p_futur);


	while(!fini) {

		/* POSITION 1 */
		if((aTester.est_libre == 0)
				&& (aTester.pion.couleur == adversaire)
				&& (est_prenable(aTester.notation_officielle,&p_futur) == 1)
				&& ((get_case_plateau_silent(aTester.x-1, aTester.y-1, p_futur).est_libre)
						|| coup_inclus(get_case_plateau_silent(aTester.x-1, aTester.y-1, p_futur),coup_courant.chemin,coup_courant.nombre_prises))
				&& (!coup_inclus(aTester, coup_courant.prises, coup_courant.nombre_prises))
				&& (get_case_plateau_silent(aTester.x-1, aTester.y-1, p_futur).notation_officielle != 0)
				&& (aTester.notation_officielle != derniere_position)
				&& (!coup_inclus(aTester, to_avoid_parcours, cnt_avoid_parcours))) {
			if((case_courant.notation_officielle == coup_courant.old_case)
					&& (coup_courant.nombre_prises <= 1)
					&& (coup_inclus(aTester, to_avoid_depart, cnt_avoid_depart))) {
				break;
			}
			else {
				nouvelle_rafle = 1;
				derniere_position = 0;
				/* si je suis sur la case de départ, j'ajoute aTester a la liste des cases a eviter */
				if ((case_courant.notation_officielle == coup_courant.old_case)
						&& (coup_courant.nombre_prises <= 1)) {
					to_avoid_depart[cnt_avoid_depart++] = aTester;
				}
				/* nouvelle_position est la case ou on atteri apres avoir mangé aTester */
				case_courant = get_case_plateau_silent(aTester.x-1, aTester.y-1, p_futur);
				coup_courant.new_case = case_courant.notation_officielle;
				coup_courant.prises[coup_courant.nombre_prises - 1] = aTester;
				coup_courant.chemin[coup_courant.nombre_prises++] = case_courant;

				/* on va reessayer le test sur la POSITION 1 de aTester */
				aTester = get_case_plateau_silent(case_courant.x-1,case_courant.y-1, p_futur);
			}
		}
		else {
			aTester = get_case_plateau_silent(case_courant.x+1,case_courant.y-1,p_futur);
			/* POSITION 2 */
			if((aTester.est_libre == 0)
					&& (aTester.pion.couleur == adversaire)
					&& (est_prenable(aTester.notation_officielle,&p_futur) == 1)
					&& ((get_case_plateau_silent(aTester.x+1, aTester.y-1, p_futur).est_libre)
							|| coup_inclus(get_case_plateau_silent(aTester.x+1, aTester.y-1, p_futur), coup_courant.chemin, coup_courant.nombre_prises))
					&& (!coup_inclus(aTester, coup_courant.prises, coup_courant.nombre_prises))
					&& (get_case_plateau_silent(aTester.x+1, aTester.y-1, p_futur).notation_officielle != 0)
					&& (aTester.notation_officielle != derniere_position)
					&& (!coup_inclus(aTester, to_avoid_parcours, cnt_avoid_parcours))) {
				if((case_courant.notation_officielle == coup_courant.old_case)
						&& (coup_courant.nombre_prises <= 1)
						&& (coup_inclus(aTester, to_avoid_depart, cnt_avoid_depart))) {
					break;
				}
				else {
					nouvelle_rafle = 1;
					derniere_position = 0;
					/* si je suis sur la case de départ, j'ajoute aTester a la liste des cases a eviter */
					if ((case_courant.notation_officielle == coup_courant.old_case)
						&& (coup_courant.nombre_prises <= 1)){
						to_avoid_depart[cnt_avoid_depart++] = aTester;
					}
					case_courant = get_case_plateau_silent(aTester.x+1, aTester.y-1, p_futur);
					coup_courant.new_case = case_courant.notation_officielle;
					coup_courant.prises[coup_courant.nombre_prises - 1] = aTester;
					coup_courant.chemin[coup_courant.nombre_prises++] = case_courant;

					aTester = get_case_plateau_silent(case_courant.x-1,case_courant.y-1, p_futur);
				}
			}
			else {
				aTester = get_case_plateau_silent(case_courant.x-1,case_courant.y+1,p_futur);
				/* POSITION 3 */
				if((aTester.est_libre == 0)
						&& (aTester.pion.couleur == adversaire)
						&& (est_prenable(aTester.notation_officielle,&p_futur) == 1)
						&& ((get_case_plateau_silent(aTester.x-1, aTester.y+1, p_futur).est_libre)
								|| coup_inclus(get_case_plateau_silent(aTester.x-1, aTester.y+1, p_futur),coup_courant.chemin,coup_courant.nombre_prises))
						&& (!coup_inclus(aTester, coup_courant.prises, coup_courant.nombre_prises))
						&& (get_case_plateau_silent(aTester.x-1, aTester.y+1, p_futur).notation_officielle != 0)
						&& (aTester.notation_officielle != derniere_position)
						&& (!coup_inclus(aTester, to_avoid_parcours, cnt_avoid_parcours))) {
					if((case_courant.notation_officielle == coup_courant.old_case)
							&& (coup_courant.nombre_prises <= 1)
							&& (coup_inclus(aTester, to_avoid_depart, cnt_avoid_depart))) {
						break;
					}
					else {
						nouvelle_rafle = 1;
						derniere_position = 0;
						/* si je suis sur la case de départ, j'ajoute aTester a la liste des cases a eviter */
						if ((case_courant.notation_officielle == coup_courant.old_case)
							&& (coup_courant.nombre_prises <= 1)){
							to_avoid_depart[cnt_avoid_depart++] = aTester;
						}
						case_courant = get_case_plateau_silent(aTester.x-1, aTester.y+1, p_futur);
						coup_courant.new_case = case_courant.notation_officielle;
						coup_courant.prises[coup_courant.nombre_prises - 1] = aTester;
						coup_courant.chemin[coup_courant.nombre_prises++] = case_courant;

						aTester = get_case_plateau_silent(case_courant.x-1,case_courant.y-1, p_futur);
					}
				}
				else {
					aTester = get_case_plateau_silent(case_courant.x+1,case_courant.y+1,p_futur);
					/* POSITION 4 */
					if((aTester.est_libre == 0)
							&& (aTester.pion.couleur == adversaire)
							&& (est_prenable(aTester.notation_officielle,&p_futur) == 1)
							&& ((get_case_plateau_silent(aTester.x+1, aTester.y+1, p_futur).est_libre)
									|| coup_inclus(get_case_plateau_silent(aTester.x+1, aTester.y+1, p_futur),coup_courant.chemin,coup_courant.nombre_prises))
							&& (!coup_inclus(aTester, coup_courant.prises, coup_courant.nombre_prises))
							&& (get_case_plateau_silent(aTester.x+1, aTester.y+1, p_futur).notation_officielle != 0)
							&& (aTester.notation_officielle != derniere_position)
							&& (!coup_inclus(aTester, to_avoid_parcours, cnt_avoid_parcours))) {
						if((case_courant.notation_officielle == coup_courant.old_case)
								&& (coup_courant.nombre_prises <= 1)
								&& (coup_inclus(aTester, to_avoid_depart, cnt_avoid_depart))) {
							break;
						}
						else {
							nouvelle_rafle = 1;
							derniere_position = 0;
							/* si je suis sur la case de départ, j'ajoute aTester a la liste des cases a eviter */
							if ((case_courant.notation_officielle == coup_courant.old_case)
								&& (coup_courant.nombre_prises <= 1)){
								to_avoid_depart[cnt_avoid_depart++] = aTester;
							}
							case_courant = get_case_plateau_silent(aTester.x+1, aTester.y+1, p_futur);
							coup_courant.new_case = case_courant.notation_officielle;
							coup_courant.prises[coup_courant.nombre_prises - 1] = aTester;
							coup_courant.chemin[coup_courant.nombre_prises++] = case_courant;

							aTester = get_case_plateau_silent(case_courant.x-1,case_courant.y-1, p_futur);
						}
					}
					else {	/* j'enregistre le coup et je backtrack  si possible, sinon je retourne le tableau de coups */

						derniere_position = coup_courant.prises[coup_courant.nombre_prises - 2].notation_officielle;
						/* si on a rien au bout d'une rafle et si on est pas dans la case 0, on l'ajoute a cp */
						if(nouvelle_rafle && coup_courant.old_case != 0 && coup_courant.new_case != 0) {
							cp[cnt_coup++] = coup_courant;
							nouvelle_rafle = 0;
						}
						if(coup_courant.nombre_prises <= 1) { /* si y'a plus de prises en fait */
							fini = 1;
						}
						/* et on backtracke */

						to_avoid_parcours[cnt_avoid_parcours++] = coup_courant.prises[coup_courant.nombre_prises - 2];
						coup_courant.nombre_prises--;
						case_courant = coup_courant.chemin[coup_courant.nombre_prises - 1];
						aTester = get_case_plateau_silent(case_courant.x-1,case_courant.y-1, p_futur);
					}
				}
			}
		}
	}
	/* on ajoute aussi les deplacements possibles */
	coup *deplacements = get_deplacements(c, p);
	while((deplacements->old_case != 0) && (deplacements->new_case != 0)) {
		cp[cnt_coup++] = *deplacements;
		deplacements++;
	}
	/* pour marquer la fin de tableau */
	coup bidon;
	bidon.old_case = 0;
	bidon.new_case = 0;
	cp[cnt_coup++] = bidon;
	return cp;
}

int get_possible_case_pos(int c, int diag, plateau p) {
	int x = p.cases[c].x;
	int y = p.cases[c].y;
	switch (diag) {
	case 1:
		while (x > 0 && y > 0) {
			x--;
			y--;
			case_plateau aPrendre = get_case_plateau_silent(x, y, p);
			if (!aPrendre.est_libre) { /* si on trouve une case non libre */
				if (aPrendre.pion.couleur != p.cases[c].pion.couleur) { /* soit elle à un pion adversaire */
					return get_case_plateau_silent(x, y, p).notation_officielle;
				} else { /* soit un pion de la même couleur */
					return 0;
				}
			}
		}
		return 0;
		break;
	case 2:
		while (x <= 10 && y > 0) {
			x++;
			y--;
			case_plateau aPrendre = get_case_plateau_silent(x, y, p);
			if (!aPrendre.est_libre) { /* si on trouve une case non libre */
				if (aPrendre.pion.couleur != p.cases[c].pion.couleur) { /* soit elle à un pion adversaire */
					return get_case_plateau_silent(x, y, p).notation_officielle;
				} else { /* soit un pion de la même couleur */
					return 0;
				}
			}
		}
		return 0;
		break;
	case 3:
		while (x > 0 && y <= 10) {
			x--;
			y++;
			case_plateau aPrendre = get_case_plateau_silent(x, y, p);
			if (!aPrendre.est_libre) { /* si on trouve une case non libre */
				if (aPrendre.pion.couleur != p.cases[c].pion.couleur) { /* soit elle à un pion adversaire */
					return get_case_plateau_silent(x, y, p).notation_officielle;
				} else { /* soit un pion de la même couleur */
					return 0;
				}
			}
		}
		return 0;
		break;
	case 4:
		while (x <= 10 && y <= 10) {
			x++;
			y++;
			case_plateau aPrendre = get_case_plateau_silent(x, y, p);
			if (!aPrendre.est_libre) { /* si on trouve une case non libre */
				if (aPrendre.pion.couleur != p.cases[c].pion.couleur) { /* soit elle à un pion adversaire */
					return get_case_plateau_silent(x, y, p).notation_officielle;
				} else { /* soit un pion de la même couleur */
					return 0;
				}
			}
		}
		return 0;
		break;
	default:
		return 0;
		break;
	}
}


coup * completer_coup_dame(const coup c, int mvt, plateau p) {
	coup * res = calloc(100, sizeof(coup));
	int cpt_res = 0;
	plateau p_futur;
	if (mvt == 1 || mvt == 4) { // si on est dur la diagonale 1-4
		int diag2 = get_possible_case_pos(c.new_case, 2, p); // on cherche sur les diagonales perpendiculaires
		int diag3 = get_possible_case_pos(c.new_case, 3, p);
		if (diag2) { // si on peut prendre un pion sur la diagonale 2
			case_plateau cPrise = p.cases[diag2];
			int x = cPrise.x + 1;
			int y = cPrise.y - 1;
			while (x <= 10 && y > 0 && get_case_plateau_silent(x, y, p).est_libre) { /* dans ce cas, on parcours les cases de la diagonale derrière la prise */
				coup cp = c;
				cp.prises[cp.nombre_prises] = cPrise;
				case_plateau new_case = get_case_plateau_silent(x, y, p);
				cp.nombre_prises++;
				cp.chemin[cp.nombre_prises] = new_case;
				cp.new_case = new_case.notation_officielle;
				res[cpt_res++] = cp;

				if (get_possible_case_pos(new_case.notation_officielle, 1, p) /* si il n'y a pas d'aures prises sur la diagonale, on ajoute le coup */
				|| get_possible_case_pos(new_case.notation_officielle, 4, p)) {

					p_futur = p;
					plateau_prendre_pion(cPrise.notation_officielle, &p_futur);
					plateau_deplacer_pion(c.new_case,
							new_case.notation_officielle, &p_futur);
					coup * coups_completes =
							completer_coup_dame(cp, 2, p_futur);
					int nbCoups = nombre_coups(coups_completes);
					int i;
					for (i = 0; i < nbCoups; i++) {
						res[cpt_res++] = coups_completes[i];
					}
				}
				x++;
				y--;
			}
		}
		if (diag3) { // si on peut prendre un pion sur la diagonale 3
			case_plateau cPrise = p.cases[diag3];
			int x = cPrise.x - 1;
			int y = cPrise.y + 1;
			while (x > 0 && y <= 10 && get_case_plateau_silent(x, y, p).est_libre) { /* dans ce cas, on parcours les cases de la diagonale derrière la prise */
				coup cp = c;
				cp.prises[cp.nombre_prises] = cPrise;
				case_plateau new_case = get_case_plateau_silent(x, y, p);
				cp.nombre_prises++;
				cp.chemin[cp.nombre_prises] = new_case;
				cp.new_case = new_case.notation_officielle;
				res[cpt_res++] = cp;
				if (!(get_possible_case_pos(new_case.notation_officielle, 1, p) /* si il n'y a pas d'aures prises sur la diagonale, on ajoute le coup */
				|| get_possible_case_pos(new_case.notation_officielle, 4, p))) {

					p_futur = p;
					plateau_prendre_pion(cPrise.notation_officielle, &p_futur);
					plateau_deplacer_pion(c.new_case,
							new_case.notation_officielle, &p_futur);
					coup * coups_completes =
							completer_coup_dame(cp, 3, p_futur);
					int nbCoups = nombre_coups(coups_completes);
					int i;
					for (i = 0; i < nbCoups; i++) {
						res[cpt_res++] = coups_completes[i];
					}
				}
				x--;
				y++;
			}
		}
	} else { // sinon on est sur la diagonale 2-3
		int diag1 = get_possible_case_pos(c.new_case, 1, p); // on cherche sur les diagonales perpendiculaires
		int diag4 = get_possible_case_pos(c.new_case, 4, p);
		if (diag1) { // si on peut prendre un pion sur la diagonale 1
			case_plateau cPrise = p.cases[diag1];
			int x = cPrise.x - 1;
			int y = cPrise.y - 1;
			while (x > 0 && y > 0 && get_case_plateau_silent(x, y, p).est_libre) { /* dans ce cas, on parcours les cases de la diagonale derrière la prise */
				coup cp = c;
				cp.prises[cp.nombre_prises] = cPrise;
				case_plateau new_case = get_case_plateau_silent(x, y, p);
				cp.nombre_prises++;
				cp.chemin[cp.nombre_prises] = new_case;
				cp.new_case = new_case.notation_officielle;
				res[cpt_res++] = cp;
				if (!(get_possible_case_pos(new_case.notation_officielle, 2, p) /* si il n'y a pas d'aures prises sur la diagonale, on ajoute le coup */
				|| get_possible_case_pos(new_case.notation_officielle, 3, p))) {
					p_futur = p;
					plateau_prendre_pion(cPrise.notation_officielle, &p_futur);
					plateau_deplacer_pion(c.new_case,
							new_case.notation_officielle, &p_futur);
					coup * coups_completes =
							completer_coup_dame(cp, 1, p_futur);
					int nbCoups = nombre_coups(coups_completes);
					int i;
					for (i = 0; i < nbCoups; i++) {
						res[cpt_res++] = coups_completes[i];
					}
				}
				x--;
				y--;
			}
		}
		if (diag4) { // si on peut prendre un pion sur la diagonale 3
			case_plateau cPrise = p.cases[diag4];
			int x = cPrise.x + 1;
			int y = cPrise.y + 1;
			while (x <= 10 && y <= 10 && get_case_plateau_silent(x, y, p).est_libre) { /* dans ce cas, on parcours les cases de la diagonale derrière la prise */
				coup cp = c;
				cp.prises[cp.nombre_prises] = cPrise;
				case_plateau new_case = get_case_plateau_silent(x, y, p);
				cp.nombre_prises++;
				cp.chemin[cp.nombre_prises] = new_case;
				cp.new_case = new_case.notation_officielle;
				res[cpt_res++] = cp;
				if (!(get_possible_case_pos(new_case.notation_officielle, 2, p) /* si il n'y a pas d'aures prises sur la diagonale, on ajoute le coup */
				|| get_possible_case_pos(new_case.notation_officielle, 3, p))) {
					p_futur = p;
					plateau_prendre_pion(cPrise.notation_officielle, &p_futur);
					plateau_deplacer_pion(c.new_case,
							new_case.notation_officielle, &p_futur);
					coup * coups_completes =
							completer_coup_dame(cp, 4, p_futur);
					int nbCoups = nombre_coups(coups_completes);
					int i;
					for (i = 0; i < nbCoups; i++) {
						res[cpt_res++] = coups_completes[i];
					}
				}
				x++;
				y++;
			}
		}
	}

	coup bidon;
	bidon.old_case = 0;
	bidon.new_case = 0;
	res[cpt_res++] = bidon;

	return res;
}

/**
 * \brief Recherche les coups possibles pour une dame.
 * \author Bastien Auda
 */
coup* coupsPossiblesDames(const case_plateau c, const plateau p) {

	coup * cps = calloc(NBCOUPS, sizeof(coup));
	plateau p_futur = p;
	int cnt_coup = 0;
	case_plateau case_courant = c;
	couleur_pion adversaire = (c.pion.couleur == blanc) ? noir : blanc;
	type_coup prise = x;

	/* conditions de départ */
	coup coup_courant;
	coup_courant.old_case = case_courant.notation_officielle;
	coup_courant.nombre_prises = 0;
	coup_courant.tc = x;
	coup_courant.chemin[coup_courant.nombre_prises++] = case_courant;

	/* pour signaler qu'on est dans une rafle */
	int nouvelle_rafle = 0;
	int derniere_recherche_faite = 0; /* lorsqu'on revient sur la case de départ, on fait une derniere recherche */
	int fini = 0;
	int derniere_position = 0;

	/* quand on est sur la case de départ on marque l'element qu'on va visiter
	 * ainsi on ne reparcours pas une deuxieme fois quand on revient durant le backtrack
	 */
	case_plateau to_avoid[5];
	int cnt_avoid = 0;

	/* ---------------------------------------------------------------------------
	 * stratégie:
	 *
	 * 		       |       |
	 *         1   |       |   2				On teste d'abord les diagonales
	 * 		_______|_______|_______				dans l'ordre indiqué toujours
	 * 		       | case  |					par rapport à la case courante
	 *             |courant|
	 * 		_______|_______|_______
	 *		       |       |
	 * 		   3   |       |   4
	 *             |       |
	 *
	 *
	 *
	 * ---------------------------------------------------------------------------
	 */

	while (!fini) {
		/* ---------------------- Diagonale 1 ----------------------------- */
		int case_prise = get_possible_case_pos(c.notation_officielle, 1, p);
		case_plateau case_derriere = get_case_plateau_silent(
				p.cases[case_prise].x - 1, p.cases[case_prise].y - 1, p);
		if (!case_prise || !case_derriere.est_libre
				|| case_derriere.notation_officielle == 0) { /* si la diagonale est vide, ou qu'on ne peut pas prendre le pion */
			int x = c.x - 1;
			int y = c.y - 1;
			while (x > 0 && y > 0 && get_case_plateau_silent(x, y, p).est_libre) { /* on parcours la diagonale jusqu'au bout ou jusqu'a rencontrer un autre pion. */
				case_plateau new_case = get_case_plateau_silent(x, y, p);
				if (new_case.notation_officielle != 0) {
					coup cp;
					cp.tc = '-';
					cp.old_case = c.notation_officielle;
					cp.nombre_prises = 0;
					cp.new_case = new_case.notation_officielle;
					cps[cnt_coup++] = cp; /* on ajoute tous les coups à la liste */
				}
				x--;
				y--;
			}

		} else { /* sinon, il y a un pion à prendre sur la diagonale */
			case_plateau cPrise = p.cases[case_prise];
			int x = cPrise.x - 1;
			int y = cPrise.y - 1;
			while (x > 0 && y > 0 && get_case_plateau_silent(x, y, p).est_libre) { /* dans ce cas, on parcours les cases de la diagonale derrière la prise */
				coup cp;
				cp.tc = prise;
				cp.old_case = c.notation_officielle;
				cp.nombre_prises = 1;
				cp.prises[0] = cPrise;
				case_plateau new_case = get_case_plateau_silent(x, y, p);
				cp.chemin[0] = c;
				cp.chemin[1] = new_case;
				cp.new_case = new_case.notation_officielle;

				p_futur = p;
				plateau_prendre_pion(cPrise.notation_officielle, &p_futur);
				plateau_deplacer_pion(c.notation_officielle,
						new_case.notation_officielle, &p_futur);

				cps[cnt_coup++] = cp;

				if (get_possible_case_pos(new_case.notation_officielle, 2,
						p_futur) || get_possible_case_pos(
						new_case.notation_officielle, 3, p_futur)) { /* si il y a une prise possible sur la diagonale, on l'ajoute à la liste */
					coup * coups_completes =
							completer_coup_dame(cp, 1, p_futur);

					int nbCoups = nombre_coups(coups_completes);
					int i;
					for (i = 0; i < nbCoups; i++) {
						cps[cnt_coup++] = coups_completes[i];
					}
					free(coups_completes);
				}
				x--;
				y--;
			}
		}

		/* ---------------------- Diagonale 2 ----------------------------- */

		case_prise = get_possible_case_pos(c.notation_officielle, 2, p);
		case_derriere = get_case_plateau_silent(p.cases[case_prise].x + 1,
				p.cases[case_prise].y - 1, p);
		if (!case_prise || !case_derriere.est_libre
				|| case_derriere.notation_officielle == 0) { /* si la diagonale est vide */
			int x = c.x + 1;
			int y = c.y - 1;
			while (x <= 10 && y > 0 && get_case_plateau_silent(x, y, p).est_libre) { /* on parcours la diagonale jusqu'au bout ou jusqu'a rencontrer un autre pion. */
				case_plateau new_case = get_case_plateau_silent(x, y, p);
				if (new_case.notation_officielle != 0) {
					coup cp;
					cp.tc = '-';
					cp.old_case = c.notation_officielle;
					cp.nombre_prises = 0;
					cp.new_case = new_case.notation_officielle;
					cps[cnt_coup++] = cp; /* on ajoute tous les coups à la liste */
				}
				x++;
				y--;
			}

		} else { /* sinon, il y a un pion à prendre sur la diagonale */
			case_plateau cPrise = p.cases[case_prise];
			int x = cPrise.x + 1;
			int y = cPrise.y - 1;
			while (x <= 10 && y > 0 && get_case_plateau_silent(x, y, p).est_libre) { /* dans ce cas, on parcours les cases de la diagonale derrière la prise */
				coup cp;
				cp.tc = prise;
				cp.old_case = c.notation_officielle;
				cp.nombre_prises = 1;
				cp.prises[0] = cPrise;
				case_plateau new_case = get_case_plateau_silent(x, y, p);
				cp.chemin[0] = c;
				cp.chemin[1] = new_case;
				cp.new_case = new_case.notation_officielle;

				p_futur = p;
				plateau_prendre_pion(cPrise.notation_officielle, &p_futur);
				plateau_deplacer_pion(c.notation_officielle,
						new_case.notation_officielle, &p_futur);
				cps[cnt_coup++] = cp;

				if (get_possible_case_pos(new_case.notation_officielle, 1,
						p_futur) || get_possible_case_pos(
						new_case.notation_officielle, 4, p_futur)) {

					coup * coups_completes =
							completer_coup_dame(cp, 2, p_futur);

					int nbCoups = nombre_coups(coups_completes);
					int i;
					for (i = 0; i < nbCoups; i++) {
						cps[cnt_coup++] = coups_completes[i];
					}
					free(coups_completes);
				}
				x++;
				y--;
			}
		}

		/* ---------------------- Diagonale 3 ----------------------------- */

		case_prise = get_possible_case_pos(c.notation_officielle, 3, p);
		case_derriere = get_case_plateau_silent(p.cases[case_prise].x - 1,
				p.cases[case_prise].y + 1, p);
		if (!case_prise || !case_derriere.est_libre
				|| case_derriere.notation_officielle == 0) { /* si la diagonale est vide */
			int x = c.x - 1;
			int y = c.y + 1;
			while (x > 0 && y <= 10 && get_case_plateau_silent(x, y, p).est_libre) { /* on parcours la diagonale jusqu'au bout ou jusqu'a rencontrer un autre pion. */
				case_plateau new_case = get_case_plateau_silent(x, y, p);
				if (new_case.notation_officielle != 0) {
					coup cp;
					cp.tc = '-';
					cp.old_case = c.notation_officielle;
					cp.nombre_prises = 0;
					cp.new_case = new_case.notation_officielle;
					cps[cnt_coup++] = cp; /* on ajoute tous les coups à la liste */
				}
				x--;
				y++;
			}

		} else { /* sinon, il y a un pion à prendre sur la diagonale */
			case_plateau cPrise = p.cases[case_prise];
			int x = cPrise.x - 1;
			int y = cPrise.y + 1;
			while (x > 0 && y <= 10 && get_case_plateau_silent(x, y, p).est_libre) { /* dans ce cas, on parcours les cases de la diagonale derrière la prise */
				coup cp;
				cp.tc = prise;
				cp.old_case = c.notation_officielle;
				cp.nombre_prises = 1;
				cp.prises[0] = cPrise;
				case_plateau new_case = get_case_plateau_silent(x, y, p);
				cp.chemin[0] = c;
				cp.chemin[1] = new_case;
				cp.new_case = new_case.notation_officielle;

				p_futur = p;
				plateau_prendre_pion(cPrise.notation_officielle, &p_futur);
				plateau_deplacer_pion(c.notation_officielle,
						new_case.notation_officielle, &p_futur);
				cps[cnt_coup++] = cp;

				if (get_possible_case_pos(new_case.notation_officielle, 1,
						p_futur) || get_possible_case_pos(
						new_case.notation_officielle, 4, p_futur)) {
					coup * coups_completes =
							completer_coup_dame(cp, 3, p_futur);

					int nbCoups = nombre_coups(coups_completes);
					int i;
					for (i = 0; i < nbCoups; i++) {
						cps[cnt_coup++] = coups_completes[i];
					}
					free(coups_completes);
				}
				x--;
				y++;
			}
		}

		/* ---------------------- Diagonale 4 ----------------------------- */

		case_prise = get_possible_case_pos(c.notation_officielle, 4, p);
		case_derriere = get_case_plateau_silent(p.cases[case_prise].x + 1,
				p.cases[case_prise].y + 1, p);
		if (!case_prise || !case_derriere.est_libre
				|| case_derriere.notation_officielle == 0) { /* si la diagonale est vide */
			int x = c.x + 1;
			int y = c.y + 1;
			while (x <= 10 && y <= 10 && get_case_plateau_silent(x, y, p).est_libre) { /* on parcours la diagonale jusqu'au bout ou jusqu'a rencontrer un autre pion. */
				case_plateau new_case = get_case_plateau_silent(x, y, p);
				if (new_case.notation_officielle != 0) {
					coup cp;
					cp.tc = '-';
					cp.old_case = c.notation_officielle;
					cp.nombre_prises = 0;
					cp.new_case = new_case.notation_officielle;
					cps[cnt_coup++] = cp; /* on ajoute tous les coups à la liste */
				}
				x++;
				y++;
			}

		} else { /* sinon, il y a un pion à prendre sur la diagonale */
			case_plateau cPrise = p.cases[case_prise];
			int x = cPrise.x + 1;
			int y = cPrise.y + 1;
			while (x <= 10 && y <= 10 && get_case_plateau_silent(x, y, p).est_libre) { /* dans ce cas, on parcours les cases de la diagonale derrière la prise */
				coup cp;
				cp.tc = prise;
				cp.old_case = c.notation_officielle;
				cp.nombre_prises = 1;
				cp.prises[0] = cPrise;
				case_plateau new_case = get_case_plateau_silent(x, y, p);
				cp.chemin[0] = c;
				cp.chemin[1] = new_case;
				cp.new_case = new_case.notation_officielle;

				p_futur = p;
				plateau_prendre_pion(cPrise.notation_officielle, &p_futur);
				plateau_deplacer_pion(c.notation_officielle,
						new_case.notation_officielle, &p_futur);
				cps[cnt_coup++] = cp;

				if (get_possible_case_pos(new_case.notation_officielle, 2,
						p_futur) || get_possible_case_pos(
						new_case.notation_officielle, 3, p_futur)) { /* si il y a d'aures prises sur la diagonale */
					coup * coups_completes =
							completer_coup_dame(cp, 4, p_futur);

					int nbCoups = nombre_coups(coups_completes);
					int i;
					for (i = 0; i < nbCoups; i++) {
						cps[cnt_coup++] = coups_completes[i];
					}
					free(coups_completes);
				}
				x++;
				y++;
			}
		}

		fini = 1;
	}

	//free(deplacements);

	/* pour marquer la fin de tableau */
	coup bidon;
	bidon.old_case = 0;
	bidon.new_case = 0;
	cps[cnt_coup++] = bidon;
	return cps;
}

/* retourne les coups possibles de tout les pions */
coup* getCoups(const joueur j, const plateau p) {

	//coup cp[500];
	coup *cp = calloc(500, sizeof(coup));

	case_plateau c;
	int cnt_coup = 0;
	int i;
	int k = 0;
	/* j'itere sur toutes les cases du plateau */
	for (i = 1; i < 51; i++) {
		c = p.cases[i];
		/* si dans cette case y'a un pion du joueur j
		 * on recupere tout les coups possibles de ce pion
		 */
		if ((!c.est_libre) && (c.pion.couleur == j.couleur)) {
			coup * aAjouter;
			if (c.pion.est_dame) {
				aAjouter = coupsPossiblesDames(c, p);
			} else {
				aAjouter = coupsPossibles(c, p);
			}
			/* recopie les coups possibles de ce pion dans cp */
			while ((aAjouter[k].old_case != 0) && (aAjouter[k].new_case != 0)) {
				cp[cnt_coup++] = aAjouter[k++];
			}
			k = 0;
		}
	}
	/* pour marquer la fin de tableau */
	coup bidon;
	bidon.old_case = 0;
	bidon.new_case = 0;
	cp[cnt_coup++] = bidon;

	coup *result = calloc(cnt_coup, sizeof(coup));
	memcpy(&result, &cp, sizeof result);

	return result;
}

/* retourne les coups max du tableau en entrée */
coup* getCoupsMax(const coup *cp) {

	int i = 0;
	//coup coups_max[NBCOUPS];
	coup *coups_max = calloc(NBCOUPS, sizeof(coup));
	int cnt_coups_max = 0;
	int nb_prises_max = 0;

	/* je parcours une premiere fois cp pour trouver le nb de prises max rencontré */
	while ((cp[i].old_case != 0) && (cp[i].new_case != 0)) {
		if (cp[i].nombre_prises > nb_prises_max) {
			nb_prises_max = cp[i].nombre_prises;
		}
		i++;
	}

	/* je reparcours cp, cette fois je ne prend que les coups qui ont un
	 * nb de prises égal au nb_prises_max
	 */
	i = 0;
	while ((cp[i].old_case != 0) && (cp[i].new_case != 0)) {
		if (cp[i].nombre_prises == nb_prises_max) {
			coups_max[cnt_coups_max++] = cp[i];
		}
		i++;
	}

	/* je marque la fin de tableau */
	coup bidon;
	bidon.old_case = 0;
	bidon.new_case = 0;
	coups_max[cnt_coups_max++] = bidon;

	coup *result = calloc(cnt_coups_max, sizeof(coup));
	memcpy(&result, &coups_max, sizeof(result));

	return result;
}

/* retourne les déplacements possible du pion sur la case c */
coup* get_deplacements(const case_plateau c, const plateau p) {
	coup *moves = calloc(3, sizeof(coup));
	coup *d = moves;
	plateau futur = p;
	if (c.pion.couleur == blanc) {
		case_plateau c1 = get_case_plateau_silent(c.x - 1, c.y - 1, futur);
		if ((c1.notation_officielle != 0) && c1.est_libre) {
			coup nouveauCoup;
			nouveauCoup.old_case = c.notation_officielle;
			nouveauCoup.new_case = c1.notation_officielle;
			nouveauCoup.tc = '-';
			*(d++) = nouveauCoup;
		}
		case_plateau c2 = get_case_plateau_silent(c.x + 1, c.y - 1, futur);
		if ((c2.notation_officielle != 0) && c2.est_libre) {
			coup nouveauCoup;
			nouveauCoup.old_case = c.notation_officielle;
			nouveauCoup.new_case = c2.notation_officielle;
			nouveauCoup.tc = '-';
			*(d++) = nouveauCoup;
		}
	} else {
		case_plateau c1 = get_case_plateau_silent(c.x - 1, c.y + 1, futur);
		if ((c1.notation_officielle != 0) && c1.est_libre) {
			coup nouveauCoup;
			nouveauCoup.old_case = c.notation_officielle;
			nouveauCoup.new_case = c1.notation_officielle;
			nouveauCoup.tc = '-';
			*(d++) = nouveauCoup;
		}
		case_plateau c2 = get_case_plateau_silent(c.x + 1, c.y + 1, futur);
		if ((c2.notation_officielle != 0) && c2.est_libre) {
			coup nouveauCoup;
			nouveauCoup.old_case = c.notation_officielle;
			nouveauCoup.new_case = c2.notation_officielle;
			nouveauCoup.tc = '-';
			printf("\n");
			*(d++) = nouveauCoup;
		}
	}

	/* je marque la fin du tableau */
	coup bidon;
	bidon.old_case = 0;
	bidon.new_case = 0;
	*(d++) = bidon;

	return moves;
}




/* retourne 0 si liste1 = liste2, sinon 1 */
int compare_coups(coup *liste1, coup *liste2) {
	coup *p1 = liste1;
	coup *p2 = liste2;

	while(p1->old_case != 0) {
		if((p1->old_case != p2->old_case)
				|| (p1->new_case != p2->new_case)
				|| (p1->nombre_prises != p2->nombre_prises)
				|| (p1->tc != p2->tc))
			return 1;
		p1++;
		p2++;
	}
	return 0;
}

case_plateau get_case_plateau_silent(int x, int y, plateau p) {
	if (x < 1 || x > 10 || y < 1 || y > 10) {
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
