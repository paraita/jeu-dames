#include <stdio.h>

#include "../trunk/constantes.h"
#include "../trunk/moteur.h"



int main(int argc, char *argv[]) {

	joueur j1;
	j1.est_humain = 1;
	joueur j2;
	j2.est_humain = 0;

	plateau p = nouveau_plateau(j1,j2);

	plateau new_p = p;

	set_case_en_surbrillance(1,&new_p);

	print_case(get_case_plateau(2,1,p));

	print_plateau(p);

	return 0;
}
