#include "fonction_evaluation.h"

double fct_eval(const plateau *p){

	int i;
	int val;
	double total = 0;
	double denominateur = 1; //on divisera le tout par le total des valeurs des cases pour retomber entre -1 et 1.
	
	for(i = 1; i < 51 ; i++){ //Pour chaque case
		if(!p->cases[i].est_libre){ //si elle est occupee
			val = valeur_case(p, &(p->cases[i])); //on calcule sa valeur
			denominateur += val;
			if(p->cases[i].pion.couleur == p->tour.couleur){ //on ajoute ou soustrait la valeur selon le joueur auquel appartient le pion.
				total += val;
			}else{
				total -= val;
			}
		}
	}
	
	return total / denominateur;
}

int valeur_case(const plateau * p, const case_plateau * c){
	if(c->pion.est_dame) return 300; //une dame vaut basiquement trois fois un pion.
	int r = rang(c);
	if(est_isole(p,c,r)) return 75 + r*r; //un pion isole vaut 75 de base, plus un bonus selon son rang.
	return 100 + r*r; //un pion non isole vaut 100 de base, plus un bonus selon son rang.
}

int rang(const case_plateau * c){
	int res = (c->notation_officielle - 1) / 5; //on retrouve la ligne sur laquelle se trouve le pion.
	if(c->pion.couleur == noir) return res; //apres, son rang depend de sa couleur.
	return 8 - res;
}

int est_isole(const plateau * p, const case_plateau * c, int rang){
	int n = c->notation_officielle;
	if(rang == 0 || n % 10 == 5 || n % 10 == 6) return 0; //si le pion est sur un bord, il n'est pas considere comme isole.
	int s; //signe
	if((rang % 2 == 1 && c->pion.couleur == blanc) || (rang % 2 == 0 && c->pion.couleur == noir)){
		s = -1;
	}else{
		s = 1;
	}
	if((p->cases[n + s * 5].est_libre || p->cases[n + s * 5].couleur != c->pion.couleur)
	&& (p->cases[n + s * 4].est_libre || p->cases[n + s * 4].couleur != c->pion.couleur)
	&& (p->cases[n - s * 5].est_libre || p->cases[n - s * 5].couleur != c->pion.couleur)
	&& (p->cases[n - s * 6].est_libre || p->cases[n - s * 6].couleur != c->pion.couleur)){ //si les quatres cases adjacentes sont toutes libres ou occupees par un pion adverse, le pion est considere comme isole.
		return 1;
	}
	return 0;
}