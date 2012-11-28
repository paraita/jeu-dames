/**
 * 	\file plateau.h
 * 	\brief Tout ce qui concerne le plateau de jeu (damier, pions et joueurs).
 *	\author Bastien Auda
 */


/**
 * 	\enum couleur_pion
 * 	\brief La couleur d'un pion.
 */
typedef enum {
	blanc,
	noir
} couleur_pion;

/**
 * 	\enum type_coup
 * 	\brief Le type de coup.
 * 	Le "tiret" '-' est remplacé par un 't'.
 */
typedef enum {
	x, /*!< Prise. */
	t /*!< Déplacement. */
} type_coup;


/**
 * 	\struct pion
 * 	\brief Objet pion.
 * 	Un pion est déterminé par une couleur et si il est une dame ou non.
 */
typedef struct {
	couleur_pion couleur;
	int est_dame;		/*!< Détermine si on a un pion normal ou une dame. */
	int en_surbrillance; /*!< Si le pion doit être affichée en surbrillance. */
} pion;

/**
 * 	\struct case_plateau
 * 	\brief Objet case du plateau de jeu.
 * 	Une case est définie par une couleur et, si elle est noire,elle dispose d'une abscisse (x) et une ordonnée (y) sur le plateau.
 * 	Une case peut être libre ou non, si elle n'est pas libre elle contient un pion.
 */
typedef struct {
	couleur_pion couleur; /*!< La couleur de la case. */
	int est_libre;	/*!< Vrai si la case est vide */
	pion pion;
	int x;
	int y;
	int notation_officielle; /*!< Le numéro de la case selon la notation officielle. */
	int en_surbrillance; /*!< Si la case doit être affichée en surbrillance. */
} case_plateau;



/**
 * 	\struct joueur
 * 	\brief Objet joueur.
 * 	Un joueur est caractérisé par la couleur qu'il joue et sa nature (humain ou intelligence artificielle).
 */
typedef struct {
	int est_humain; 	/*!< Détermine si le joueur est une IA ou un joueur réel. */
	couleur_pion couleur; 	/*!< La couleur avec laquelle joue ce joueur. */
} joueur;



/**
 * 	\struct coup
 * 	\brief Objet coup.
 *	Un coup est défini par un numéro de case de départ, un numéro de case d'arrivée, un type (déplacement ou prise) et optinellement un commentaire
 */
typedef struct {
	int old_case;
	int new_case;
	type_coup tc; /*!< Si le coup est un déplacement ou une prise. */
	int nombre_prises;
	case_plateau prises[20]; /*!< Les cases sur lesquelles les jetons ont été pris. */
	case_plateau chemin[20]; /*!< Liste de cases sur lesquelles le pion s'arrête lors d'une rafle (pour repérer la fin de liste, la dernière case sera une case blanche). */
	char * commentaire;
	/*!< Les commentaires sont :\n
	  	\li ! pour indiquer un coup fort ou bien joué\n
		\li !! pour indiquer un coup très fort\n
		\li ? pour indiquer un coup faible ou mal joué\n
		\li	?? pour indiquer un coup très faible ou une gaffe\n
		\li	!? pour indiquer un coup paraissant fort, mais qui en réalité se révèle faible\n
		\li	?! pour indiquer un coup paraissant faible, mais qui en réalité se révèle fort\n
		\li	* pour indiquer un coup forcé, tout autre mouvement entraînant une perte immédiate\n
		\li	+ pour indiquer le gain de la partie\n
		\li	= pour indiquer un jeu égal\n
		\li	+1 pour indiquer le gain d’un pion\n
		\li	+n pour indiquer le gain de n pion\n
		\li	+- pour indiquer un avantage aux blancs\n
		\li	-+ pour indiquer un avantage aux noirs
	 */
} coup;


/**
 * 	\struct plateau
 * 	\brief Objet plateau.
 *	Le plateau est composé de 50 cases, numérotées de 1 à 50.
 *	Il comporte un historique des coups.
 *	Il sait quel joueur doit jouer le prochain coup.
 */
typedef struct {
	case_plateau cases[51];	/*!< Un plateau est composé de 50 cases, numérotées de 01 à 50. (la case 0 stocke la case blanche). */
	coup historique[500];	/*!< On peut enregistrer jusqu'à 500 coups. */
	int i; /*!< Non utilisé : l'indice du prochain coup à entrer. */
	joueur joueur1;
	joueur joueur2;
	joueur tour; /*!< Le joueur qui doit jouer le prochain coup. */
} plateau;

/* ********* Fin des définitions de types, début des définitions de fonctions *************************/

/**
 * \fn plateau nouveau_plateau(joueur j1, joueur j2)
 * \brief Fonction de création d'un nouveau plateau.
 *
 * \param j1 Le joueur blanc.
 * \param j2 Le joueur noir.
 * \return plateau Un plateau initialisé avec les pions en position initiale et associé aux joueurs.
 */
plateau nouveau_plateau(joueur j1, joueur j2);


