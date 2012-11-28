/**
 * \file arbre.h
 *
 *  \brief Implémantation des arbres
 *  \author Bastien Auda
 */


/**
 * 	\struct arbre
 * 	\brief Un arbre à une valeur (la racine) et un certain nombre de fils.
 */
typedef struct arbre {
	struct arbre * parent;
	int valeur;
	int profondeur;
	int nb_fils; /*!< Le nombre de fils de ce noeud */
	struct arbre *fils[80]; /*!< Un noeud n'aura jamais plus de 80 fils car on a, pour un demi-coup, 20 pions * 4 déplacements possibles = 80 coups différents. */
} arbre;


/**
 * \fn int arbre_est_feuille(arbre t);
 * \brief Renvoie vrai si l'arbre est une feuille.
 */
int arbre_est_feuille(arbre t);

/**
 * \fn void print_arbre(arbre t);
 * \brief Affiche l'arbre en parcours préfixe "à la Scheme", c.à.d. de la forme (racine fils1 fils2 ...).
 */
void print_arbre(arbre t);
