#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "creatures.h"



int main() {
#define TAILLE_MAX_CREATURES 5
    int profondeur = 0;
    CreatureMarine new_tab[TAILLE_MAX_CREATURES];


    srand(time(NULL));

    init_nouveau_tableau(new_tab, TAILLE_MAX_CREATURES);

	printf("Quelle doit etre la profondeur actuelle ? ");
	scanf("%d", &profondeur);


    creation_du_typeetaffectation(new_tab, TAILLE_MAX_CREATURES, profondeur);

    return 0;
}