/**
 * \fn int plateau_deplacer_pion(int old_position,int new_position,plateau *p)
 * \brief Déplace un pion.
 *
 * \param old_position La position de départ.
 * \param new_position La position d'arrivée.
 * \return int Vrai si le déplacement est possible, faux si un pion occupe déjà la case ou si on sort du plateau.
 */
int plateau_deplacer_pion(int old_position,int new_position,plateau *p);

/**
 * \fn int plateau_prendre_pion(int position,plateau *p)
 * \brief Prend le pion de la case "position".
 *
 * \param position Position de la case sur laquelle se trouve le pion.
 * \return int Vrai si la prise est effectuée, faux si la case est vide ou si on sort du plateau.
 */
int plateau_prendre_pion(int position,plateau *p);

/**
 * \fn void plateau_ajouter_coup(coup c,plateau *p)
 * \brief Ajoute un coup dans l'historique du plateau.
 *
 * \param c Le coup à ajouter.
 * \param p Le plateau auquel on ajoute le coup.
 * En raison du risque improbable qu'une partie dure plus de 500 coups, l'historique au-delà est ignoré.
 */
void plateau_ajouter_coup(coup c,plateau *p);

/**
 *	\fn void plateau_appliquer_coup(coup c, plateau * p);
 *	\brief Met à jour le plateau en jouant le coup donné et passe la main au joueur suivant.
 *	\param c Le coup à jouer.
 */
void plateau_appliquer_coup(coup c, plateau * p);

/**
 * 	\fn int plateau_partie_finie(plateau p);
 * 	\brief Teste si la partie est gagnée pour un des deux joueurs.
 * 	\return 0 si la partie n'est pas finie, couleur + 1 sinon.
 */
int plateau_partie_finie(plateau p);

/**
 * \fn case_plateau get_case_plateau(int x, int y,plateau p);
 * \brief Renvoie la case à la position (x,y).
 *
 * \param x Abscisse de la case (colonne) [1-10].
 * \param y Ordonnée de la case [1-10].
 */
case_plateau get_case_plateau(int x, int y,plateau p);

/**
 * \fn void print_case(case_plateau c);
 * \brief Affiche les informations sur la case (à des fins de test).
 *
 * \param c La case à afficher.
 */
void print_case(case_plateau c);

/**
 * 	\fn void print_plateau(plateau p);
 * 	\brief Affiche le plateau sur stdout.
 */
void print_plateau(plateau p);

/**
 * \fn void set_case_en_surbrillance(int numero,plateau *p);
 * \brief Met la case en surbrillance.
 *
 * \param numero Numéro de la case à mettre en surbrillance (selon la notation officielle).
 */
void set_case_en_surbrillance(int numero,plateau *p);

/**
 * \fn void set_pion_en_surbrillance(int numero,plateau *p);
 * \brief Met un pion en surbrillance.
 *
 * \param numero Numéro de la case sur laquelle se trouve le pion à mettre en surbrillance (selon la notation officielle).
 */
void set_pion_en_surbrillance(int numero,plateau *p);

/**
 * \fn void reset_surbrillance(plateau *p);
 * \brief Annule la mise en surbrillance de toutes les cases et tous les pions du plateau.
 */
void reset_surbrillance(plateau *p);


/**
 * \fn void printCoup(const coup c)
 * \brief print les infos d'un coup
 *
 * \param c le coup dont on veut les informations.
 * \author Paraita Wohler
 */
void printCoup(const coup c);

/**
 * \fn int est_prenable(int position, plateau *p)
 * \brief predicat pour savoir si une position est prenable.
 *
 * \param position la position du pion que l'on veut prendre.
 * \param p le plateau sur lequel on veut tester la position à prendre.
 */
int est_prenable(int position, plateau *p);


/**
 * \fn void print_liste_coups(coup *l)
 * \brief affiche la liste des coups dans l.
 *
 * \param l la liste des coups que l'on veut afficher.
 * \author Paraita Wohler
 */
void print_liste_coups(coup *l);


/**
 * \fn int coup_inclus(case_plateau c, coup *liste)
 * \brief prédicat: est ce que la case c est incluse dans liste ?
 *
 * \param c la case a tester.
 * \param liste l'ensemble d'inclusion.
 * \author Paraita Wohler
 */
int coup_inclus(case_plateau c, case_plateau *liste, int taille);

/**
 * \fn case_plateau get_case_plateau_silent(int x, int y, plateau p)
 * \brief retourne la case si elle existe, ou la case 0 sinon
 *
 * \param x la position horizontale sur le plateau
 * \param y la position verticale sur le plateau
 * \param p le plateau courant
 * \author Paraita Wohler
 */
case_plateau get_case_plateau_silent(int x, int y, plateau p);

/**
 * \fn int nombre_coups(coup *set)
 * \brief retourne le nombre de coups dans set
 *
 * \param set le tableau des coups.
 * \author Paraita Wohler
 */
int nombre_coups(coup *set);
